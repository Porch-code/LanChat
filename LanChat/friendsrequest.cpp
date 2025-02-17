#include "friendsrequest.h"
#include "login.h"

// 静态成员初始化
FriendRequestWidget* FriendRequestWidget::instance = nullptr;

// 获取唯一实例
FriendRequestWidget* FriendRequestWidget::getInstance(QWidget *parent)
{
    if (instance == nullptr)
    {
        instance = new FriendRequestWidget(parent);
    }
    return instance;
}


FriendRequestWidget::FriendRequestWidget(QWidget *parent)
    : QDialog(parent),
    networkManager(new QNetworkAccessManager(this)),
    model(new QStandardItemModel(this))
{
    // 设置界面布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 初始化列表视图
    friendRequestListView = new QListView(this);
    friendRequestListView->setModel(model);
    layout->addWidget(friendRequestListView);

    // 初始化按钮
    acceptButton = new QPushButton("Accept", this);
    rejectButton = new QPushButton("Reject", this);
    layout->addWidget(acceptButton);
    layout->addWidget(rejectButton);

    // 连接按钮的点击事件
    connect(acceptButton, &QPushButton::clicked, this, &FriendRequestWidget::onAcceptClicked);
    connect(rejectButton, &QPushButton::clicked, this, &FriendRequestWidget::onRejectClicked);

    // 获取好友请求列表
    setupFriendRequestList();
}

FriendRequestWidget::~FriendRequestWidget()
{

}

void FriendRequestWidget::setupFriendRequestList()
{
    // 构造网络请求
    QString username = Login::currentUsername;  // 使用一个示例用户名，你可以根据实际情况获取用户名
    QUrl url(QString("http://example.com/api/friend_requests?username=%1").arg(username));
    QNetworkRequest request(url);

    // 发送请求
    QNetworkReply *reply = networkManager->get(request);

    // 连接请求的信号与槽
    connect(reply, &QNetworkReply::finished, this, &FriendRequestWidget::onFriendRequestReply);
}

void FriendRequestWidget::onFriendRequestReply()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());

    if (!reply)
    {
        return;
    }

    // 检查是否发生错误
    if (reply->error() != QNetworkReply::NoError)
    {
        QMessageBox::warning(this, "Network Error", "Failed to fetch friend requests.");
        reply->deleteLater();
        return;
    }

    // 获取返回的数据并解析
    QByteArray responseData = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

    if (!jsonDoc.isObject())
    {
        qDebug() << "Invalid JSON format.";
        reply->deleteLater();
        return;
    }

    QJsonObject jsonObject = jsonDoc.object();
    QJsonArray friendRequests = jsonObject["requests"].toArray();

    // 更新列表视图
    model->clear();
    for (const QJsonValue &value : friendRequests)
    {
        QJsonObject requestObject = value.toObject();
        QString sender = requestObject["sender"].toString();
        QString message = requestObject["message"].toString();

        QStandardItem *item = new QStandardItem(QString("%1: %2").arg(sender, message));
        model->appendRow(item);
    }

    reply->deleteLater();
}

void FriendRequestWidget::onAcceptClicked()
{
    QModelIndex selectedIndex = friendRequestListView->currentIndex();
    if (!selectedIndex.isValid())
    {
        QMessageBox::warning(this, "No Selection", "Please select a friend request to accept.");
        return;
    }

    QString requestInfo = model->itemFromIndex(selectedIndex)->text();
    QString sender = requestInfo.split(":").first();

    // 发送同意请求的网络请求
    QUrl url(QString("http://example.com/api/accept_friend_request?sender=%1").arg(sender));
    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, &FriendRequestWidget::onFriendRequestActionReply);
}

void FriendRequestWidget::onRejectClicked()
{
    QModelIndex selectedIndex = friendRequestListView->currentIndex();
    if (!selectedIndex.isValid())
    {
        QMessageBox::warning(this, "No Selection", "Please select a friend request to reject.");
        return;
    }

    QString requestInfo = model->itemFromIndex(selectedIndex)->text();
    QString sender = requestInfo.split(":").first();

    // 发送拒绝请求的网络请求
    QUrl url(QString("http://example.com/api/reject_friend_request?sender=%1").arg(sender));
    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, &FriendRequestWidget::onFriendRequestActionReply);
}

void FriendRequestWidget::onFriendRequestActionReply()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (!reply)
    {
        return;
    }

    if (reply->error() != QNetworkReply::NoError)
    {
        QMessageBox::warning(this, "Network Error", "Failed to process friend request.");
    }
    else
    {
        QMessageBox::information(this, "Success", "Friend request processed successfully.");
    }

    reply->deleteLater();
}

#include "friendsdetails.h"
#include "friendsitemdelegate.h"

// 静态成员初始化
FriendDetailsWidget* FriendDetailsWidget::instance = nullptr;

// 获取唯一实例
FriendDetailsWidget* FriendDetailsWidget::getInstance(const QString &friendName, QWidget *parent)
{
    if (instance == nullptr)
    {
        instance = new FriendDetailsWidget(friendName, parent);
    }
    return instance;
}

FriendDetailsWidget::FriendDetailsWidget(const QString &friendName, QWidget *parent)
    : QDialog(parent), model(new QStandardItemModel(this)), networkManager(new QNetworkAccessManager(this))
{
    // 初始化控件
    friendDetailListView = new QListView(this);
    friendDetailListView->setModel(model);
    friendDetailListView->setItemDelegate(new FriendsItemDelegate(this));   // 使用自定义的 ItemDelegate
    friendDetailListView->setGeometry(100, 100, 400, 300);                  // 设置位置和大小
    friendDetailListView->show();

    // 启动网络请求
    setupFriendDetailList(friendName);

    // 连接网络请求的信号和槽
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &FriendDetailsWidget::onFriendDetailsReply);
}

FriendDetailsWidget::~FriendDetailsWidget()
{
}

void FriendDetailsWidget::setupFriendDetailList(const QString &friendName)
{
    QString username = friendName;  // 获取当前登录的用户名
    if (username.isEmpty())
    {
        qDebug() << "Username is empty.";
        return;
    }

    qInfo() << "Released" << username;

    // 创建一个 QNetworkAccessManager 对象来发起网络请求
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();

    // 构造请求的 URL，假设我们通过 GET 请求来获取用户数据
    QUrl url(QString("http://localhost/api/getSearchUserData?username=%1").arg(username));
    qDebug() << "Request URL: " << url.toString();  // 打印请求的 URL

    // 创建一个网络请求
    QNetworkRequest request(url);

    // 发送 GET 请求
    QNetworkReply* reply = networkManager->get(request);

    // 连接请求完成的信号到处理槽函数
    connect(reply, &QNetworkReply::finished, this, &FriendDetailsWidget::onFriendDetailsReply);

}

void FriendDetailsWidget::onFriendDetailsReply()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Request failed:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    // 获取服务器响应的内容
    QByteArray responseData = reply->readAll();
    // qDebug() << "Response Data: " << responseData;  // 打印响应数据

    // 解析 JSON 数据
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    if (!jsonDoc.isObject())
    {
        qDebug() << "Invalid JSON format.";
        reply->deleteLater();
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    // 从 JSON 中获取用户数据
    QString uname = jsonObj["data"].toObject()["uname"].toString();
    QString region = jsonObj["data"].toObject()["user_region"].toString();

    // 从封装的 JSON 数据中获取头像字段
    QString avatarBase64 = jsonObj["data"].toObject()["avatar"].toString();  // 获取头像的 Base64 编码字符串

    if (avatarBase64.isEmpty())
    {
        qDebug() << "Avatar Base64 is empty.";
    }
    else
    {
        QByteArray avatarData = QByteArray::fromBase64(avatarBase64.toUtf8());
        if (avatarData.isEmpty())
        {
            qDebug() << "Failed to decode Base64 string.";
        }
        else
        {
            qDebug() << "Decoded Avatar Data size:" << avatarData.size();
        }
    }

    // 解码头像数据
    QByteArray avatarData = QByteArray::fromBase64(avatarBase64.toUtf8());  // 解码为二进制数据



    // 更新模型显示数据
    QStandardItem *item = new QStandardItem();
    item->setData(uname, Qt::DisplayRole);             // 设置名字
    item->setData(region, Qt::DisplayRole);            // 设置地区
    item->setData(avatarData, Qt::DecorationRole);     // 设置头像
    model->appendRow(item);

    // 清理
    reply->deleteLater();
}

#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "chatmessagedelegate.h"
#include "messageitemdelegate.h"
#include "friendsitemdelegate.h"
#include "friendsrequestitemdelegate.h"
#include "userprofile.h"
#include "addfriend.h"
#include "addverification.h"
#include "login.h"

QString MainWidget::searchUsername = "";
QString MainWidget::applyUsername = "";
QString MainWidget::currentChatSessionId = "";

MainWidget::MainWidget(QWidget *parent)
    : QLabel(parent)
    , ui(new Ui::MainWidget)
    , m_manager(new QNetworkAccessManager(this))    // 初始化QNetworkAccessManager
    , tcpSocket(new QTcpSocket(this))               // 初始化QTcpSocket
    , chatModel(new NonClickableChatModel(this))    // 初始化数据模型
    , friendListModel(new QStandardItemModel(this)) // 初始化好友模型
{
    ui->setupUi(this);
    ui->listView_Chat->setModel(chatModel);         // 设置数据模型给 QListView


    // 固定窗口大小(自订尺寸为准)
    setFixedSize(width(), height());

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->installEventFilter(this);

    QFile file(":/new/prefix1/images/qss/MainWeight.qss");

    if (file.open(QFile::OpenModeFlag::ReadOnly))
    {
        this->setStyleSheet(file.readAll());
    }

    ui->label_ProFile->setPixmap(
        QPixmap(":/new/prefix1/images/Default_avatar.png").scaled(ui->label_ProFile->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)
        );


    setupMessageList();

    // 设置按钮为可选中状态
    ui->pushButton_Message->setCheckable(true);
    ui->pushButton_Friend->setCheckable(true);
    ui->pushButton_SendFile->setCheckable(true);

    ui->pushButton_SendMsg->setShortcut(Qt::Key_Enter);

    // 设置按钮为互斥模式，确保只有一个按钮能被选中
    ui->pushButton_Message->setAutoExclusive(true);
    ui->pushButton_Friend->setAutoExclusive(true);

    // 连接按钮点击事件
    connect(ui->pushButton_Message, &QPushButton::clicked, this, &MainWidget::on_pushButton_Message_released);
    connect(ui->pushButton_Friend, &QPushButton::clicked, this, &MainWidget::on_pushButton_Friend_released);

    // 默认选中第一个按钮（例如好友列表）
    ui->pushButton_Message->setChecked(true);
    ui->verticalStackedWidget->setCurrentIndex(3);
    ui->label_home_ProFile->setPixmap(QPixmap(":/new/prefix1/images/logo_3.ico").scaled(ui->label_home_ProFile->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    // 创建并设置自定义委托
    ChatMessageDelegate *delegate = new ChatMessageDelegate(this);
    ui->listView_Chat->setItemDelegate(delegate);

    UserProFile *userProfile = UserProFile::getInstance(this);
    connect(userProfile, &UserProFile::avatarLoaded, this, &MainWidget::onAvatarLoaded);

    bool connected = connect(userProfile, &UserProFile::avatarUpdated, this, &MainWidget::updateAvatar, Qt::AutoConnection);
    qInfo() << "Signal connected:" << connected;

    // 关闭按钮
    connect(ui->pushButton_Close, &QPushButton::clicked, this, [=](){
        this->close();
    });

    // 最小化按钮
    connect(ui->pushButton_Reduce, &QPushButton::clicked, this, [=](){
        this->showMinimized();
    });

    AddVerification *addVerification = AddVerification::getInstance(this);
    connect(addVerification, &AddVerification::statusChanged, this, &MainWidget::onStatusChanged);


    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWidget::onSocketReadyRead);
    connect(tcpSocket, &QTcpSocket::connected, this, &MainWidget::onSocketConnected);
    connect(tcpSocket, &QTcpSocket::errorOccurred, this, &MainWidget::onSocketError);

    tcpSocket->connectToHost("localhost", 82);

    ui->listView_Chat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listView_Users->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->listView_Users->setModel(friendListModel);
}

MainWidget::~MainWidget()
{
    delete ui;

}

void MainWidget::onAvatarLoaded(const QPixmap &pixmap)
{
    if (pixmap.isNull())
    {
        qDebug() << "Received a null pixmap";
    }
    else
    {
        // 更新当前用户头像
        currentUserAvatar = pixmap;

        // 更新界面，例如设置 QLabel 的 pixmap
        ui->label_ProFile->setPixmap(pixmap);
        ui->label_ProFile->setScaledContents(true); // 按比例缩放
        ui->label_ProFile->repaint();
    }
}

bool MainWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this)
    {
        QMouseEvent* MouseEvent = dynamic_cast<QMouseEvent*>(event);
        if (MouseEvent)
        {
            static QPoint Offset;
            static bool is = false;

            if (MouseEvent->type() == QEvent::Type::MouseButtonPress)
            {
                // 计算偏移量
                Offset =  MouseEvent->globalPosition().toPoint() - this->pos();
                // 计算是否点击的是上方边框
                if (MouseEvent->globalPosition().toPoint().y() - this->pos().y() > 40)
                {
                    is = false;
                }
                else
                {
                    is = true;
                }

            }
            else if (MouseEvent->type() == QEvent::Type::MouseMove)
            {
                if (is)
                {
                    this->move(MouseEvent->globalPosition().toPoint() - Offset);
                }
            }
        }
    }

    return false;  // 返回 false 允许事件继续传递
}

// 重绘事件
void MainWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 创建一个与当前窗口大小相同的QPixmap
    QPixmap buffer(size());
    buffer.fill(Qt::transparent);

    // 在QPixmap上进行绘制
    QPainter bufferPainter(&buffer);
    bufferPainter.setPen(Qt::NoPen);
    bufferPainter.drawRect(rect());


    // 将绘制好的QPixmap绘制到窗口上
    QPainter painters(this);

    // 不绘制边框
    painters.setPen(Qt::NoPen);
    painters.drawPixmap(0, 0, buffer);

}

// 设置消息列表
void MainWidget::setupMessageList()
{

    // 发送请求获取好友列表
    fetchFriendList(friendListModel);

    // 设置模型到 QListView 控件
    ui->listView_Users->setModel(friendListModel);

    // 设置代理，来自定义绘制每个项
    ui->listView_Users->setItemDelegate(new MessageItemDelegate(this));

    // 点击某一好友项时的处理
    connect(ui->listView_Users, &QListView::clicked, this, &MainWidget::onMessageClicked);
}

// 获取好友消息列表
void MainWidget::fetchFriendList(QStandardItemModel *friendListModel)
{
    QString username = Login::currentUsername;

    if (username.isEmpty())
    {
        qDebug() << "Username is empty.";
        return;
    }

    // 构造带参数的URL，并对username进行URL编码
    QUrl url("http://localhost/api/fetchfriendlist");
    QUrlQuery query;
    query.addQueryItem("username", username);
    url.setQuery(query);

    QNetworkRequest request(url);
    // GET请求不需要Content-Type头，但设置也无妨
    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_manager->get(request);

    connect(reply, &QNetworkReply::finished, [reply, friendListModel]()
            {
                if (reply->error() != QNetworkReply::NoError)
                {
                    qWarning() << "网络请求错误:" << reply->errorString();
                    reply->deleteLater();
                    return;
                }

                QByteArray responseData = reply->readAll();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
                if (jsonDoc.isNull())
                {
                    qWarning() << "无效的JSON响应";
                    reply->deleteLater();
                    return;
                }

                QJsonObject responseObj = jsonDoc.object();
                QString status = responseObj["status"].toString();
                int code = responseObj["code"].toInt();
                if (status != "success" || code != 200)
                {
                    QString message = responseObj["message"].toString();
                    qWarning() << "服务器返回错误：" << message;
                    reply->deleteLater();
                    return;
                }

                QJsonArray friendsArray = responseObj["data"].toArray();
                friendListModel->clear();

                for (const QJsonValue &friendValue : friendsArray)
                {
                    QJsonObject friendObj = friendValue.toObject();
                    QString user_name = friendObj["user_name"].toString();
                    QString name = friendObj["uname"].toString();
                    QString avatarUrl = friendObj["avatar"].toString();
                    QString lastMessage = friendObj["last_message"].toString();
                    QString date = friendObj["last_message_time"].toString();

                    // 处理Base64头像数据（假设avatar是纯Base64字符串）
                    QByteArray imageData = QByteArray::fromBase64(avatarUrl.toUtf8());
                    QPixmap avatar;
                    avatar.loadFromData(imageData);

                    MessageItem friendInfo = { user_name, name, lastMessage, date, avatar};

                    QStandardItem *item = new QStandardItem();
                    item->setData(friendInfo.name, Qt::DisplayRole);
                    item->setData(friendInfo.lastMessage, Qt::UserRole + 1);
                    item->setData(friendInfo.date, Qt::UserRole + 2);
                    item->setData(friendInfo.user_name, Qt::DisplayRole + 3);
                    item->setData(avatar, Qt::DecorationRole); // 设置QPixmap到DecorationRole

                    friendListModel->appendRow(item);
                }

                reply->deleteLater();
            });
}

// 处理点击事件，点击好友弹出聊天框
void MainWidget::onMessageClicked(const QModelIndex &index)
{
    // 将 model 强制转换为 QStandardItemModel
    QStandardItemModel *friendListModel = qobject_cast<QStandardItemModel *>(ui->listView_Users->model());
    if (!friendListModel)
        return;  // 如果模型类型不是 QStandardItemModel，则返回

    // 通过 index 获取对应的 QStandardItem
    QStandardItem *item = friendListModel->itemFromIndex(index);

    if (item)
    {
        // 获取好友的名字
        QString friendName = item->data(Qt::DisplayRole).toString();

        // 设置当前聊天好友的用户名
        currentFriendUsername = item->data(Qt::DisplayRole + 3).toString();

        if (currentFriendUsername.isEmpty())
        {
            return;
        }

        // 获取好友的头像
        QPixmap friendAvatar = item->data(Qt::DecorationRole).value<QPixmap>();

        // 保存当前好友的头像
        currentFriendAvatar = friendAvatar;

        // 处理消息项的点击，跳转到聊天页面
        qInfo() << "处理消息项";

        // 设置页面为 Page0（聊天页面）
        ui->verticalStackedWidget->setCurrentIndex(0);

        // 将好友名字显示到 label_FriendName 上
        ui->label_FriendName->setText(friendName);

        // 将好友头像显示到 label_FriendProFile 上
        ui->label_FriendProFile->setPixmap(friendAvatar.scaled(ui->label_FriendProFile->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

        // 从服务器加载聊天记录
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QUrl url("http://localhost/api/getChatHistory");
        QUrlQuery query;
        query.addQueryItem("user1", Login::currentUsername);
        query.addQueryItem("user2", currentFriendUsername);
        url.setQuery(query);

        QNetworkRequest request(url);
        QNetworkReply *reply = manager->get(request);

        connect(reply, &QNetworkReply::finished, [=]()
                {
                    if (reply->error() == QNetworkReply::NoError)
                    {
                        QByteArray responseData = reply->readAll();
                        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

                        if (!jsonDoc.isNull() && jsonDoc.isObject())
                        {
                            QJsonObject responseObj = jsonDoc.object();
                            QString status = responseObj["status"].toString();

                            if (status == "success")
                            {
                                QJsonArray messagesArray = responseObj["data"].toArray();
                                chatModel->clear(); // 使用数据模型的 clear 方法清空列表

                                QList<QStandardItem*> newItems;
                                for (const QJsonValue &messageValue : messagesArray)
                                {
                                    QJsonObject messageObj = messageValue.toObject();
                                    QString sender = messageObj["sender"].toString();
                                    QString content = messageObj["content"].toString();
                                    QString timestamp = messageObj["timestamp"].toString();

                                    // 设置头像
                                    QPixmap friendAvatar;
                                    if (sender == Login::currentUsername) {
                                        friendAvatar = currentUserAvatar; // 当前用户头像
                                    } else {
                                        friendAvatar =  item->data(Qt::DecorationRole).value<QPixmap>(); // 好友头像
                                    }

                                    QStandardItem *newItem = new QStandardItem(QString("[%1] %2: %3").arg(timestamp, sender, content));

                                    // 将 QPixmap 转换为 QIcon 并设置给项
                                    QIcon icon(friendAvatar);
                                    newItem->setIcon(icon);

                                    newItems.append(newItem);
                                }

                                // 批量添加新项
                                chatModel->appendRows(newItems);
                            }
                            else
                            {
                                qWarning() << "聊天记录加载失败:" << responseObj["message"].toString();
                            }
                        }
                        else
                        {
                            qWarning() << "无效的 JSON 响应";
                        }
                    }
                    else
                    {
                        qWarning() << "网络请求错误:" << reply->errorString();
                    }

                    reply->deleteLater();
                });
    }
    // 使用 QTimer 延迟滚动操作
    QTimer::singleShot(30, [=]() {
        ui->listView_Chat->scrollToBottom();
    });
}


// 设置好友列表
void MainWidget::setupFriendsList()
{
    // 创建一个标准项模型
    QStandardItemModel *model_friends = new QStandardItemModel(this);

    // 从服务器数据库获取好友列表
    QString username = Login::currentUsername;
    if (username.isEmpty())
    {
        qDebug() << "Username is empty.";
        QMessageBox::warning(this, "错误", "用户名不能为空");
        return;
    }

    // 构造带参数的URL，并对username进行URL编码
    QUrl url("http://localhost/api/getFriendsList");
    QUrlQuery query;
    query.addQueryItem("username", username);
    url.setQuery(query);
    QNetworkRequest request(url);

    // GET请求不需要Content-Type头，但设置也无妨
    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = m_manager->get(request);
    connect(reply, &QNetworkReply::finished, [reply, model_friends, this]()
            {
                if (reply->error() != QNetworkReply::NoError)
                {
                    qWarning() << "网络请求错误:" << reply->errorString();
                    QMessageBox::warning(this, "网络错误", "获取好友列表时发生网络错误: " + reply->errorString());
                    reply->deleteLater();
                    return;
                }

                QByteArray responseData = reply->readAll();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
                if (jsonDoc.isNull())
                {
                    qWarning() << "无效的JSON响应";
                    QMessageBox::warning(this, "数据错误", "获取到的好友列表数据无效");
                    reply->deleteLater();
                    return;
                }

                QJsonObject responseObj = jsonDoc.object();
                QString status = responseObj["status"].toString();
                int code = responseObj["code"].toInt();
                if (status != "success" || code != 200)
                {
                    QString message = responseObj["message"].toString();
                    qWarning() << "服务器返回错误：" << message;
                    QMessageBox::warning(this, "服务器错误", "服务器返回错误: " + message);
                    reply->deleteLater();
                    return;
                }
                model_friends->clear();

                // 先添加“新的好友”项
                FriendsItem newFriend;
                newFriend.name = "新的好友";
                newFriend.avatar = QPixmap(":/new/prefix1/images/addFriend.png");
                QStandardItem *newFriendItem = new QStandardItem();
                newFriendItem->setData(newFriend.name, MainWidget::NameRole);           // 设置名字
                newFriendItem->setData(newFriend.avatar, Qt::DecorationRole);           // 设置头像
                newFriendItem->setData(true, Qt::UserRole);                             // 设置一个标记，用来判断是否是“新的好友”
                model_friends->appendRow(newFriendItem);

                // 添加其他好友
                QJsonArray friendsArray = responseObj["data"].toArray();
                for (const QJsonValue &friendValue : friendsArray)
                {
                    QJsonObject friendObj = friendValue.toObject();
                    QString name = friendObj["uname"].toString();
                    QString user_gender = friendObj["user_gender"].toString();
                    QString user_age = friendObj["user_age"].toString();
                    QString user_region = friendObj["user_region"].toString();
                    QString avatarUrl = friendObj["avatar"].toString();

                    // 处理Base64头像数据（假设avatar是纯Base64字符串）
                    QByteArray imageData = QByteArray::fromBase64(avatarUrl.toUtf8());
                    QPixmap avatar;
                    avatar.loadFromData(imageData);

                    // 正确初始化 FriendsItem
                    FriendsItem friendInfo;
                    friendInfo.name = name;
                    friendInfo.user_gender = user_gender;
                    friendInfo.user_age = user_age;
                    friendInfo.user_region = user_region;
                    friendInfo.avatar = avatar;

                    QStandardItem *item = new QStandardItem();
                    item->setData(friendInfo.name, NameRole);
                    item->setData(friendInfo.user_gender, GenderRole);
                    item->setData(friendInfo.user_age, AgeRole);
                    item->setData(friendInfo.user_region, RegionRole);
                    item->setData(friendInfo.avatar, Qt::DecorationRole); // 设置QPixmap到DecorationRole
                    model_friends->appendRow(item);
                }

                // 设置模型到 QListView 控件
                ui->listView_Users->setModel(model_friends);

                // 设置代理，来自定义绘制每个项
                ui->listView_Users->setItemDelegate(new FriendsItemDelegate(this));

                // 点击某一好友项时的处理
                connect(ui->listView_Users, &QListView::clicked, this, &MainWidget::onFriendClicked);
                reply->deleteLater();
            });
}

// 从服务器获取申请列表
QList<MainWidget::FriendsItem> MainWidget::fetchFriendRequestsFromServer()
{
    QList<FriendsItem> friendRequests;
    QString username = Login::currentUsername;
    if (username.isEmpty())
    {
        qDebug() << "Username is empty.";
        return friendRequests;
    }

    // 构造带参数的URL，并对username进行URL编码
    QUrl url("http://localhost/api/fetchfriendrequests");
    QUrlQuery query;
    query.addQueryItem("username", username);
    url.setQuery(query);
    qDebug() << "Request URL: " << url.toString(); // 输出请求的URL

    QNetworkRequest request(url);
    // GET请求不需要Content-Type头，但设置也无妨
    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_manager->get(request);

    // 使用 QEventLoop 等待请求完成
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError)
    {
        qWarning() << "网络请求错误:" << reply->errorString();
        reply->deleteLater();
        return friendRequests;
    }

    QByteArray responseData = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    if (jsonDoc.isNull())
    {
        qWarning() << "无效的JSON响应";
        reply->deleteLater();
        return friendRequests;
    }

    QJsonObject responseObj = jsonDoc.object();
    QString status = responseObj["status"].toString();
    int code = responseObj["code"].toInt();
    if (status != "success" || code != 200) {
        QString message = responseObj["message"].toString();
        qWarning() << "服务器返回错误：" << message;
        reply->deleteLater();
        return friendRequests;
    }

    QJsonArray requestsArray = responseObj["data"].toArray();
    for (const QJsonValue &requestValue : requestsArray)
    {
        QJsonObject requestObj = requestValue.toObject();
        QString username = requestObj["username"].toString();
        QString name = requestObj["uname"].toString();
        QString avatarUrl = requestObj["avatar"].toString();
        QString statusStr = requestObj["status"].toString();

        // 处理Base64头像数据（假设avatar是纯Base64字符串）
        QByteArray imageData = QByteArray::fromBase64(avatarUrl.toUtf8());
        QPixmap avatar;
        if (!avatar.loadFromData(imageData)) {
            qWarning() << "Failed to load avatar for user: " << username;
        }

        // 声明 requestStatus 变量，这里修改为 Status 类型
        FriendsItem::Status requestStatus;
        if (statusStr == "apply")
        {
            requestStatus = FriendsItem::Pending;
        }
        else if (statusStr == "friend")
        {
            requestStatus = FriendsItem::Added;
        }
        else if (statusStr == "refuse")
        {
            requestStatus = FriendsItem::Rejected;
        }
        else
        {
            requestStatus = FriendsItem::Pending; // 默认状态
        }

        FriendsItem friendRequest;
        friendRequest.username = username;
        friendRequest.name = name;
        friendRequest.avatar = avatar;
        friendRequest.status = requestStatus;
        friendRequests.append(friendRequest); // 确保将请求添加到列表中
    }
    reply->deleteLater();
    return friendRequests;
}

// 处理点击事件，区分“新的好友”和已存在的好友
void MainWidget::onFriendClicked(const QModelIndex &index)
{
    // 将 model 强制转换为 QStandardItemModel
    QStandardItemModel *model_friends = qobject_cast<QStandardItemModel *>(ui->listView_Users->model());
    if (!model_friends)
        return;  // 如果模型类型不是 QStandardItemModel，则返回

    // 通过 index 获取对应的 QStandardItem
    QStandardItem *item = model_friends->itemFromIndex(index);
    bool isNewFriend = item->data(Qt::UserRole).toBool();  // 判断是否是“新的好友”

    if (isNewFriend)
    {
        // 处理“新的好友”项的点击，跳转到好友申请页面
        qInfo() << "处理“新的好友”项";

        // 获取好友的名字
        QString friendName = item->data(MainWidget::NameRole).toString();

        // 获取好友的头像
        QPixmap friendAvatar = item->data(Qt::DecorationRole).value<QPixmap>();

        // 获取好友申请列表（模拟从服务器获取数据）
        QList<FriendsItem> friendRequests = fetchFriendRequestsFromServer();

        // 创建一个标准项模型
        QStandardItemModel *model_apply = new QStandardItemModel(this);

        // 假设你有一个 friendRequests 列表，其中每个好友申请包含名字、头像和状态
        for (const FriendsItem &friendRequest : friendRequests)
        {
            QStandardItem *newItem = new QStandardItem();
            newItem->setData(friendRequest.name, MainWidget::NameRole);          // 设置名字
            newItem->setData(friendRequest.avatar, Qt::DecorationRole);     // 设置头像
            newItem->setData(friendRequest.username,Qt::UserRole + 2);

            // 设置状态信息
            QString statusText;
            switch (friendRequest.status) {
            case FriendsItem::Pending:
                statusText = "未处理";
                break;
            case FriendsItem::Added:
                statusText = "已添加";
                break;
            case FriendsItem::Rejected:
                statusText = "已拒绝";
                break;
            }
            newItem->setData(statusText, MainWidget::Status);  // 设置状态信息

            // 设置项的大小
            newItem->setSizeHint(QSize(200, 60));

            // 将新创建的项添加到模型
            model_apply->appendRow(newItem);
        }

        ui->listView_FriendApply->setModel(model_apply);  // 设置模型

        // 设置自定义代理（如果有自定义代理）
        ui->listView_FriendApply->setItemDelegate(new FriendRequestItemDelegate(this));

        // 点击某一申请项时的处理
        connect(ui->listView_FriendApply, &QListView::clicked, this, &MainWidget::onFriendApplyClicked);

        // 跳转页面
        ui->verticalStackedWidget->setCurrentIndex(1);  // 设置页面为 Page1（新的好友申请页面）
        ui->label_FriendName_3->setText(friendName);  // 显示好友的名字
        ui->label_FriendProFile_3->setPixmap(friendAvatar.scaled(ui->label_FriendProFile_3->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));  // 显示头像
    }

    else
    {
        // 处理已存在好友项的点击，展示该好友的个人资料
        qInfo() << "处理已存在好友项" ;

        QString friendName = item->data(MainWidget::NameRole).toString();       // 获取好友的名字
        QString friendGender = item->data(MainWidget::GenderRole).toString();   // 获取好友的性别
        QString friendAge = item->data(MainWidget::AgeRole).toString();         // 获取好友的年龄
        QString friendRegion = item->data(MainWidget::RegionRole).toString();   // 获取好友的地区
        QPixmap friendAvatar = item->data(Qt::DecorationRole).value<QPixmap>(); // 获取好友的头像

        ui->verticalStackedWidget->setCurrentIndex(2);  // 设置页面为 Page2（已存在好友页面）

        // 设置好友信息
        ui->label_data_FriendName->setText("昵称\t" + friendName);
        ui->label_data_FriendProFile->setPixmap(friendAvatar.scaled(ui->label_data_FriendProFile->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->label_data_FriendGender->setText("性别\t" + friendGender);
        ui->label_data_FriendAge->setText("年龄\t" + friendAge);
        ui->label_data_FriendRegion->setText("地区\t" + friendRegion);
    }
}

// 处理点击事件，同意好友申请
void MainWidget::onFriendApplyClicked(const QModelIndex &index)
{
    // 获取正确的模型：listView_FriendApply 对应的模型
    QStandardItemModel *model_apply = qobject_cast<QStandardItemModel *>(ui->listView_FriendApply->model());
    if (!model_apply)
        return;  // 如果模型类型不是 QStandardItemModel，则返回

    // 通过 index 获取对应的 QStandardItem
    QStandardItem *item = model_apply->itemFromIndex(index);
    if (!item)
        return;  // 确保 item 不为 nullptr

    // 获取好友的状态（假设状态存储在 Qt::UserRole + 1）
    QString status = item->data(MainWidget::Status).toString();

    // 获取申请好友的用户名
    applyUsername = item->data(Qt::UserRole + 2).toString();

    // 获取用户名
    QString user_applicant = applyUsername;                // 添加的好友用户名
    QString user_recipient = Login::currentUsername;       // 当前登录的用户名

    // 构建 URL 和请求体
    QUrl url("http://localhost/api/receiver");
    QUrlQuery query;
    query.addQueryItem("user_name_1", user_applicant);
    query.addQueryItem("user_name_2", user_recipient);

    url.setQuery(query);
    qDebug() << "Request URL: " << url.toString(); // 输出请求的URL

    QNetworkRequest request(url);
    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_manager->get(request);
    // 使用 QEventLoop 等待请求完成

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError)
    {
        qWarning() << "网络请求错误:" << reply->errorString();
        reply->deleteLater();
    }

    QByteArray responseData = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    if (jsonDoc.isNull())
    {
        qWarning() << "无效的JSON响应";
        reply->deleteLater();
    }

    QJsonObject responseObj = jsonDoc.object();
    QString rstatus = responseObj["status"].toString();
    int code = responseObj["code"].toInt();

    qInfo() << "返回验证：" << rstatus << code;

    if (status == "未处理" && (rstatus == "success" || code == 200))
    {
        // 弹出好友验证窗口
        AddVerification *addVerification = AddVerification::getInstance(this);
        if (addVerification)
        {
            addVerification->show();  // 显示窗口
            addVerification->loadUserData();
        }
        else
        {
            qWarning() << "无法创建 AddVerification 实例";
        }
    }
}

void MainWidget::onStatusChanged(const QString newStatus)
{
    qInfo() << "状态更改信号触发！" << newStatus;


    // 获取正确的模型：listView_FriendApply 对应的模型
    QStandardItemModel *model_apply = qobject_cast<QStandardItemModel *>(ui->listView_FriendApply->model());
    if (!model_apply)
        return;  // 如果模型类型不是 QStandardItemModel，则返回

    // 遍历模型，找到对应的 item 并更新状态
    for (int row = 0; row < model_apply->rowCount(); ++row)
    {
        QStandardItem *item = model_apply->item(row);
        if (item)
        {
            // 获取原有的状态和用户名
            QString currentStatus = item->data(MainWidget::Status).toString();
            QString currentUsername = item->data(Qt::UserRole + 2).toString();  // 获取用户名

            // 如果状态是 "未处理" 且用户名匹配，则更新状态
            if (currentStatus == "未处理" && currentUsername == applyUsername)
            {
                // 更新状态数据
                item->setData(newStatus, MainWidget::Status);
                qInfo() << "Updated status for user:" << currentUsername << "to:" << newStatus;

                // 强制刷新视图
                QModelIndex index = model_apply->index(row, 0);
                emit model_apply->dataChanged(index, index);  // 通知视图更新
                return;  // 只更新对应的用户状态，找到之后就可以退出
            }
        }
    }
}

void MainWidget::setupSearchList()
{

}


void MainWidget::on_pushButton_Message_released()
{
    setupMessageList();

}



void MainWidget::on_pushButton_Friend_released()
{
    setupFriendsList();
}


void MainWidget::on_pushButton_Setting_released()
{
    UserProFile *userProfile = UserProFile::getInstance(this);

    // 断开旧连接（避免重复）
    disconnect(userProfile, &UserProFile::avatarUpdated, this, &MainWidget::updateAvatar);

    // 重新连接信号
    connect(userProfile, &UserProFile::avatarUpdated, this, &MainWidget::updateAvatar);
    userProfile->show();
}

void MainWidget::updateAvatar(const QString &avatarBase64)
{
    qInfo() << "头像更改信号触发！";

    QByteArray decodedData = QByteArray::fromBase64(avatarBase64.toUtf8());
    QPixmap pixmap;
    pixmap.loadFromData(decodedData);  // 将 Base64 解码后的数据加载为 QPixmap

    if (!pixmap.isNull())
    {
        // 更新当前用户头像
        currentUserAvatar = pixmap;

        ui->label_ProFile->setPixmap(pixmap);           // 更新头像显示
        ui->label_ProFile->setScaledContents(true);     // 确保图片按比例缩放
        ui->label_ProFile->update();                    // 强制更新界面
    }
    else
    {
        qWarning() << "Failed to load avatar from Base64 data.";
    }
}

// 添加好友
void MainWidget::on_pushButton_AddFriend_released()
{
    auto friendName = ui->lineEdit_Search->text();

    qInfo() << "released" << friendName;

    // 构建 URL 和请求体
    QUrl url("http://localhost/api/addfriend");
    QUrlQuery query;
    query.addQueryItem("friendName", friendName);

    // 设置 URL 查询参数
    url.setQuery(query);

    // 创建 QNetworkRequest， 使用更新后的 URL
    QNetworkRequest request(url);

    // 网络验证
    // 使用 POST 方法发送请求
    QNetworkReply *reply = m_manager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());

    // 关联信号
    connect(reply, &QNetworkReply::finished, this, [=]()
            {
                QByteArray response = reply->readAll();
                qInfo() << QString::fromUtf8(response);

                // 根据返回的响应进行处理
                if (response.contains("success"))  // 假设接口返回成功信息时包含 "success"
                {
                    // 搜索时保存用户名
                    searchUsername = ui->lineEdit_Search->text();

                    // 获取 AddFriend 实例并加载数据
                    AddFriend *addFriend = AddFriend::getInstance(this);
                    addFriend->loadUserData();  // 加载用户数据
                    addFriend->show();  // 显示窗口
                }
                else
                {
                    QMessageBox::information(this, "提示", "用户不存在！", QMessageBox::Ok);
                }

                reply->deleteLater();  // 删除网络请求对象
            });
}

// 发送消息按钮
void MainWidget::on_pushButton_SendMsg_released()
{
    QString message = ui->textEdit_Msg->toPlainText().trimmed();
    if (message.isEmpty())
    {
        QMessageBox::warning(this, "提示", "消息不能为空！");
        return;
    }

    // 发送到服务器（不要立即添加到聊天框）
    if (!sendMessageToServer(message))
    {
        QMessageBox::critical(this, "错误", "消息发送失败！");
    }

    ui->textEdit_Msg->clear();
}

// 更新好友列表的最近消息
void MainWidget::updateRecentMessageInFriendList(const QString &message, const QString &timestamp)
{
    QStandardItemModel *friendModel = qobject_cast<QStandardItemModel*>(ui->listView_Users->model());
    if (!friendModel)
        return;

    // 遍历好友列表寻找当前聊天好友
    for (int i = 0; i < friendModel->rowCount(); ++i)
    {
        QStandardItem *item = friendModel->item(i);
        QString userName = item->data(Qt::DisplayRole + 3).toString(); // 根据实际数据角色调整

        if (userName == currentFriendUsername) {
            // 更新最近消息和时间
            item->setData(message, Qt::UserRole + 1); // 最近消息角色
            item->setData(timestamp, Qt::UserRole + 2); // 时间角色

            // 通知视图更新
            QModelIndex index = friendModel->index(i, 0);
            emit friendModel->dataChanged(index, index);
            break;
        }
    }
}


const int MAX_RECONNECT_ATTEMPTS = 3;
const int RECONNECT_INTERVAL = 3000; // 重连间隔，单位：毫秒
int reconnectAttempts = 0;

bool MainWidget::sendMessageToServer(const QString &message)
{
    if (tcpSocket->state() != QAbstractSocket::ConnectedState)
    {
        QMessageBox::warning(this, "错误", "未连接到服务器！正在尝试重连...");
        if (!reconnect())
        {
            return false;
        }
    }

    QJsonObject jsonMessage;
    jsonMessage["type"] = "text";
    jsonMessage["sender"] = Login::currentUsername;
    jsonMessage["receiver"] = currentFriendUsername;
    jsonMessage["content"] = message;
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString customTimestamp = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
    jsonMessage["timestamp"] = customTimestamp;

    QJsonDocument doc(jsonMessage);
    QByteArray data = doc.toJson();

    // 打印发送的 JSON 数据，用于调试
    qDebug() << "Sending JSON data:" << QString::fromUtf8(data);

    qint64 bytesWritten = tcpSocket->write(data);
    if (bytesWritten == -1) {
        qWarning() << "消息发送失败:" << tcpSocket->errorString();
        return false;
    }

    qInfo() << "消息发送成功！";
    return true;
}

bool MainWidget::reconnect()
{
    if (reconnectAttempts >= MAX_RECONNECT_ATTEMPTS)
    {
        qWarning() << "重连失败，达到最大重连次数";
        reconnectAttempts = 0;
        return false;
    }

    tcpSocket->abort();
    tcpSocket->connectToHost("localhost", 82);

    if (tcpSocket->waitForConnected(RECONNECT_INTERVAL))
    {
        qInfo() << "重新连接成功！";
        reconnectAttempts = 0;
        return true;
    }
    else
    {
        qWarning() << "重新连接失败，尝试第" << reconnectAttempts + 2 << "次...";
        reconnectAttempts++;
        return reconnect();
    }
}

// 处理接收到的数据
void MainWidget::onSocketReadyRead()
{
    try {
        QByteArray data = tcpSocket->readAll();
        qDebug() << "Received data:" << QString::fromUtf8(data);

        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isNull() || !doc.isObject())
        {
            qWarning() << "无效的JSON数据";
            return;
        }

        QJsonObject jsonObj = doc.object();
        QString type = jsonObj["type"].toString();

        if (type == "text")
        {
            QString sender = jsonObj["sender"].toString();
            QString content = jsonObj["content"].toString();
            QString timestamp = jsonObj["timestamp"].toString();

            // 只处理当前聊天会话的消息
            if (sender == currentFriendUsername || sender == Login::currentUsername)
            {
                // 检查是否已经存在相同消息（根据内容和时间戳）
                bool exists = false;
                for (int i = 0; i < chatModel->rowCount(); ++i)
                {
                    QStandardItem *item = chatModel->item(i);
                    if (item->text().contains(content) && item->text().contains(timestamp)) {
                        exists = true;
                        break;
                    }
                }

                if (!exists)
                {
                    QStandardItem *newItem = new QStandardItem(
                        QString("[%1] %2: %3").arg(timestamp, sender, content)
                        );

                    // 设置头像
                    QPixmap avatar = (sender == Login::currentUsername)
                                         ? currentUserAvatar
                                         : currentFriendAvatar;
                    newItem->setIcon(QIcon(avatar));

                    chatModel->appendRow(newItem);
                    ui->listView_Chat->scrollToBottom();
                }
            }

            // 更新好友列表的最近消息
            updateRecentMessageInFriendList(content, timestamp);

            // 保存消息到数据库
            saveMessageToDatabase(content, sender, currentFriendUsername);
        }
    }
    catch (const std::exception& e) {
        qWarning() << "处理接收到的数据时发生异常:" << e.what();
    }
}

// 处理连接成功
void MainWidget::onSocketConnected()
{
    qInfo() << "已连接到服务器";
}

// 处理套接字错误
void MainWidget::onSocketError(QAbstractSocket::SocketError error)
{
    if (error == QAbstractSocket::RemoteHostClosedError)
    {
        // 服务器关闭了连接，尝试重新连接
        qWarning() << "Socket错误: 服务器关闭了连接，尝试重新连接";
        if (!reconnect())
        {
            QMessageBox::critical(this, "错误", "重连失败，请检查网络或服务器状态！");
        }
    }
    else
    {
        qWarning() << "Socket错误:" << tcpSocket->errorString() << error;
    }
}

// 保存聊天内容到数据库
void MainWidget::saveMessageToDatabase(const QString &message, const QString &sender, const QString &receiver)
{
    // 确保聊天会话存在
    QEventLoop loop;
    QMetaObject::Connection conn = connect(this, &MainWidget::chatSessionIdReady, &loop, &QEventLoop::quit);
    createChatSessionIfNotExists(sender, receiver);
    loop.exec();
    disconnect(conn);

    qInfo() << "会话id：" << currentChatSessionId;

    // 构建请求 URL
    QUrl url("http://localhost/api/saveMessage");
    QUrlQuery query;
    query.addQueryItem("chat_session_id", currentChatSessionId);
    query.addQueryItem("sender_id", sender);
    query.addQueryItem("receiver_id", receiver);
    query.addQueryItem("message_content", message);
    query.addQueryItem("message_type", "text");
    query.addQueryItem("sent_at", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    url.setQuery(query);

    // 创建网络请求
    QNetworkRequest request(url);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(request);

    // 处理请求完成信号
    connect(reply, &QNetworkReply::finished, [=]()
            {
                if (reply->error() == QNetworkReply::NoError)
                {
                    QByteArray responseData = reply->readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
                    if (!jsonDoc.isNull() && jsonDoc.isObject())
                    {
                        QJsonObject responseObj = jsonDoc.object();
                        QString status = responseObj["status"].toString();
                        if (status == "success")
                        {
                            // 消息保存成功
                            qInfo() << "消息保存成功";
                        }
                        else
                        {
                            qWarning() << "消息保存失败: " << responseObj["message"].toString();
                        }
                    }
                    else
                    {
                        qWarning() << "无效的 JSON 响应";
                    }
                }
                else
                {
                    qWarning() << "网络请求错误: " << reply->errorString();
                }
                reply->deleteLater();
            });
}

// 创建聊天会话（如果不存在）
void MainWidget::createChatSessionIfNotExists(const QString &user1, const QString &user2)
{
    // 构建请求 URL，检查会话是否存在
    QUrl checkUrl("http://localhost/api/checkChatSession");
    QUrlQuery checkQuery;
    checkQuery.addQueryItem("user1", user1);
    checkQuery.addQueryItem("user2", user2);
    checkUrl.setQuery(checkQuery);

    // 创建网络请求
    QNetworkRequest checkRequest(checkUrl);
    QNetworkAccessManager *checkManager = new QNetworkAccessManager(this);
    QNetworkReply *checkReply = checkManager->get(checkRequest);

    // 处理请求完成信号
    connect(checkReply, &QNetworkReply::finished, [=]()
            {
                if (checkReply->error() == QNetworkReply::NoError)
                {
                    QByteArray responseData = checkReply->readAll();
                    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

                    if (!jsonDoc.isNull() && jsonDoc.isObject())
                    {
                        QJsonObject responseObj = jsonDoc.object();
                        QString status = responseObj["status"].toString();

                        if (status == "exists")
                        {
                            // 会话已存在，获取会话 ID
                            currentChatSessionId = responseObj["session_id"].toString();
                            qInfo() << "会话已存在" << currentChatSessionId << "session_id:" << responseObj["session_id"].toString();
                            emit chatSessionIdReady(); // 发射信号
                        }
                        else
                        {
                            // 会话不存在，创建新会话
                            QUrl createUrl("http://localhost/api/createChatSession");
                            QUrlQuery createQuery;
                            createQuery.addQueryItem("user1", user1);
                            createQuery.addQueryItem("user2", user2);
                            createQuery.addQueryItem("created_at", QDateTime::currentDateTime().toString(Qt::ISODate));
                            createQuery.addQueryItem("updated_at", QDateTime::currentDateTime().toString(Qt::ISODate));
                            createUrl.setQuery(createQuery);

                            QNetworkRequest createRequest(createUrl);
                            QNetworkAccessManager *createManager = new QNetworkAccessManager(this);
                            QNetworkReply *createReply = createManager->get(createRequest);

                            connect(createReply, &QNetworkReply::finished, [=]()
                                    {
                                        if (createReply->error() == QNetworkReply::NoError)
                                        {
                                            QByteArray createResponseData = createReply->readAll();
                                            QJsonDocument createJsonDoc = QJsonDocument::fromJson(createResponseData);

                                            if (!createJsonDoc.isNull() && createJsonDoc.isObject())
                                            {
                                                QJsonObject createResponseObj = createJsonDoc.object();
                                                QString createStatus = createResponseObj["status"].toString();

                                                if (createStatus == "success")
                                                {
                                                    // 会话创建成功，获取新会话 ID
                                                    currentChatSessionId = createResponseObj["session_id"].toString();
                                                    emit chatSessionIdReady(); // 发射信号
                                                }
                                                else
                                                {
                                                    qWarning() << "聊天会话创建失败: " << createResponseObj["message"].toString();
                                                }
                                            }
                                            else
                                            {
                                                qWarning() << "无效的 JSON 响应";
                                            }
                                        }
                                        else
                                        {
                                            qWarning() << "网络请求错误: " << createReply->errorString();
                                        }
                                        createReply->deleteLater();
                                    });
                        }
                    }
                    else
                    {
                        qWarning() << "无效的 JSON 响应";
                    }
                }
                else
                {
                    qWarning() << "网络请求错误: " << checkReply->errorString();
                }
                checkReply->deleteLater();
            });
}


void MainWidget::on_pushButton_FriendVoice_released()
{
    QMessageBox::information(this, "提示", "语音通话功能还未开通，敬请期待！", QMessageBox::Ok);
}


void MainWidget::on_pushButton_FriendVideo_released()
{
    QMessageBox::information(this, "提示", "视频通话功能还未开通，敬请期待！", QMessageBox::Ok);
}

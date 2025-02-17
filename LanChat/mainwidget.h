#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QColorDialog>
#include <QFile>
#include <QLabel>
#include <QStandardItem>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTcpSocket>
#include <QDateTime>
#include <QTimer>
#include "nonclickablechatmodel.h"

// 前向声明
class UserProFile;
class AddVerification;
class FriendRequestWidget;
class FriendDetailsWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QLabel
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    // 消息列表结构体定义
    struct MessageItem {
        QString user_name;
        QString name;
        QString lastMessage;
        QString date;
        QPixmap avatar;
    };

    // 好友列表结构体定义
    struct FriendsItem {
        enum Status {
            Pending,   // 未处理
            Added,     // 已添加
            Rejected   // 已拒绝
        };

        QString username;
        QString name;
        QPixmap avatar;
        QString user_gender;
        QString user_age;
        QString user_region;

        Status status = Pending;  // 默认状态为“未处理”
    };

    enum FriendItemRoles {
        NameRole = Qt::UserRole + 1,
        GenderRole,
        AgeRole,
        RegionRole,
        Status
    };

    bool eventFilter(QObject *watched, QEvent *event);

    // 保存搜索用户名
    static QString searchUsername;

    // 保存申请用户名
    static QString applyUsername;

    // 当前聊天会话的ID
    static QString currentChatSessionId;

    // 处理点击事件，点击好友弹出聊天框
    void onMessageClicked(const QModelIndex &index);

    // 处理点击事件，区分“新的好友”和已存在的好友
    void onFriendClicked(const QModelIndex &index);

    // 处理点击事件，同意好友申请
    void onFriendApplyClicked(const QModelIndex &index);

    // 发送消息到服务器
    bool sendMessageToServer(const QString &message);

    bool reconnect();

    // 保存消息到数据库
    void saveMessageToDatabase(const QString &message, const QString &sender, const QString &receiver);

    // 创建聊天会话
    void createChatSessionIfNotExists(const QString &user1, const QString &user2);

    void updateRecentMessageInFriendList(const QString &message, const QString &timestamp);

private:
    Ui::MainWidget *ui;                        // 用户界面指针，指向 MainWidget的 UI 对象

    QNetworkAccessManager *m_manager;          // 网络请求管理器，负责处理网络请求和响应

    QTcpSocket *tcpSocket;                     // TCP Socket

    UserProFile *userProfile;                  // 用户资料对象，存储当前用户的个人信息和资料

    AddVerification *addVerification;          // 添加验证对象，可能用于处理用户添加好友时的验证逻辑

    FriendRequestWidget *friendRequestWidget;  // 好友请求窗口，处理显示和管理来自其他用户的好友请求

    FriendDetailsWidget *friendDetailsWidget;  // 好友详情窗口，显示朋友的详细信息

    QStackedWidget *stackedWidget;             // 堆叠式窗口，允许在多个视图之间切换

    QString currentFriendUsername;             // 当前聊天好友的用户名

    NonClickableChatModel *chatModel;          // 使用自定义模型类

    QPixmap currentUserAvatar;                 // 当前用户头像

    QPixmap currentFriendAvatar;               // 保存当前好友的头像

    QStandardItemModel *friendListModel;       // 好友列表模型



protected:
    // 重绘事件
   void paintEvent(QPaintEvent *event);

   // 消息列表
   void setupMessageList();

   // 好友列表
   void setupFriendsList();

   // 搜索列表
   void setupSearchList();

   // 从服务器获取好友申请信息
   QList<MainWidget::FriendsItem> fetchFriendRequestsFromServer();

   // 获取好友消息列表
   void fetchFriendList(QStandardItemModel *friendListModel);

private slots:
   // 消息列表按钮
   void on_pushButton_Message_released();

   // 好友列表按钮
   void on_pushButton_Friend_released();

   // 设置按钮
   void on_pushButton_Setting_released();

   // 加载界面头像
   void onAvatarLoaded(const QPixmap &pixmap);

   // 添加好友
   void on_pushButton_AddFriend_released();

   // 更新界面头像
   void updateAvatar(const QString &avatarBase64);

   // 接收并处理状态变化
   void onStatusChanged(const QString newStatus);

   // 读取服务器发送的消息
   void onSocketReadyRead();

   // 连接成功时的槽函数
   void onSocketConnected();

   // 处理Socket错误
   void onSocketError(QAbstractSocket::SocketError error);

   // 发送消息按钮
   void on_pushButton_SendMsg_released();

   void on_pushButton_FriendVoice_released();

   void on_pushButton_FriendVideo_released();

   signals:
   // 会话ID就绪信号
   void chatSessionIdReady();
};
#endif // MAINWIDGET_H

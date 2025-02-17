#ifndef FRIENDSREQUEST_H
#define FRIENDSREQUEST_H

#include <QDialog>
#include <QStandardItemModel>
#include <QListView>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QJsonArray>
#include <QJsonValue>

class FriendRequestWidget : public QDialog
{
    Q_OBJECT

public:
    explicit FriendRequestWidget(QWidget *parent = nullptr);

    ~FriendRequestWidget();

    // 获取唯一实例
    static FriendRequestWidget* getInstance(QWidget *parent = nullptr);

    // 初始化好友请求列表
    void setupFriendRequestList();

private slots:
    // 处理网络请求返回
    void onFriendRequestReply();

    // 点击接受按钮时
    void onAcceptClicked();

    // 点击拒绝按钮时
    void onRejectClicked();

    // 处理同意/拒绝请求后的网络响应
    void onFriendRequestActionReply();

private:
    // UI 元素
    QListView *friendRequestListView;

    QPushButton *acceptButton;

    QPushButton *rejectButton;

    // 网络管理器
    QNetworkAccessManager *networkManager;

    // 模型，用于显示好友请求列表
    QStandardItemModel *model;

    // 静态成员，存储唯一实例
    static FriendRequestWidget* instance;
};

#endif // FRIENDSREQUEST_H

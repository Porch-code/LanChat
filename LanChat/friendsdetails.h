#ifndef FRIENDSDETAILS_H
#define FRIENDSDETAILS_H

#include <QWidget>
#include <QDialog>
#include <QListView>
#include <QStandardItemModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPixmap>

class FriendDetailsWidget : public QDialog
{
    Q_OBJECT

public:
    // 获取唯一实例的静态方法
    static FriendDetailsWidget* getInstance(const QString &friendName, QWidget *parent = nullptr);

    // 禁止复制和赋值操作
    FriendDetailsWidget(const FriendDetailsWidget&) = delete;

    FriendDetailsWidget& operator=(const FriendDetailsWidget&) = delete;

    ~FriendDetailsWidget();

    void setupFriendDetailList(const QString &friendName);

private slots:
    void onFriendDetailsReply();

private:
    // 构造函数私有化，确保只能通过 getInstance() 创建实例
    explicit FriendDetailsWidget(const QString &friendName, QWidget *parent = nullptr);

    // 静态指针保存唯一实例
    static FriendDetailsWidget *instance;

    QListView *friendDetailListView;

    QStandardItemModel *model;

    QNetworkAccessManager *networkManager;
};

#endif // FRIENDSDETAILS_H

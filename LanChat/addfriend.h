#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCloseEvent>
#include <QProcessEnvironment>
#include <QMessageBox>
#include <QUrl>
#include <QUrlQuery>
#include <QFileDialog>
#include <QPixmap>
#include <QHttpMultiPart>
#include <QJsonObject>
#include <QJsonDocument>
#include <QSqlQuery>
#include <QFile>

namespace Ui {
class AddFriend;
}

class AddFriend : public QDialog
{
    Q_OBJECT

public:
    // explicit AddFriend(QWidget *parent = nullptr);
    ~AddFriend();

    // 获取当前实例
    static AddFriend* getInstance(QWidget *parent = nullptr);

    // 加载搜索用户数据
    void loadUserData();

    // 接受搜索用户数据
    void onUserDataReceived();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_pushButton_AddFriend_released();

signals:
    // 定义信号来传递申请好友的消息
    void applyToAddFriendStatus(const QString &user_name_1, const QString &user_name_2, const QString &statusMessage);

private:
    Ui::AddFriend *ui;

    QNetworkAccessManager *m_manager;

    // 静态成员，保存当前实例
    static AddFriend* currentInstance;

    // 网络管理器作为成员变量
    QNetworkAccessManager* networkManager;

    // 构造函数私有化，防止外部创建实例
    explicit AddFriend(QWidget* parent = nullptr);

};

#endif // ADDFRIEND_H

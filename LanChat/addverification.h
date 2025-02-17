#ifndef ADDVERIFICATION_H
#define ADDVERIFICATION_H

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
#include "mainwidget.h"

namespace Ui {
class AddVerification;
}

class AddVerification : public QDialog
{
    Q_OBJECT

public:
    // explicit AddFriend(QWidget *parent = nullptr);
    ~AddVerification();

    explicit AddVerification(QWidget *parent = nullptr);

    // 获取当前实例
    static AddVerification* getInstance(QWidget *parent = nullptr);

    // 加载申请用户数据
    void loadUserData();

    // 接受申请用户数据
    void onUserDataReceived();

protected:
    void showEvent(QShowEvent *event) override;

signals:
    void statusChanged(const QString newStatus);  // 发射状态变化信号

private slots:
    void on_pushButton_agree_released();

    void on_pushButton_refuse_released();

private:
    Ui::AddVerification *ui;

    QNetworkAccessManager *m_manager;

    // 静态成员，保存当前实例
    static AddVerification* currentInstance;

    // 网络管理器作为成员变量
    QNetworkAccessManager* networkManager;
};

#endif // ADDVERIFICATION_H

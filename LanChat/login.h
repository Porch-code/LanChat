#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QFile>
#include <QLabel>
#include <QKeyEvent>
#include <QtDebug>
#include <QApplication>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkRequest>

// 前向声明 Signup 类
class Signup;

class MainWidget;

namespace Ui {
class Login;
}

class Login : public QLabel
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();

    // 键盘事件
    void keyPressEvent(QKeyEvent* ev) override;

    // 鼠标事件
    bool eventFilter(QObject *watched, QEvent *event) override;

    // 保存当前用户名
    static QString currentUsername;

private slots:
    void on_pushButton_Login_released();

    void on_pushButton_Register_released();

private:
    Ui::Login *ui;

    QNetworkAccessManager *m_manager;

    Signup *signupPage;

    MainWidget *mainPage;
};

#endif // LOGIN_H

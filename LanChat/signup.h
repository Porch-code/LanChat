#ifndef SIGNUP_H
#define SIGNUP_H

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

// 前向声明 Login 类
class Login;

namespace Ui {
class Signup;
}

class Signup : public QLabel
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);

    ~Signup();

    // 键盘事件
    void keyPressEvent(QKeyEvent* ev) override;

    // 鼠标事件
    bool eventFilter(QObject *watched, QEvent *event) override;


private slots:
    void on_pushButton_Return_released();

    void on_pushButton_Register_released();

private:
    Ui::Signup *ui;

    QNetworkAccessManager *m_manager;

    Login *loginPage;
};

#endif // SIGNUP_H

#include "login.h"
#include "signup.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;

    // 打开登录页面
    l.show();


    return a.exec();
}

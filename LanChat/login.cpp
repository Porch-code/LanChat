#include "login.h"
#include "ui_login.h"
#include "signup.h"
#include "mainwidget.h"

QString Login::currentUsername = "";

Login::Login(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::Login),
    m_manager(new QNetworkAccessManager(this)),
    signupPage(nullptr),
    mainPage(nullptr)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->installEventFilter(this);

    ui->label_ProFile->setPixmap(QPixmap(":/new/prefix1/images/logo_3.ico").scaled(ui->label_ProFile->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    // 判断协议是否勾选
    connect(ui->checkBox_Authorize, &QCheckBox::stateChanged, this, [=](int state){
        if (state == Qt::Checked)
        {
            ui->pushButton_Login->setEnabled(true);
        }
        else
        {
            ui->pushButton_Login->setEnabled(false);
        }
    });

    ui->pushButton_Login->setEnabled(false);

    // 设置密码框的显示模式为密码模式
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);

    // 关闭按钮
    connect(ui->pushButton_Close, &QPushButton::clicked, this, [=](){
        this->close();
    });

    // 最小化按钮
    connect(ui->pushButton_Reduce, &QPushButton::clicked, this, [=](){
        this->showMinimized();
    });

    QFile file(":/new/prefix1/images/qss/LoginWeight.qss");

    if (file.open(QFile::OpenModeFlag::ReadOnly))
    {
        this->setStyleSheet(file.readAll());
    }
}

Login::~Login()
{
    delete ui;
}

void Login::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_F5)
    {
        qDebug() << qApp->applicationDirPath() + "/../../LanChat/images/LoginWeight.qss";

        QFile file(qApp->applicationDirPath() + "/../../LanChat/images/LoginWeight.qss");

        if (file.open(QFile::OpenModeFlag::ReadOnly))
        {
            this->setStyleSheet(file.readAll());
        }
    }

    return QLabel::keyPressEvent(ev);
}

bool Login::eventFilter(QObject *watched, QEvent *event)
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
                if (MouseEvent->globalPosition().toPoint().y() - this->pos().y() > 30)
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

    return QLabel::eventFilter(watched, event);
}



void Login::on_pushButton_Login_released()
{
    auto username = ui->lineEdit_UserName->text();
    auto password = ui->lineEdit_Password->text();



    qInfo() << "released" << username << password;

    // 用户名不能为空
    if (username.isEmpty())
    {
        QMessageBox::information(this, "提示", "用户名不能为空！", QMessageBox::Ok);
    }

    // 密码不能为空
    if (password.isEmpty() && !username.isEmpty())
    {
        QMessageBox::information(this, "提示", "密码不能为空！", QMessageBox::Ok);
    }

    // 登录判断（写死）
    /*
    if (username == "zxx" && password == "123456")
    {
        QMessageBox::information(this,"提示", "登录成功！",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this,"提示", "用户名或密码错误！",QMessageBox::Ok);
    }
    */

    // 构建 URL 和请求体
    QUrl url("http://localhost/api/login");
    QUrlQuery query;
    query.addQueryItem("username", username);
    query.addQueryItem("password", password);

    // 设置 URL 查询参数
    url.setQuery(query);

    // 创建 QNetworkRequest，使用更新后的 URL
    QNetworkRequest request(url);

    // 网络验证
    // 通过GET方法提交用户名和密码 ：数据直接写在链接后面的 http://localhost/api/login?username=zxx&password=123456
    // 通过POST方法提交用户名和密码 : 数据作为主体(body)发送 http://localhost/api/login username=zxx&password=123456
    // 使用 POST 方法发送请求
    QNetworkReply *reply = m_manager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());


    // 关联信号
    connect(reply, &QNetworkReply::finished, this, [=]()
    {
        QByteArray response = reply->readAll();
        qInfo() << QString::fromUtf8(response);

        // 解析 JSON 数据
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        if (!jsonDoc.isNull() && jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            QString status = jsonObj["status"].toString();

            if (status == "success") {
                // 登录时保存用户名
                currentUsername = username;

                // QMessageBox::information(this, "提示", "登录成功！", QMessageBox::Ok);

                mainPage = new MainWidget();  // 初始化主页面

                mainPage->show();             // 显示主页面

                this->close();                // 关闭当前页面
            } else {
                QMessageBox::information(this, "提示", "用户名或密码不正确!", QMessageBox::Ok);
            }
        } else {
            QMessageBox::information(this, "提示", "服务器响应格式错误!", QMessageBox::Ok);
        }
    });
}

void Login::on_pushButton_Register_released()
{
    signupPage = new Signup();  // 初始化注册页面

    QPoint currentPos = this->pos(); // 获取当前窗口的左上角坐标

    signupPage->move(currentPos);    // 将注册页面显示在当前位置

    signupPage->show();         // 显示注册页面

    this->hide();               // 隐藏当前登录界面
}

#include "signup.h"
#include "ui_signup.h"
#include "login.h"

Signup::Signup(QWidget *parent)
    : QLabel(parent)
    , ui(new Ui::Signup)
    , m_manager(new QNetworkAccessManager(this))
    , loginPage(nullptr)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->installEventFilter(this);


    ui->label_ProFile->setPixmap(QPixmap(":/new/prefix1/images/logo_3.ico").scaled(ui->label_ProFile->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

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

Signup::~Signup()
{
    delete ui;
}

void Signup::keyPressEvent(QKeyEvent *ev)
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

bool Signup::eventFilter(QObject *watched, QEvent *event)
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

void Signup::on_pushButton_Register_released()
{
    auto username = ui->lineEdit_UserName->text();
    auto password = ui->lineEdit_Password->text();
    auto confirm_password = ui->lineEdit_Password_2->text();

    qInfo() << "released" << username << password << confirm_password;

    // 用户名不能为空
    if (username.isEmpty())
    {
        QMessageBox::information(this, "提示", "用户名不能为空！", QMessageBox::Ok);
        return ;
    }

    // 密码不能为空
    if (password.isEmpty() && !username.isEmpty())
    {
        QMessageBox::information(this, "提示", "密码不能为空！", QMessageBox::Ok);
        return ;
    }

    // 确认密码不能为空
    if (confirm_password.isEmpty() && !username.isEmpty() && !password.isEmpty())
    {
        QMessageBox::information(this, "提示", "确认密码不能为空！", QMessageBox::Ok);
        return ;
    }

    // 确认密码和密码不匹配
    if (password != confirm_password)
    {
        QMessageBox::information(this, "提示", "两次密码不一致！", QMessageBox::Ok);
        return ;
    }

    // 构建 URL 和请求体
    QUrl url("http://localhost/api/signup"); // 假设注册接口是 /api/register
    QUrlQuery query;
    query.addQueryItem("username", username);
    query.addQueryItem("password", password);

    // 设置 URL 查询参数
    url.setQuery(query);

    // 创建 QNetworkRequest，使用更新后的 URL
    QNetworkRequest request(url);

    // 使用 POST 方法提交数据（注册时通常使用 POST 请求）
    QNetworkReply *reply = m_manager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());

    // 关联信号
    connect(reply, &QNetworkReply::finished,this,[=]()
    {
        QByteArray response = reply->readAll();
        qInfo() << QString::fromUtf8(response);

        // 根据返回的响应进行处理
        if (response.contains("success"))
        {
            QMessageBox::information(this, "提示", "注册成功！", QMessageBox::Ok);
        }
        else if (response.contains("repeat"))
        {
            QMessageBox::information(this, "提示", "注册失败，用户名已存在！", QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this, "提示", "注册失败，请重试！", QMessageBox::Ok);
        }
    });
}

void Signup::on_pushButton_Return_released()
{
    // 初始化登录页面
    loginPage = new Login();

    // 获取当前窗口的左上角坐标
    QPoint currentPos = this->pos();

    // 将注册页面显示在当前位置
    loginPage->move(currentPos);

    // 显示登录页面
    loginPage->show();

    this->hide();
}

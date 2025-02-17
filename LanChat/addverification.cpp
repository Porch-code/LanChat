#include "addverification.h"
#include "ui_addverification.h"
#include "mainwidget.h"
#include "login.h"

AddVerification* AddVerification::currentInstance = nullptr;

AddVerification::AddVerification(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddVerification)
    , m_manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    ui->label_ProFile->setPixmap(QPixmap(":/new/prefix1/images/Default_avatar.png").scaled(ui->label_ProFile->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    QFile file(":/new/prefix1/images/qss/AddFriendWeight.qss");

    if (file.open(QFile::OpenModeFlag::ReadOnly))
    {
        this->setStyleSheet(file.readAll());
    }

    // 初始化网络管理器
    networkManager = new QNetworkAccessManager(this);  // 将网络管理器设置为 AddFriend 的子对象
}

AddVerification::~AddVerification()
{
    delete ui;
}

void AddVerification::showEvent(QShowEvent *event)
{
    // 如果已有一个窗口实例存在，则不再创建新的窗口
    if (currentInstance != nullptr)
    {
        currentInstance->raise();
        currentInstance->activateWindow();
        return;  // 退出，不再显示新的窗口
    }

    // 否则，设置当前窗口为实例
    currentInstance = this;

    // 调用基类的 showEvent 方法
    QDialog::showEvent(event);

}

// 获取当前实例，如果实例不存在，则创建新实例
AddVerification* AddVerification::getInstance(QWidget *parent)
{
    if (currentInstance == nullptr)
    {
        // 创建新实例
        currentInstance = new AddVerification(parent);
    }
    return currentInstance;
}

// 加载申请用户数据
void AddVerification::loadUserData()
{
    // 获取当前搜索的用户名
    QString username = MainWidget::applyUsername;
    if (username.isEmpty())
    {
        qDebug() << "Username is empty.";
        return;
    }

    qInfo() << "Released" << username;

    // 创建一个 QNetworkAccessManager 对象来发起网络请求
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();

    // 构造请求的 URL，假设我们通过 GET 请求来获取用户数据
    QUrl url(QString("http://localhost/api/getSearchUserData?username=%1").arg(username));
    qDebug() << "Request URL: " << url.toString();  // 打印请求的 URL

    // 创建一个网络请求
    QNetworkRequest request(url);

    // 发送 GET 请求
    QNetworkReply* reply = networkManager->get(request);

    // 连接请求完成的信号到处理槽函数
    connect(reply, &QNetworkReply::finished, this, &AddVerification::onUserDataReceived);
}

// 接受申请用户数据
void AddVerification::onUserDataReceived()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Request failed:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    // 获取服务器响应的内容
    QByteArray responseData = reply->readAll();
    // qDebug() << "Response Data: " << responseData;  // 打印响应数据

    // 解析 JSON 数据
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    if (!jsonDoc.isObject()) {
        qDebug() << "Invalid JSON format.";
        reply->deleteLater();
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    // 从 JSON 中获取用户数据
    QString uname = jsonObj["data"].toObject()["uname"].toString();
    QString region = jsonObj["data"].toObject()["user_region"].toString();

    // 从封装的 JSON 数据中获取头像字段
    QString avatarBase64 = jsonObj["data"].toObject()["avatar"].toString();  // 获取头像的 Base64 编码字符串

    if (avatarBase64.isEmpty()) {
        qDebug() << "Avatar Base64 is empty.";
    } else {
        QByteArray avatarData = QByteArray::fromBase64(avatarBase64.toUtf8());
        if (avatarData.isEmpty()) {
            qDebug() << "Failed to decode Base64 string.";
        } else {
            qDebug() << "Decoded Avatar Data size:" << avatarData.size();
        }
    }

    // 解码头像数据
    QByteArray avatarData = QByteArray::fromBase64(avatarBase64.toUtf8());  // 解码为二进制数据

    qInfo() << "Released" << uname << region;

    // 将数据填充到界面控件中
    ui->label_Name->setText(uname);
    ui->label_Region->setText("地区：" + region);

    // 如果头像的二进制数据有效，则加载头像
    // 如果头像的二进制数据有效，则加载头像
    if (!avatarData.isEmpty())
    {
        QPixmap pixmap;
        if (pixmap.loadFromData(avatarData))  // 从二进制数据加载图片
        {
            ui->label_ProFile->setPixmap(pixmap);

            // 设置标签内容自动缩放
            ui->label_ProFile->setScaledContents(true);
        }
        else
        {
            qDebug() << "Failed to load avatar from binary data.";
        }
    }

    // 处理完数据后，删除网络请求对象
    reply->deleteLater();
}



void AddVerification::on_pushButton_agree_released()
{
    // 获取用户名
    QString user_name_1 = Login::currentUsername;       // 当前登录的用户名
    QString user_name_2 = MainWidget::applyUsername;    // 申请用户的用户名
    QString buttonText = "friend";

    qInfo() << "released" << user_name_1 << user_name_2 << buttonText;

    // 用户名不能为空
    if (user_name_1.isEmpty())
    {
        QMessageBox::information(this, "提示", "当前登录的用户名不能为空！", QMessageBox::Ok);
        return ;
    }
    if (user_name_2.isEmpty())
    {
        QMessageBox::information(this, "提示", "申请用户的用户名不能为空！", QMessageBox::Ok);
        return ;
    }

    // 构建 URL 和请求体
    QUrl url("http://localhost/api/addverification");
    QUrlQuery query;
    query.addQueryItem("user_name_1", user_name_1);
    query.addQueryItem("user_name_2", user_name_2);
    query.addQueryItem("buttonText", buttonText);

    // 设置 URL 查询参数
    url.setQuery(query);

    // 创建 QNetworkRequest，使用更新后的 URL
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");  // 设置 Content-Type

    // 使用 POST 方法发送请求
    QNetworkReply *reply = m_manager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());

    // 关联信号
    connect(reply, &QNetworkReply::finished, this, [=]()
    {
        QByteArray response = reply->readAll();
        qInfo() << QString::fromUtf8(response);

        // 根据返回的响应进行处理
        if (response.contains("success"))
        {
            // 发出信号，修改状态为 "已同意"
            emit statusChanged("已添加");

            // 关闭窗口
            this->close();
        }
        else
        {
            QMessageBox::information(this, "提示", "操作失败！", QMessageBox::Ok);
        }
    });


}


void AddVerification::on_pushButton_refuse_released()
{
    // 获取用户名
    QString user_name_1 = Login::currentUsername;       // 当前登录的用户名
    QString user_name_2 = MainWidget::applyUsername;    // 申请用户的用户名
    QString buttonText = "refuse";

    qInfo() << "released" << user_name_1 << user_name_2 << buttonText;

    // 用户名不能为空
    if (user_name_1.isEmpty())
    {
        QMessageBox::information(this, "提示", "当前登录的用户名不能为空！", QMessageBox::Ok);
        return ;
    }
    if (user_name_2.isEmpty())
    {
        QMessageBox::information(this, "提示", "申请用户的用户名不能为空！", QMessageBox::Ok);
        return ;
    }

    // 构建 URL 和请求体
    QUrl url("http://localhost/api/addverification");
    QUrlQuery query;
    query.addQueryItem("user_name_1", user_name_1);
    query.addQueryItem("user_name_2", user_name_2);
    query.addQueryItem("buttonText", buttonText);

    // 设置 URL 查询参数
    url.setQuery(query);

    // 创建 QNetworkRequest，使用更新后的 URL
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");  // 设置 Content-Type

    // 使用 POST 方法发送请求
    QNetworkReply *reply = m_manager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());

    // 关联信号
    connect(reply, &QNetworkReply::finished, this, [=]()
    {
        QByteArray response = reply->readAll();
        qInfo() << QString::fromUtf8(response);

        // 根据返回的响应进行处理
        if (response.contains("success"))
        {
            // 发出信号，修改状态
            emit statusChanged("已拒绝");

            // 关闭窗口
            this->close();
        }
        else
        {
            QMessageBox::information(this, "提示", "操作失败！", QMessageBox::Ok);
        }
    });
}


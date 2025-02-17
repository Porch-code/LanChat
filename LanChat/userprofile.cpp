#include "userprofile.h"
#include "ui_userprofile.h"
#include "login.h"
#include <mainwidget.h>

UserProFile* UserProFile::currentInstance = nullptr;

UserProFile::UserProFile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserProFile)
    , m_manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // 设置 comboBox_Gender 的值
    ui->comboBox_Gender->addItem("男");
    ui->comboBox_Gender->addItem("女");

    // 获取 comboBox_Gender 的模型
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->comboBox_Gender->model());
    if (!model)
    {
        model = new QStandardItemModel(ui->comboBox_Gender);
        ui->comboBox_Gender->setModel(model);
    }

    // 遍历每个选项并设置对齐方式
    for (int i = 0; i < model->rowCount(); ++i)
    {
        QStandardItem* item = model->item(i);
        if (item)
        {
            item->setTextAlignment(Qt::AlignCenter);
        }
    }

    // 设置当前选中项的对齐方式
    ui->comboBox_Gender->setStyleSheet("QComboBox { text-align: center; }");

    // 设置 spinBox_Age 的范围
    ui->spinBox_Age->setRange(0, 120);  // 假设年龄的范围是 0 到 120
    ui->spinBox_Age->setValue(18);      // 设置默认年龄为 18

    loadUserData();

    QFile file(":/new/prefix1/images/qss/UserProFile.qss");

    if (file.open(QFile::OpenModeFlag::ReadOnly))
    {
        this->setStyleSheet(file.readAll());
    }
}

UserProFile::~UserProFile()
{
    delete ui;
}

// 获取当前实例，如果实例不存在，则创建新实例
UserProFile* UserProFile::getInstance(QWidget *parent)
{
    if (currentInstance == nullptr)
    {
        currentInstance = new UserProFile(parent);  // 创建新实例
    }
    currentInstance->loadUserData();

    return currentInstance;
}

void UserProFile::showEvent(QShowEvent *event)
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

void UserProFile::closeEvent(QCloseEvent *event)
{
    // 在窗口关闭时清除当前实例
    currentInstance = nullptr;
    // 继续关闭操作
    event->accept();
}

// 加载当前用户数据
void UserProFile::loadUserData()
{
    // 获取当前登录的用户名
    QString username = Login::currentUsername;
    if (username.isEmpty())
    {
        qDebug() << "Username is empty.";
        return;
    }

    qInfo() << "Released" << username;

    // 创建一个 QNetworkAccessManager 对象来发起网络请求
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);

    // 构造请求的 URL，假设我们通过 GET 请求来获取用户数据
    QUrl url(QString("http://localhost/api/getUserData?username=%1").arg(username));

    // 打印请求的 URL
    qDebug() << "Request URL: " << url.toString();

    // 创建一个网络请求
    QNetworkRequest request(url);

    // 发送 GET 请求
    QNetworkReply* reply = networkManager->get(request);

    // 连接请求完成的信号到处理槽函数
    connect(reply, &QNetworkReply::finished, this, &UserProFile::onUserDataReceived);
}

// 接受当前用户数据
void UserProFile::onUserDataReceived()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Request failed:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    // 获取服务器响应的内容
    QByteArray responseData = reply->readAll();
    // qDebug() << "Response Data: " << responseData;  // 打印响应数据

    // 解析 JSON 数据
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    if (!jsonDoc.isObject())
    {
        qDebug() << "Invalid JSON format.";
        reply->deleteLater();
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    // 从 JSON 中获取用户数据
    QString uname = jsonObj["data"].toObject()["uname"].toString();
    QString gender = jsonObj["data"].toObject()["user_gender"].toString();
    int age = jsonObj["data"].toObject()["user_age"].toInt();
    QString region = jsonObj["data"].toObject()["user_region"].toString();

    // 从封装的 JSON 数据中获取头像字段
    QString avatarBase64 = jsonObj["data"].toObject()["avatar"].toString();

    if (avatarBase64.isEmpty())
    {
        qDebug() << "Avatar Base64 is empty.";
    }
    else
    {
        QByteArray avatarData = QByteArray::fromBase64(avatarBase64.toUtf8());
        if (avatarData.isEmpty())
        {
            qDebug() << "Failed to decode Base64 string.";
        } else {
            qDebug() << "Decoded Avatar Data size:" << avatarData.size();
        }
    }

    // 解码头像数据
    QByteArray avatarData = QByteArray::fromBase64(avatarBase64.toUtf8());  // 解码为二进制数据

    qInfo() << "Released" << uname << gender << age << region;

    // 将数据填充到界面控件中
    ui->lineEdit_UnameEdit->setText(uname);
    ui->comboBox_Gender->setCurrentText(gender);
    ui->spinBox_Age->setValue(age);
    ui->lineEdit_RegionEdit->setText(region);

    // 如果头像的二进制数据有效，则加载头像
    if (!avatarData.isEmpty())
    {
        QPixmap pixmap;
        // 从二进制数据加载图片
        if (pixmap.loadFromData(avatarData))
        {
            // 设置头像到当前 QDialog 中的 QLabel
            ui->label_ProFile->setPixmap(pixmap);

            // 触发信号，将图片传递给 MainWidget
            emit avatarLoaded(pixmap);
            qDebug() << "Emitting avatarLoaded signal";

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

void UserProFile::on_pushButton_Save_released()
{
    // 获取当前登录用户名
    QString username = Login::currentUsername;

    // 获取呢称、性别、年龄、地址信息
    auto uname = ui->lineEdit_UnameEdit->text();
    auto gender = ui->comboBox_Gender->currentText();
    auto age = ui->spinBox_Age->value();
    auto region = ui->lineEdit_RegionEdit->text();

    qInfo() << "released" << username << uname << gender << age << region;

    // 用户名不能为空
    if (username.isEmpty())
    {
        QMessageBox::information(this, "提示", "用户名不能为空！", QMessageBox::Ok);
        return ;
    }

    // 昵称不能为空
    if (uname.isEmpty())
    {
        QMessageBox::information(this, "提示", "昵称不能为空！", QMessageBox::Ok);
        return ;
    }

    // 将头像路径转为 Base64 编码
    QString avatarBase64;
    if (!avatarPath.isEmpty())
    {
        QFile file(avatarPath);
        if (file.open(QIODevice::ReadOnly))
        {
            QByteArray imageData = file.readAll();

            // 将图片转换为 Base64 编码
            avatarBase64 = imageData.toBase64();
        }
        else
        {
            QMessageBox::information(this, "提示", "无法读取头像文件！", QMessageBox::Ok);
            return;
        }
    }

    // 构建 JSON 数据
    QJsonObject json;
    json["username"] = username;
    json["uname"] = uname;
    json["gender"] = gender;
    json["age"] = age;
    json["region"] = region;
    json["avatar"] = avatarBase64;


    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // 创建 QNetworkRequest，设置 Content-Type 头为 application/json
    QUrl url("http://localhost/api/profile");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 使用 POST 方法提交数据
    QNetworkReply *reply = m_manager->post(request, data);

    // 关联信号
    connect(reply, &QNetworkReply::finished, this, [=]()
    {
        QByteArray response = reply->readAll();
        qInfo() << QString::fromUtf8(response);

        // 根据返回的响应进行处理
        if (response.contains("success"))
        {
            QMessageBox::information(this, "提示", "修改成功！", QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this, "提示", "修改失败，请重试！", QMessageBox::Ok);
        }
    });

    // 头像保存成功后发出信号
    qInfo() << "Before emitting avatarUpdated signal with avatarBase64: ";
    emit avatarUpdated(avatarBase64);

    this->close();
}

void UserProFile::on_pushButton_Cancel_released()
{
    this->close();
}


void UserProFile::on_pushButton_Upload_released()
{
    // 弹出文件选择对话框，允许用户选择图片
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择头像"), "", tr("图片文件 (*.png *.jpg *.jpeg *.bmp *.gif)"));

    if (!fileName.isEmpty())
    {
        // 如果文件名不为空，加载选中的图片并显示在 label_ProFile 上
        avatarPath = fileName;
        QPixmap pixmap(fileName);

        if (pixmap.isNull())
        {
            // 如果图片加载失败，显示错误信息
            QMessageBox::warning(this, tr("加载失败"), tr("无法加载选中的图片"));
        }
        else
        {
            // 将图片缩放以适应 label_ProFile 的大小，保持比例
            ui->label_ProFile->setPixmap(pixmap.scaled(ui->label_ProFile->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
}


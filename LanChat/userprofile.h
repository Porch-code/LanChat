#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QDialog>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCloseEvent>
#include <QProcessEnvironment>
#include <QMessageBox>
#include <QUrl>
#include <QUrlQuery>
#include <QLabel>
#include <QFileDialog>
#include <QPixmap>
#include <QHttpMultiPart>
#include <QJsonObject>
#include <QJsonDocument>
#include <QSqlQuery>
#include <QFile>

namespace Ui {
class UserProFile;
}

class UserProFile : public QDialog
{
    Q_OBJECT

public:
    explicit UserProFile(QWidget *parent = nullptr);

    ~UserProFile();

    // 获取当前实例
    static UserProFile* getInstance(QWidget *parent = nullptr);

    // 加载当前用户数据
    void loadUserData();

    // 接收当前用户数据
    void onUserDataReceived();


protected:
    void showEvent(QShowEvent *event) override;

    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_pushButton_Save_released();

    void on_pushButton_Cancel_released();

    void on_pushButton_Upload_released();

private:
    Ui::UserProFile *ui;

    QNetworkAccessManager *m_manager;

    // 保存头像
    QString avatarPath;

    // 静态成员，保存当前实例
    static UserProFile* currentInstance;

signals:
    void avatarLoaded(const QPixmap &pixmap);

    void avatarUpdated(const QString &avatarBase64);
};

#endif // USERPROFILE_H

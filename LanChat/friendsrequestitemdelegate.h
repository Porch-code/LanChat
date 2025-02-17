#ifndef FRIENDSREQUESTITEMDELEGATE_H
#define FRIENDSREQUESTITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QPixmap>
#include <QFont>
#include <QPainterPath>


class FriendRequestItemDelegate :public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit FriendRequestItemDelegate(QObject *parent = nullptr);

    ~FriendRequestItemDelegate() override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // 接收好友请求的状态
    void setFriendRequestStatus(const QString &user_name_1, const QString &statusMessage);

public slots:
    // 接收 applyToAddFriendStatus 信号并更新界面
    void updateFriendRequestStatus(const QString &user_name_1, const QString &user_name_2, const QString &statusMessage);

private:
    QMap<QString, QString> m_friendStatusMap;  // 用来存储每个朋友的申请状态
};

#endif // FRIENDSREQUESTITEMDELEGATE_H

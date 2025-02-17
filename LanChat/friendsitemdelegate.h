#ifndef FRIENDSITEMDELEGATE_H
#define FRIENDSITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QPixmap>
#include <QFont>
#include <QPainterPath>

class FriendsItemDelegate :public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit FriendsItemDelegate(QObject *parent = nullptr);

    ~FriendsItemDelegate() override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // 接收好友请求的状态
    void setFriendRequestStatus(const QString &user_name_1, const QString &statusMessage);

private:
    QMap<QString, QString> m_friendStatusMap;  // 用来存储每个朋友的申请状态
};

#endif // FRIENDSITEMDELEGATE_H

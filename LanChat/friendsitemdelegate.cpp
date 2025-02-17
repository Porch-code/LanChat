#include "friendsitemdelegate.h"
#include "mainwidget.h"

FriendsItemDelegate::FriendsItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

FriendsItemDelegate::~FriendsItemDelegate()
{
}

void FriendsItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    // 设置项的矩形区域，增加内边距
    QRect rect = opt.rect.adjusted(5, 5, -5, 0);

    // 获取头像、名字、消息和日期
    QPixmap avatar = index.data(Qt::DecorationRole).value<QPixmap>();
    QString name = index.data(MainWidget::NameRole).toString();

    // 创建一个QPainterPath对象，用于绘制圆角矩形
    QPainterPath path;
    // QRectF rect(option.rect);                // 获取项的矩形区域

    // 设置圆角半径
    qreal radius = 10.0;

    // 绘制圆角矩形
    path.addRoundedRect(rect, radius, radius);

    // 绘制背景
    if (option.state & QStyle::State_Selected)
    {
        // 选中项的背景色

        // 启用抗锯齿
        painter->setRenderHint(QPainter::Antialiasing);

        // 填充圆角矩形
        painter->fillPath(path, QColor(229, 229, 229, 100));
    }

    if (option.state & QStyle::State_MouseOver) {
        // 悬浮项的背景色

        // 启用抗锯齿
        painter->setRenderHint(QPainter::Antialiasing);

        // 填充圆角矩形
        painter->fillPath(path, QColor(229, 229, 229, 100));
    }

    // 绘制头像
    QRect avatarRect(option.rect.x() + 15, option.rect.y() + 18, 40, 40);
    painter->drawPixmap(avatarRect, avatar.scaled(40, 40, Qt::KeepAspectRatio));

    // 绘制名字
    QFont nameFont = painter->font();
    nameFont.setPointSize(11);      // 设置字体大小
    painter->setFont(nameFont);     // 应用字体
    painter->setPen(Qt::black);     // 设置字体颜色为黑色
    painter->drawText(option.rect.x() + 65, option.rect.y() + 40, name);

}

QSize FriendsItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);  // 标记未使用的参数

    if (option.state & QStyle::State_Selected)
    {
        return QSize(220, 80); // 如果选中，设置更大的高度和宽度
    }
    else
    {
        return QSize(200, 70); // 默认大小
    }
}

void FriendsItemDelegate::setFriendRequestStatus(const QString &user_name_1, const QString &statusMessage)
{
    m_friendStatusMap[user_name_1] = statusMessage;  // 保存状态

}

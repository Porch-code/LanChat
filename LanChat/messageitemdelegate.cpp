#include "MessageItemDelegate.h"

MessageItemDelegate::MessageItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

MessageItemDelegate::~MessageItemDelegate()
{

}

void MessageItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    // 设置项的矩形区域，增加内边距
    QRect rect = opt.rect.adjusted(5, 5, -5, 0);

    // 获取头像、名字、消息和日期
    QPixmap avatar = index.data(Qt::DecorationRole).value<QPixmap>();
    QString name = index.data(Qt::DisplayRole).toString();
    QString lastMessage = index.data(Qt::UserRole + 1).toString();
    QString dateStr = index.data(Qt::UserRole + 2).toString();

    // 解析日期字符串
    QDateTime dateTime = QDateTime::fromString(dateStr, "yyyy-MM-dd HH:mm:ss");
    QString formattedDate;

    // 获取当前日期
    QDate currentDate = QDate::currentDate();

    // 判断是否是今天
    if (dateTime.isValid() && dateTime.date() == currentDate)
    {
        // 如果是今天，则只显示时间
        formattedDate = dateTime.toString("HH:mm");
    } else
    {
        // 如果不是今天，则显示月和日
        formattedDate = dateTime.toString("MM-dd");
    }

    // 创建一个QPainterPath对象，用于绘制圆角矩形
    QPainterPath path;

    // QRectF rect(option.rect);  // 获取项的矩形区域
    qreal radius = 10.0;       // 设置圆角半径
    path.addRoundedRect(rect, radius, radius);  // 绘制圆角矩形

    // 绘制背景
    if (option.state & QStyle::State_Selected)
    {
        // 选中项的背景色
        // 启用抗锯齿
        painter->setRenderHint(QPainter::Antialiasing);

        // 填充圆角矩形
        painter->fillPath(path, QColor(229, 229, 229, 100));
    }
    if (option.state & QStyle::State_MouseOver)
    {
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

    // 设置字体大小
    nameFont.setPointSize(11);

    // 应用字体
    painter->setFont(nameFont);

    // 设置字体颜色为黑色
    painter->setPen(Qt::black);

    painter->drawText(option.rect.x() + 65, option.rect.y() + 30, name);

    // 绘制上一条消息
    QFont messageFont = painter->font();
    messageFont.setBold(false);
    messageFont.setPointSize(10);
    painter->setFont(messageFont);

    // 设置字体颜色
    painter->setPen(QColor(128, 128, 128));

    // 定义最大宽度
    int maxWidth = 180;

    // 创建 QFontMetrics 对象，用来计算文字宽度
    QFontMetrics fm(messageFont);

    // 计算文字的宽度
    QString elidedText = fm.elidedText(lastMessage, Qt::ElideRight, maxWidth);

    // 绘制文字
    painter->drawText(option.rect.x() + 65, option.rect.y() + 55, elidedText);

    // 绘制日期（根据是否是当天显示不同格式）
    QFont DateFont = painter->font();
    DateFont.setBold(false);
    DateFont.setPointSize(10);
    painter->setFont(DateFont);
    painter->setPen(QColor(128, 128, 128));
    painter->drawText(option.rect.x() + 250, option.rect.y() + 45, formattedDate);

}

QSize MessageItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);  // 标记未使用的参数

    if (option.state & QStyle::State_Selected)
    {
        // 如果选中，设置更大的高度和宽度
        return QSize(220, 80);
    }
    else
    {
        // 默认大小
        return QSize(200, 70);
    }
}

#include "chatmessagedelegate.h"
#include "login.h"
#include <QStyle>

ChatMessageDelegate::ChatMessageDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void ChatMessageDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // 绘制背景
    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(option.rect, option.palette.highlight());
    }
    else
    {
        painter->fillRect(option.rect, option.palette.base());
    }

    // 获取消息数据
    QString message = index.data(Qt::DisplayRole).toString();

    // 解析消息，这里简单假设消息格式为 "[timestamp] sender: content"
    int timestampEnd = message.indexOf("]");
    QString timestamp = message.mid(1, timestampEnd - 1);
    int senderEnd = message.indexOf(":", timestampEnd + 2);
    QString sender = message.mid(timestampEnd + 2, senderEnd - timestampEnd - 2);
    QString content = message.mid(senderEnd + 2);

    // 解析日期字符串
    QDateTime dateTime = QDateTime::fromString(timestamp, "yyyy-MM-dd HH:mm:ss");
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
        formattedDate = dateTime.toString("yyyy年MM月dd日 HH:mm");
    }

    // 设置字体和颜色
    QFont font = painter->font();
    QPen pen = painter->pen();

    // 设置消息字体大小，这里设置为 12 磅
    int messageFontSize = 10;
    font.setPointSize(messageFontSize);

    // 如果是当前用户发送消息，则绘制靠右侧
    if (sender == Login::currentUsername)
    {
        // 绘制头像
        QIcon icon = index.data(Qt::DecorationRole).value<QIcon>();
        if (!icon.isNull())
        {
            // 定义头像的大小
            int iconSize = 32;

            // 计算头像的 x 坐标，使其靠最右侧
            int iconX = option.rect.x() + option.rect.width() - iconSize - 20;

            QRect iconRect(iconX, option.rect.y() + 35, iconSize, iconSize);
            icon.paint(painter, iconRect);
        }

        // 绘制时间戳
        painter->setFont(font);
        painter->setPen(Qt::white);
        QFontMetrics fm(font);
        QRect timestampTextRect = fm.boundingRect(formattedDate);
        timestampTextRect.moveTo(option.rect.x() + 240, option.rect.y() + 10);

        // 绘制时间戳的框
        QColor timestampBgColor = QColor(218, 218, 218); // 浅灰色
        painter->fillRect(timestampTextRect.adjusted(-4, -4, 4, 4), timestampBgColor);
        painter->setPen(Qt::white);
        painter->drawText(timestampTextRect, Qt::AlignLeft | Qt::AlignTop, formattedDate);


        // 绘制消息内容
        font.setBold(false);
        painter->setFont(font);
        painter->setPen(Qt::black);
        QFontMetrics fmContent(font);
        QRect contentTextRect = fmContent.boundingRect(content);

        // 计算消息内容的 x 坐标，使其在头像左侧
        int contentX = option.rect.x() + option.rect.width() - contentTextRect.width() - 70;
        contentTextRect.moveTo(contentX, option.rect.y() + 45);

        // 设置消息内容框的底色
        QColor contentBgColor = QColor(200, 230, 255); // 浅蓝色
        painter->fillRect(contentTextRect.adjusted(-9, -9, 9, 9), contentBgColor);

        painter->setPen(Qt::black);
        painter->drawText(contentTextRect, Qt::AlignLeft | Qt::AlignTop, content);
    }
    // 否则靠左侧绘制
    else
    {
        // 绘制头像
        QIcon icon = index.data(Qt::DecorationRole).value<QIcon>();
        if (!icon.isNull())
        {
            // 定义头像的大小
            int iconSize = 32;
            QRect iconRect(option.rect.x() + 15, option.rect.y() + 35, iconSize, iconSize);
            icon.paint(painter, iconRect);
        }

        // 绘制时间戳
        painter->setFont(font);
        painter->setPen(Qt::white);
        QFontMetrics fm(font);
        QRect timestampTextRect = fm.boundingRect(formattedDate);
        timestampTextRect.moveTo(option.rect.x() + 240, option.rect.y() + 10);

        // 绘制时间戳的框
        QColor timestampBgColor = QColor(218, 218, 218); // 浅灰色
        painter->fillRect(timestampTextRect.adjusted(-4, -4, 4, 4), timestampBgColor);
        painter->setPen(Qt::white);
        painter->drawText(timestampTextRect, Qt::AlignLeft | Qt::AlignTop, formattedDate);


        // 绘制消息内容
        font.setBold(false);
        painter->setFont(font);
        painter->setPen(Qt::black);
        QFontMetrics fmContent(font);
        QRect contentTextRect = fmContent.boundingRect(content);
        contentTextRect.moveTo(option.rect.x() + 65, option.rect.y() + 45);

        // 设置消息内容框的底色
        QColor contentBgColor = QColor(255, 255, 255); // 白色
        painter->fillRect(contentTextRect.adjusted(-9, -9, 9, 9), contentBgColor);

        painter->setPen(Qt::black);
        painter->drawText(contentTextRect, Qt::AlignLeft | Qt::AlignTop, content);
    }

    // 恢复原始字体和颜色
    painter->setFont(option.font);
    painter->setPen(pen);
}

QSize ChatMessageDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    // 简单设置项的高度为 80 像素，宽度使用视图的宽度
    return QSize(option.rect.width(), 80);
}

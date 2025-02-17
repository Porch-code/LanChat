#ifndef CHATMESSAGEDELEGATE_H
#define CHATMESSAGEDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QPixmap>
#include <QFont>
#include <QPainterPath>
#include <QDateTime>

class ChatMessageDelegate :public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit ChatMessageDelegate(QWidget *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
};

#endif // CHATMESSAGEDELEGATE_H

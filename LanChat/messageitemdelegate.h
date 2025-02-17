#ifndef MESSAGEITEMDELEGATE_H
#define MESSAGEITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QPixmap>
#include <QFont>
#include <QDateTime>
#include <QPainterPath>


class MessageItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit MessageItemDelegate(QObject *parent = nullptr);

    ~MessageItemDelegate() override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // MESSAGEITEMDELEGATE_H

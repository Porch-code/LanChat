#ifndef NONCLICKABLECHATMODEL_H
#define NONCLICKABLECHATMODEL_H

#include <QStandardItemModel>

class NonClickableChatModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit NonClickableChatModel(QObject *parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void appendRows(const QList<QStandardItem*> &items);
};

#endif // NONCLICKABLECHATMODEL_H

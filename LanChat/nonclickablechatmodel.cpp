#include "nonclickablechatmodel.h"

NonClickableChatModel::NonClickableChatModel(QObject *parent) : QStandardItemModel(parent)
{

}

Qt::ItemFlags NonClickableChatModel::flags(const QModelIndex &index) const
{
    // 获取默认的标志
    Qt::ItemFlags defaultFlags = QStandardItemModel::flags(index);

    // 移除可启用的标志，使项不可点击
    return defaultFlags & ~Qt::ItemIsEnabled;
}

void NonClickableChatModel::appendRows(const QList<QStandardItem*> &items)
{
    for (QStandardItem *item : items)
    {
        appendRow(item);
    }
}

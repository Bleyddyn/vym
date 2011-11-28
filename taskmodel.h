#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "task.h"

class BranchItem;

class TaskModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    TaskModel(QObject *parent=0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
//    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    bool setData(const QModelIndex &index, Task *t, int role=Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex(),Task *t=NULL);
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());

    Task* createTask (BranchItem *bi);
    void deleteTask (Task* t);
    void recalcPriorities();

private:
    QList <Task*> tasks;
};

#endif

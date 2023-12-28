#include "customtablemodel.h"

CustomTableModel::CustomTableModel(int rows, int columns, std::vector<ParamTest> m_data, QObject *parent)
    : QAbstractTableModel(parent), m_rows(rows), m_columns(columns), m_data(m_data) {

}


int CustomTableModel::rowCount(const QModelIndex &parent) const  {
    Q_UNUSED(parent);
    return m_rows;
}


int CustomTableModel::columnCount(const QModelIndex &parent) const  {
    Q_UNUSED(parent);
    return m_columns;
}


QVariant CustomTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        const ParamTest& item = m_data.at(index.column());
        switch (index.row())
        {
        case 0:
            return QString(item.month);
        case 1:
            return item.SunDays;
        case 2:
            return item.RainDays;
        case 3:
            return item.XrenDays;
        case 4:
            return item.HolyDays;
        default:
            return QVariant();
        }
    }

    return QVariant();
}


bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    ParamTest& item = m_data[index.column()];
    switch (index.row())
    {
    case 0:
        item.month = value.toString().toUtf8().constData();
        break;
    case 1:
        item.SunDays = value.toInt();
        break;
    case 2:
        item.RainDays = value.toInt();
        break;
    case 3:
        item.XrenDays = value.toInt();
        break;
    case 4:
        item.HolyDays = value.toInt();
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {Qt::EditRole});

    return true;
}


// связан с "emit dataChanged(index, index, {Qt::EditRole});"
Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

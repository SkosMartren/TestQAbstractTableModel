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
            return QString::fromStdString(item.month);
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

#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include <iostream>
#include <vector>

struct ParamTest
{
    const char* month;
    int SunDays;
    int RainDays;
    int XrenDays;
    int HolyDays;
};

// CustomTableModel используется в MainWindow::MainWindow для пробрасывания данных из UserTable в ui->tableView
class CustomTableModel : public QAbstractTableModel {

public:

    CustomTableModel(int rows, int columns, std::vector<ParamTest> m_data, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override ;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;


private:
    int m_rows;
    int m_columns;
    std::vector<ParamTest> m_data;
};


#endif // CUSTOMTABLEMODEL_H

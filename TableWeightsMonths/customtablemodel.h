#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include <vector>
#include <QDialog>
#include <string>

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

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;


    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    int m_rows;
    int m_columns;
    std::vector<ParamTest> m_data;
};


#endif // CUSTOMTABLEMODEL_H

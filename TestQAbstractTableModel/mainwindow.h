#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractTableModel>
#include <QVariant>
#include <QVector>
#include <QApplication>
#include <QTableView>
#include <QHeaderView>

#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// CustomTableModel используется в MainWindow::MainWindow для пробрасывания данных из UserTable в ui->tableView
class CustomTableModel : public QAbstractTableModel {

public:

    CustomTableModel(const QVector<QVector<QString>>& data, const QStringList& headers, QObject* parent = nullptr)
        : QAbstractTableModel(parent), m_data(data), m_headers(headers) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return m_data.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return m_headers.size();
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (!index.isValid())
            return QVariant();

        if (role == Qt::DisplayRole)
            return m_data[index.row()][index.column()];

        return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
            return m_headers.at(section);

        return QVariant();
    }

private:
    QVector<QVector<QString>> m_data;
    QStringList m_headers;
};

// используется для создания немодального окна в методе MainWindow::on_pushButtonShowInfo_clicked
class InfoDialog : public QDialog {
public:
    InfoDialog(QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("Справочная информация [Немодальное окно]");

        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *infoLabel = new QLabel("Как обговаривали на собеседовании: какая-то информация о месяцах", this);
        layout->addWidget(infoLabel);

        QPushButton *closeButton = new QPushButton("Закрыть", this);
        layout->addWidget(closeButton);

        connect(closeButton, &QPushButton::clicked, this, &InfoDialog::close);
    }
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAddColumn_clicked();

    void on_pushButtonShowInfo_clicked();

private:
    Ui::MainWindow *ui;
    CustomTableModel model; //  это необходимо, чтобы model разрушался вмместе с MainWindow, а не раньше
};
#endif // MAINWINDOW_H

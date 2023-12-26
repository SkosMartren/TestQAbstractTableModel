// mainwindow.h
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

#include "customtablemodel.h"
#include "ui_mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(int rows, int columns, std::vector<ParamTest> m_data, QWidget *parent = nullptr);
    ~MainWindow();


protected:
    // Обработка события изменения размера
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void on_AddColumn_clicked();

    void on_Info_clicked();

private:
    Ui::MainWindow* ui;
    CustomTableModel model; //  это необходимо, чтобы model разрушался вмместе с MainWindow, а не раньше
};
#endif // MAINWINDOW_H



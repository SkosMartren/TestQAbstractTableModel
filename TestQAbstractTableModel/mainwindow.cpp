#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      model({
                 {"January", "March", "June", "September"},
                 {"February", "April", "July", "October"},
                 {"December", "May", "August", "November"}
            },
            {"Winter", "Spring", "Summer", "Fall"}, this)
{
    ui->setupUi(this);

    ui->tableView->setModel(&model);

    // Устанавливаем размеры виджета таблицы
        ui->tableView->setMinimumSize(400, 300);
        ui->tableView->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAddColumn_clicked()
{
    QMessageBox::critical(this, "Ошибка [модальное окно]", "Произошла ошибка при добавлении столбца.");
}




void MainWindow::on_pushButtonShowInfo_clicked()
{
    InfoDialog *infoDialog = new InfoDialog(this);
    infoDialog->exec();  // Здесь используется exec для модального диалога, но можно также использовать show для немодального

}


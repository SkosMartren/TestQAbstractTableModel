// mainwindow.cpp
#include "mainwindow.h"
#include "infodialog.h"

MainWindow::MainWindow(int rows, int columns, std::vector<ParamTest> m_data, QWidget* parent)
    : QMainWindow(parent)
      ,ui(new Ui::MainWindow)
      ,model(rows, columns, m_data, this)
{
    ui->setupUi(this);
    ui->tableView->setModel(&model);
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::resizeEvent(QResizeEvent* event) {

    // https://stackoverflow.com/questions/18293403/columns-auto-resize-to-the-size-of-qtableview
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void MainWindow::on_AddColumn_clicked()
{
    QMessageBox::critical(this, "Ошибка [модальное окно]", "Произошла ошибка при добавлении столбца.");
}


void MainWindow::on_Info_clicked()
{
    InfoDialog *infoDialog = new InfoDialog(this);
    infoDialog->exec();  // Здесь используется exec для модального диалога, но можно также использовать show для немодального
}


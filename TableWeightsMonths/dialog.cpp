#include "dialog.h"
#include "ui_dialog.h"
#include "infodialog.h"

MyDialog::MyDialog(int rows, int columns, const std::vector<ParamTest>& m_data, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    ,model(rows, columns, m_data, this)
{
    ui->setupUi(this);
    ui->tableView->setModel(&model);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::resizeEvent(QResizeEvent* event) {

    // https://stackoverflow.com/questions/18293403/columns-auto-resize-to-the-size-of-qtableview
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}


void MyDialog::on_AddColumn_clicked()
{
    QMessageBox::critical(this, "Ошибка [модальное окно]", "Произошла ошибка при добавлении столбца.");
}


void MyDialog::on_Info_clicked()
{
    InfoDialog *infoDialog = new InfoDialog(this);

    // https://doc.qt.io/qt-6/qwidget.html#setAttribute
    // https://doc.qt.io/qt-6/qt.html#WidgetAttribute-enum
    infoDialog->setAttribute(Qt::WA_DeleteOnClose); // Установка флага

    infoDialog->show();
}


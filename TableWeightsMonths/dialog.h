#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "customtablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(int rows, int columns, const std::vector<ParamTest>& m_data, QWidget *parent = nullptr);
    ~MyDialog();

protected:

    // Обработка события изменения размера
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void on_AddColumn_clicked();

    void on_Info_clicked();

private:
    Ui::Dialog *ui;
    CustomTableModel model; //  это необходимо, чтобы model разрушался вмместе с MainWindow, а не раньше
};
#endif // DIALOG_H

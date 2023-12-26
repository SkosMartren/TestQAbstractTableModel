#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class InfoDialog : public QDialog
{
    Q_OBJECT
public:
    InfoDialog(QWidget *parent = nullptr);
};

#endif // INFODIALOG_H

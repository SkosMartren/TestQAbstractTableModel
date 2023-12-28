#include "infodialog.h"

InfoDialog::InfoDialog(QWidget *parent)
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

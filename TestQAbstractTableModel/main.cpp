#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow main;
    main.show();
    return app.exec();
}

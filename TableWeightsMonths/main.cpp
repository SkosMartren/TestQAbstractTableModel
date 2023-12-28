#include "dialog.h"

#include <QApplication>

std::vector<ParamTest> ParamTestArr2
{
  {"январь", 5, 10, 20, 3},
  {"февраль", 7, 20, 10, 5},
  {"март", 8, 15, 18, 4},
  {"апрель", 6, 12, 22, 2},
  {"май", 9, 8, 25, 1},
  {"июнь", 10, 5, 30, 2},
  {"июль", 12, 3, 28, 3},
  {"август", 11, 7, 15, 4},
  {"сентябрь", 8, 14, 20, 2},
  {"октябрь", 6, 18, 12, 3},
  {"ноябрь", 5, 22, 8, 1},
  {"декабрь", 7, 25, 5, 4}
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDialog w(5,12,  ParamTestArr2);
    w.show();
    return a.exec();
}

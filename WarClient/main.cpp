#include "WarClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WarClient w;
    w.show();
    return a.exec();
}

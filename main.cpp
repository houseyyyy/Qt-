#include "mainwindow.h"
#include <QApplication>
#include "gamemenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameMenu w;
    w.show();
    return a.exec();
}

#include "gameengine.h"
#include <QApplication>
#include "gamemenu.h"
#include <QMediaPlayer>
#include "QtSplashScreen.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QSplashScreen>
#include <QThread>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtSplashScreen  splash(QPixmap (":/pic/folder.jpg"));
      splash.setRange(0, 100);//进度条长度范围
      splash.show();
      for (int i = 0; i < 11; i++)
      {
          switch (i)
          {
          case 0:
              splash.showMessageText("Setting up the main window ...");
              break;

          case 1:
              splash.showMessageText("Loading xxxx ...");
              break;

          case 2:
              splash.showMessageText("Will show software UI ...");
              break;

          case 3:
              splash.showMessageText("Loading CUDA ...");
              break;

          case 4:
              splash.showMessageText("Loading  Server...");
              break;

          case 5:
              splash.showMessageText("Loading Engine ...");
              break;

          case 9:
              splash.showMessageText("Loading completed ...");
              break;
          }

          splash.updateNum(i*10);
          splash.repaint();
          QThread::msleep(500);
      }

    GameMenu w;
    splash.finish(&w);
    w.show();
    return a.exec();
}

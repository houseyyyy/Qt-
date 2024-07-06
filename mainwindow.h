#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Human.h"
#include <QTimer>
#include "server.h"
#include "client.h"

namespace Ui {
class MainWindow;
const int sizeOfRow = 1500;
const int sizeOfColumn = 1000;
const int LineY = 850;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void GameLoop1();
    void GameLoop2();
public:
    //登录
    void loadPlayer1(int port);
    void loadPlayer2(QString ip,QString port);
    // void StartGame();
    void GameInit();
    void sameLoop();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Human* player1;
    Human* player2;
    QPixmap background;
    //按键处理
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    //联机

    Server *server;
    Client *client;
private:
    Ui::MainWindow *ui;
    QTimer* mytime;
};

#endif // MAINWINDOW_H

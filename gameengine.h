#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QWidget>
#include "Human.h"
#include <QTimer>
#include "server.h"
#include "client.h"

namespace Ui {
class GameEngine;
const int sizeOfRow = 1500;
const int sizeOfColumn = 1000;
const int LineY = 850;
}

class GameEngine : public QWidget
{
    Q_OBJECT
private slots:
    void GameLoop1();
    void GameLoop2();
public:
    explicit GameEngine(QWidget *parent = nullptr);
    ~GameEngine();
    void paintEvent(QPaintEvent*);
    //登录
    void loadPlayer1(int port);
    void loadPlayer2(QString ip,QString port);

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
    Ui::GameEngine *ui;
    QTimer* mytime;
};

#endif // GAMEENGINE_H

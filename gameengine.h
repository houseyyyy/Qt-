#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QWidget>
#include "Human.h"
#include <QTimer>
#include <QMediaPlayer>
#include "server.h"
#include "client.h"

namespace Ui {
class GameEngine;
const int sizeOfRow = 1920;
const int sizeOfColumn = 1080;
const int LineY = 1000;
}

class GameEngine : public QWidget
{
    Q_OBJECT
private slots:
    void GameLoop1();
    void GameLoop2();
public:
    void gameover();
    explicit GameEngine(QWidget *parent = nullptr);
    ~GameEngine();
    void paintEvent(QPaintEvent*);
    //登录
    void loadPlayer1(int port);
    void loadPlayer2(QString ip,QString port);

    bool ischanged;
    Human* player1;
    Human* player2;
    QPixmap floor;
    QPixmap background;
    QPixmap lob1;
    QPixmap lifebar,blood;
    QMediaPlayer*lob=new QMediaPlayer(this);
    QMediaPlayer*bgm=new QMediaPlayer(this);
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

#include "gameengine.h"
#include "ui_gameengine.h"
#include <QPainter>
#include <QPen>
#include "Human.h"
#include <QKeyEvent>
#include "config.h"

GameEngine::GameEngine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameEngine)
{
    ui->setupUi(this);
}

GameEngine::~GameEngine()
{
    delete ui;
}
void GameEngine::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {

        //case Qt::Key_S:break;
        case Qt::Key_A:
        {


                player1->goleft = true;

            break;
        }
        case Qt::Key_D:
        {

                player1->goright = true;

            break;
        }
        case Qt::Key_Space:
        {
            //跳了零次或者跳了一次了
            if(player1->jump_counter < 2)
            {
                player1->jump_time.start();
                player1->fall_counter = 1;
                player1->jump_counter ++;
                break;
            }
        }
    }
}
void GameEngine::keyReleaseEvent(QKeyEvent* event)
{

    switch(event->key())
    {
        case Qt::Key_A:
        {
            player1->goleft = false;
            break;
        }
        case Qt::Key_D:
        {
            player1->goright= false;
            break;
        }
    }
}
//加载玩家一和玩家二
void GameEngine::loadPlayer2(QString ip,QString port)
{
    this->setWindowTitle("Player 2");
    client=new Client();
    client->Connect(ip,port);

    player2=new Human(1);
    player1=new Human(2);
    GameInit();

    //开启游戏主循环2
    mytime=new QTimer;
    connect(mytime,&QTimer::timeout,this,&GameEngine::GameLoop2);
    mytime->start();
}
void GameEngine::loadPlayer1(int port)
{
    this->setWindowTitle("Player 1");
    server=new Server();
    server->Connect(port);

    player2 = new Human(2);
    player1 = new Human(1);
    GameInit();

    //开启游戏主循环1
    mytime = new QTimer;
    connect(mytime,&QTimer::timeout,this,&GameEngine::GameLoop1);
    mytime->start();
}
//背景和线

void GameEngine::GameInit()
{

    QPen pen(QColor(166,156,242));
    QPainter painter(this);
     painter.setPen(pen);
    //画背景
    painter.drawPixmap(0,0,Ui::sizeOfRow,Ui::sizeOfColumn,background);
    pen.setWidth(10);
    //画线
    painter.drawLine(QPoint(0,Ui::LineY),QPoint(Ui::sizeOfRow,Ui::LineY));
    painter.end();

}
//玩家一主循环
void GameEngine::GameLoop1()
{
    server->sendData(player1->x,player1->y);
    player2->moveOther(server->x,server->y);
    sameLoop();
}
//玩家二主循环
void GameEngine::GameLoop2()
{
    client->sendData(player1->x,player1->y);
    player2->moveOther(client->x,client->y);
    sameLoop();
}
//通用循环
void GameEngine::sameLoop()
{

    update();
    player1->jump();
    player1->move();

    QPen pen(QColor(166,156,242));
    QPainter painter(this);
     painter.setPen(pen);
    //画背景
    painter.drawPixmap(0,0,Ui::sizeOfRow,Ui::sizeOfColumn,background);
    pen.setWidth(10);
    //画线
    painter.drawLine(QPoint(0,Ui::LineY),QPoint(Ui::sizeOfRow,Ui::LineY));
    //画人物---
    painter.drawPixmap(player1->x,player1->y,player1->height,player1->length,player1->human);

    //血条框
    pen.setWidth(2);
    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.drawRect(player1->lifebar);
    //画血条
    pen.setColor(QColor(255,0,0));
    painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
    painter.drawRect(player1->blood);

    painter.end();


}

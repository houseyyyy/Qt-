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
    resize(Ui::sizeOfRow,Ui::sizeOfColumn);
    background.load(":/background.jpg");
}

GameEngine::~GameEngine()
{
    delete ui;
}
void GameEngine::paintEvent(QPaintEvent*)
{

    player1->jump();
    player1->move();
    player1->attack(player2,KIND_NORMAL);
    player1->attack(player2,KIND_SKILL);
    player1->attack(player2,KIND_BIG);

    QPen pen(QColor(166,156,242));
    QPainter painter(this);
     painter.setPen(pen);
    //画背景
    painter.drawPixmap(0,0,Ui::sizeOfRow,Ui::sizeOfColumn,background);
    pen.setWidth(10);
    //画线
    painter.drawLine(QPoint(0,Ui::LineY),QPoint(Ui::sizeOfRow,Ui::LineY));
    //画人物---
    painter.drawPixmap(player1->x,player1->y,player1->height,player1->length,player1->getImg());
    painter.drawPixmap(player2->x,player2->y,player2->height,player2->length,player2->human);

/*  //血条框
    pen.setWidth(2);
    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.drawRect(player1->lifebar);
    //画血条
    pen.setColor(QColor(255,0,0));
    painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
    painter.drawRect(player1->blood);
*/

    painter.end();
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
            break;
        }
        //以下是玩家技能按键  J x轴大的攻击  K 技能  L 瞬移  S 防御  I 大招
        case Qt::Key_J:
        {
            player1->normal_attacking_time.start();
            break;
        }
        case Qt::Key_K:
        {
            player1->skill_attacking_time.start();
            break;
        }
        case Qt::Key_I:
        {
            player1->big_attacking_time.start();
            break;
        }
        case Qt::Key_S:
        {
            player1->defence();
            break;
        }
        case Qt::Key_L:
        {
            //待做
            /*if(player1->left==true)
            {
                player1->x-=100;//距离乱写的
            }
            else if(player1->right==true)
            {
                player1->x+=100;
            }*/
            break;
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
            player1->goright = false;
            break;
        }
        case Qt::Key_S:
        {
            player1->isdefence = false;
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
    //GameInit();
    update();
    //开启游戏主循环2
    mytime=new QTimer;
    mytime->setInterval(GAME_RATE);
    connect(mytime,&QTimer::timeout,this,&GameEngine::GameLoop2);
    mytime->start();
}
void GameEngine::loadPlayer1(int port)
{
    this->setWindowTitle("Player 1");
    server=new Server;
    server->Connect(port);

    player2 = new Human(2);
    player1 = new Human(1);
    //update();
    //开启游戏主循环1
    mytime = new QTimer;
    mytime->setInterval(GAME_RATE);
    connect(mytime,&QTimer::timeout,this,&GameEngine::GameLoop1);
    mytime->start();
}
//背景和线

//玩家一主循环
void GameEngine::GameLoop1()
{
    server->sendData(player1->x,player1->y);
    /*player1->manbox.setbox(player1->x,player1->y,player1->x+HUMAN_LENGTH,player1->y+HUMAN_HEIGHT);
    player2->manbox.setbox(server->x,server->y,server->x+HUMAN_LENGTH,server->y+HUMAN_HEIGHT);
    if(player1->left==true)
    {
        player1->Jrange.setbox(player1->x-100,player1->y,player1->x,player1->y);
        player1->Krange.setbox(player1->x-100,player1->y,player1->x,player1->y);
        player1->Irange.setbox(player1->x-100,player1->y,player1->x,player1->y);;//朝左时人物的攻击范围，我先给你随便写个范围
    }
    else if(player1->right==true)
    {
        player1->Jrange.setbox(player1->x,player1->y,player1->x+100,player1->y);
        player1->Krange.setbox(player1->x,player1->y,player1->x+100,player1->y);
        player1->Irange.setbox(player1->x,player1->y,player1->x+100,player1->y);;//朝右时人物的攻击范围，我先给你随便写个范围
    }*/
    player2->moveOther(server->x,server->y);
    update();
}
//玩家二主循环
void GameEngine::GameLoop2()
{
    client->sendData(player1->x,player1->y);
    player2->moveOther(client->x,client->y);
    //qDebug() << client->x << client->y;
    update();
}

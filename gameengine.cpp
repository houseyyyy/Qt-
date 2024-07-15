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
    background.load(":/pic/background.jpg");
    lob1.load(":/pic/lob.png");
    floor.load(":/pic/floor.png");
    lifebar.load(":/pic/lifebar.png");
    bgm->setMedia(QUrl("qrc:/audio/audio/bgm/1.mp3"));//设置音乐的资源文件
    bgm->setVolume(50);//音量
    lob->setMedia(QUrl("qrc:/audio/audio/bgm/lob.mp3"));//设置音乐的资源文件
    lob->setVolume(50);//音量
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
    player1->changebox1();

    if(player2->remainblood<= 0||player1->remainblood<=0)gameover();
    QPen pen(QColor(166,156,242));
    QPainter painter(this);
     painter.setPen(pen);
    //画背景
    painter.drawPixmap(0,0,Ui::sizeOfRow,Ui::sizeOfColumn,background);
    painter.drawPixmap(0,1000,Ui::sizeOfRow,400,floor);
    pen.setWidth(10);
    //画线
    //画人物---
    if(ischanged==false)
    {
        painter.drawPixmap(player1->x - player1->px,player1->y - player1->py,player1->height,player1->length,player1->getImg1());
        painter.drawPixmap(player2->x - player2->px,player2->y - player2->py,player2->height,player2->length,player2->getImg2());
    }
    else
    {
        painter.drawPixmap(player1->x - player1->px,player1->y - player1->py,player1->height,player1->length,player1->getImg2());
        painter.drawPixmap(player2->x - player2->px,player2->y - player2->py,player2->height,player2->length,player2->getImg1());
    }

    //血条框
    pen.setWidth(2);
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.drawRect(player1->lifebar);
    painter.drawRect(player2->lifebar);
    painter.drawPixmap(0,50,500,50,lifebar);
    painter.drawPixmap(1420,50,500,50,lifebar);

    //画血条
    pen.setColor(QColor(82,82,82));
    painter.setBrush(QBrush(QColor(135,135,135,80)));
    painter.setBrush(QBrush(Qt::Dense3Pattern));
   // player1-> blood.setRect(0,55,player2->remainblood*5,40);
   // player2-> blood.setRect(1920-player1->remainblood*5,55,player1->remainblood*5,40);
    if(ischanged==false)
    {
        player1-> blood.setRect(0,55,player2->remainblood*5,40);
        player2-> blood.setRect(1920-player1->remainblood*5,55,player1->remainblood*5,40);
    }
    else
    {
        player2-> blood.setRect(0,55,player1->remainblood*5,40);
        player1-> blood.setRect(1920-player2->remainblood*5,55,player2->remainblood*5,40);
    }

    painter.drawRect(player1->blood);
    painter.drawRect(player2->blood);

    painter.end();
}
void GameEngine::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
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
    ischanged=true;
    this->setWindowTitle("Player 2");
    client=new Client();
    client->Connect(ip,port);
    bgm->play();
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
    ischanged=false;
    bgm->play();
    this->setWindowTitle("Player 1");
    server=new Server;
    server->Connect(port);

    player2 = new Human(2);
    player1 = new Human(1);
    //开启游戏主循环1
    mytime = new QTimer;
    mytime->setInterval(GAME_RATE);
    connect(mytime,&QTimer::timeout,this,&GameEngine::GameLoop1);
    mytime->start();
}

//玩家一主循环
void GameEngine::GameLoop1()
{
    server->sendData(player1);
    if(server->isConnected)
    {
    player2->setOtherplayer(server->player);
    //player1->remainblood =server->player->remainblood;
    }
    update();
}
//玩家二主循环
void GameEngine::GameLoop2()
{
    client->sendData(player1);
    player2->setOtherplayer(client->player);
   // player1->remainblood =client->player->remainblood;
    update();
}

void GameEngine::gameover()
{
    QWidget* over = new QWidget;
    bgm->stop();
    lob->play();
    over->resize(1288,798);
    over->setStyleSheet("border-image:url(:/pic/lob.png)");
    this->hide();
    over->show();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPen>
#include "human.h"
#include <QKeyEvent>
#include "config.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(Ui::sizeOfRow,Ui::sizeOfColumn);
    this->setWindowTitle("超级牛马");
    background.load(":/background.jpg");
    mytime.setInterval(GAME_RATE);
    connect(&mytime,&QTimer::timeout,[this]()
    {
        update();
        man.jump();
        man.move();
    });
    mytime.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPen pen(QColor(166,156,242));
    pen.setWidth(10);
    QPainter painter(this);
    painter.drawPixmap(0,0,Ui::sizeOfRow,Ui::sizeOfColumn,background);
    painter.setPen(pen);
    painter.drawLine(QPoint(0,Ui::LineY),QPoint(Ui::sizeOfRow,Ui::LineY));
    painter.drawPixmap(man.x,man.y,man.height,man.length,man.human);

    pen.setWidth(2);
    pen.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.drawRect(man.lifebar);

    pen.setColor(QColor(255,0,0));
    painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
    painter.drawRect(man.blood);
    painter.end();
}
void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {

        //case Qt::Key_S:break;
        case Qt::Key_A:
        {


                man.goleft = true;

            break;
        }
        case Qt::Key_D:
        {

                man.goright = true;

            break;
        }
        case Qt::Key_Space:
        {
            //跳了零次或者跳了一次了
            if(man.jump_counter < 2)
            {
                man.jump_time.start();
                man.fall_counter = 1;
                man.jump_counter ++;
                break;
            }
        }
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent* event)
{

    switch(event->key())
    {
        case Qt::Key_A:
        {
            man.goleft = false;
            break;
        }
        case Qt::Key_D:
        {
            man.goright= false;
            break;
        }
    }
}

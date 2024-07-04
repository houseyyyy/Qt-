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
    painter.setPen(pen);
    painter.drawLine(QPoint(0,Ui::LineY),QPoint(Ui::sizeOfRow,Ui::LineY));
    painter.drawPixmap(man.x,man.y,man.height,man.length,man.human);
    painter.end();
}
void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        case Qt::Key_S:man.goleft = false;man.goright = false;man.stop = true;break;
        case Qt::Key_A:man.goleft = true;man.goright = false;man.stop = false;break;
        case Qt::Key_D:man.goleft = false;man.goright = true;man.stop = false;break;
        case Qt::Key_Space:
        {
            man.jump_time.start();
            man.fall_counter = 1;
            break;
        }

    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(Ui::sizeOfRow,Ui::sizeOfColumn);
    this->setWindowTitle("超级牛马");
    //QPainter painterline(this);
    //painterline.drawLine(QPoint(0,0),QPoint(100,100));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painterline(this);
    painterline.drawLine(QPoint(0,850),QPoint(1500,850));
}

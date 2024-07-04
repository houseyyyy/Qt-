#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "human.h"
#include <QTimer>
namespace Ui {
class MainWindow;
const int sizeOfRow = 1500;
const int sizeOfColumn = 1000;
const int LineY = 850;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent*);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //按键处理
    QTimer mytime;
    void keyPressEvent(QKeyEvent*);
    Human man;
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

#ifndef HUMAN_H
#define HUMAN_H
#include <QPixmap>
#include <QTimer>
#include <QTime>

class Human
{
public:
    QPixmap human;
    Human();
    bool goleft;
    bool goright;
    bool stop;
    QTimer move_time; //移动计时器
    QTimer jump_time; //跳跃计时器
    int fall_counter; // 下落逐差法
    int x; // x坐标
    int y; // y坐标
    int length; //小人横向长度
    int height; //小人纵向长度
    void move(); //移动函数
    int moveSize;
    void jump(); // 人物跳越
    bool jump_once;        //已经跳跃一次
    bool jump_twice;       //已经跳跃两次
};

#endif // HUMAN_H

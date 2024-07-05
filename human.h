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
    QTimer jump_time; //跳跃计时器
    int fall_counter; // 下落逐差法的N
    int x; // x坐标
    int y; // y坐标
    int length; //小人横向长度
    int height; //小人纵向长度
    void move(); //移动函数
    void jump(); // 人物跳越
    int jump_counter;//记录已经跳跃次数
    bool goleft;
    bool goright;
};

#endif // HUMAN_H

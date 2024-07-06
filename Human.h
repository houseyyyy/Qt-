#ifndef HUMAN_H
#define HUMAN_H
#include <QPixmap>
#include <QTimer>
#include <QTime>

class Human
{
public:
    //创建玩家1和2的角色
    void loadHuman1();
    void loadHuman2();

    QPixmap human;
    Human(int);
    QTimer jump_time; //跳跃计时器
    int fall_counter; // 下落逐差法的N
    int x; // x坐标
    int y; // y坐标
    int length; //小人横向长度
    int height; //小人纵向长度
    int jump_counter;//记录已经跳跃次数
    bool goleft;
    bool goright;
    QRect lifebar; //血条的边框
    QRect blood; // 血条
    void move(); //移动函数
    void moveOther(int ,int );
    void jump(); // 人物跳越
    int remainblood;//剩余的血量
};

#endif // HUMAN_H

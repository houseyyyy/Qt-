#ifndef HUMAN_H
#define HUMAN_H
#include <QPixmap>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QMovie>
#include"box.h"
class Human
{
public:
    //创建玩家1和2的角色
    void loadHuman1();
    void loadHuman2();

    QPixmap human;
    QPixmap humanR,humanL,WalkR[40],WalkL[40],jumpstL[8],jumpstR[8],jumpL,jumpR;
    Human(int);
    QTimer jump_time; //跳跃计时器
    QPixmap getImg();//获得当前状态图片
    int fall_counter; // 下落逐差法的N
    int current=0;//当前图片帧数
    int framecontrol=0;//控制帧速度
    int x; // x坐标
    int y; // y坐标
    int length; //小人横向长度
    int height; //小人纵向长度
    int jump_counter;//记录已经跳跃次数
    bool goleft;
    bool goright;
    bool left;
    bool right;
    bool isjumping;
    QRect lifebar; //血条的边框
    QRect blood; // 血条
    void move(); //移动函数

    void moveOther(int ,int );
    void jump(); // 人物跳越
    int remainblood;//剩余的血量
    Box manbox;//人物碰撞箱
    Box Jrange;//J攻击的范围
    Box Krange;//K攻击的范围
    Box Irange;//I攻击的范围


    bool isnormal_attacking;//是否在普通攻击
    QTimer normal_attacking_time;//普通攻击动画放的总时间
    bool isskill_attacking;//是否在放技能
    QTimer skill_attacking_time;//技能时间
    bool isbig_attacking; //是否在放大
    QTimer big_attacking_time;
    bool isdefence; //是否防御

    void attack(Human*,int); //攻击 int 表示攻击类型
    void defence(); //防御函数
};

#endif // HUMAN_H

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

    int x; // x坐标
    int y; // y坐标
    bool goleft;
    bool goright;
    bool left;
    bool right;

    bool isjumping;
    bool isnormal_attacking;//是否在普通攻击
    bool isskill_attacking;//是否在放技能
    bool isbig_attacking; //是否在放大招
    bool isdefence; //是否防御

    Box manbox;//人物碰撞箱
    Box Jrange;
    Box Krange;
    Box Irange;

    int current;//当前图片帧数
    int currentA[3];
    int framecontrolA[3];
    int framecontrol;//控制帧速度
    int px,py;//绘图偏移
    QTimer jump_time; //跳跃计时器
    int remainblood;//对方剩余的血量
    QRect blood; // 血条
    QRect lifebar; //血条的边框
    QTimer normal_attacking_time;//普通攻击动画放的总时间
    QTimer skill_attacking_time;//技能时间
    QTimer big_attacking_time;
    void attack(Human*,int); //攻击 int 表示攻击类型
    void defence(); //防御函数
    void move(); //移动函数
    void setOtherplayer(Human*);
    void jump(); // 人物跳越
    //创建玩家1和2的角色
    void loadHuman1();
    void loadHuman2();
    bool isnormalhurt;
    bool isskillhurt;
    bool isbighurt;
    QPixmap human;
    QPixmap humanR,humanL,WalkR[11],WalkL[11],jumpL,jumpR,evadeL,evadeR,blockL,blockR;//
    QPixmap JL[11],JR[11],KL[6],KR[6],IL[32],IR[32];//
    int fall_counter; // 下落逐差法的N
    int length; //小人横向长度
    int height; //小人纵向长度
    int jump_counter;//记录已经跳跃次数
    Human(int);
    Human();
    QPixmap getImg1();//获得当前状态图片
    QPixmap getImg2();//获得当前状态图片

    void changebox1();//改变碰撞箱1
    void changebox2();//改变碰撞箱2
};

#endif // HUMAN_H

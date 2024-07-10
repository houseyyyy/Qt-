#include "Human.h"
#include "config.h"
#include "gameengine.h"
#include"box.h"
#include <QDebug>
Human::Human(int Num){
    height = 100;
    length = 100;
    remainblood = 100;
    goleft = false;
    goright = false;

    jump_time.setInterval(JUMP_DURATION);
    jump_time.setSingleShot(true);
    jump_counter = 0;
    isjumping=false;

    normal_attacking_time.setInterval(NORMAL_ATTACK_DURATION);
    normal_attacking_time.setSingleShot(true);
    isnormal_attacking = false;

    skill_attacking_time.setInterval(SKILL_ATTACK_DURATION);
    skill_attacking_time.setSingleShot(true);
    isskill_attacking = false;

    big_attacking_time.setInterval(BIG_ATTACK_DURATION);
    big_attacking_time.setSingleShot(true);
    isbig_attacking = false;

    isdefence = false;

    if(Num == 1)loadHuman1();
    else if(Num == 2) loadHuman2();

}
void Human::moveOther(int X,int Y)
{
    x = X;
    y = Y;
}
//设置玩家一的角色
void Human::loadHuman1()
{
    x = 500;
    y = 750;
    manbox.setbox(x,y,x+HUMAN_LENGTH,y+HUMAN_HEIGHT);//不知道hsy宽高有没有写反
    left=false;
    right=true;
    //人物图片---
    humanR.load(":/pic/esther/daijiyou.png");
    humanL.load(":/pic/esther/daijizuo.png");
    for(int i=0;i<40;i++){
        WalkL[i].load(QString(":/Anime/EWalkL/walk1_%1%2.png").arg(i/10).arg(i%10));
    }
    for(int i=0;i<40;i++){
        WalkR[i].load(QString(":/Anime/EWalkR/walk1_%1%2.png").arg(i/10).arg(i%10));
    }
    for(int i=0;i<8;i++)
    {
        jumpstL[i].load(QString(":/Anime/jumpL/jump_%1%2.png").arg(i/10).arg(i%10));
    }
    for(int i=0;i<8;i++)
    {
        jumpstR[i].load(QString(":/Anime/jumpR/jump_%1%2.png").arg(i/10).arg(i%10));
    }
    jumpL.load(":/Anime/jumpL/jump_08.png");
    jumpR.load(":/Anime/jumpR/jump_08.png");

    //血条
    /*lifebar.setRect(LIFEBAR_X,LIFEBAR_Y,LIFEBAR_LENGTH,LIFEBAR_HEIGHT);
    blood.setRect(LIFEBAR_X,LIFEBAR_Y,LIFEBAR_LENGTH,LIFEBAR_HEIGHT);*/
}
//设置玩家二的角色
void Human::loadHuman2()
{
    x = 400;
    y = 750;
    //人物图片---
    human.load(":/human2.png");
    //血条
    /*lifebar.setRect(LIFEBAR_X,LIFEBAR_Y,LIFEBAR_LENGTH,LIFEBAR_HEIGHT);
    blood.setRect(LIFEBAR_X,LIFEBAR_Y,LIFEBAR_LENGTH,LIFEBAR_HEIGHT);*/
}
void Human::jump()
{
    if(isdefence)
    {
        jump_time.stop();
        return;
    }
    if(jump_time.isActive()){
        y-=jump_time.remainingTime()/45;
        isjumping = true;
    }
    else{

        if(y + GAME_ACCELERATION * GAME_RATE * GAME_RATE * fall_counter< Ui::LineY - height)
        {
            y += GAME_ACCELERATION * GAME_RATE * GAME_RATE * fall_counter ++;
        }
        else
        {
            isjumping=false;
            y = Ui::LineY - height;
            fall_counter = 1;
            jump_counter = 0;
        }

    }
}
void Human::move()
{
    if(isdefence == true)
    {
        if(!(goleft&&goright))
        {
            if(goleft && !goright)left = true;
            if(!goleft && goright)right = true;
        }
        else
        {
            goleft = false;
            goright = false;
        }
        return;
    }
    if(goleft == true && goright == true)
    {
        return ;
    }
    if(goleft == true)
    {
        x -= MOVE_SIZE;
        framecontrol++;
        framecontrol=framecontrol%3;
        if(framecontrol==2)
        {
            current++;
            current=current%40;
        }
        left=true;
        right=false;
    }
    else if(goright == true)
    {
        x += MOVE_SIZE;
        framecontrol++;
        framecontrol=framecontrol%3;
        if(framecontrol==2)
        {
            current++;
            current=current%40;
        }
        right=true;
        left=false;
    }
}
QPixmap Human::getImg()
{
    if(isjumping==false)
    {
        if(goleft==false&&goright==false&&left==true&&right==false)
            return humanL;
        if(goleft==false&&goright==false&&left==false&&right==true)
            return humanR;
        if(goleft==true&&goright==false)
            return WalkL[current];
        if(goleft==false&&goright==true)
            return WalkR[current];
        else
            return humanL;
    }
    else
    {
        if(goleft==true&&goright==false)
            return jumpL;
        if(goleft==false&&goright==true)
            return jumpR;
        else
            return jumpL;
    }
    //human 类里有isnormal_attacking,isskill_attacking来判断状态，根据这个你去绑定动画
}
//防御
void Human::defence()
{
    if(!isjumping && !isnormal_attacking && !isskill_attacking && !isbig_attacking)
    {
        isdefence = true;
    }
}
// 攻击
void Human::attack(Human* player2,int kind)
{
    if(kind == KIND_NORMAL)
    {
        //只在普攻动画时间内
        if(normal_attacking_time.isActive() && !skill_attacking_time.isActive() && !big_attacking_time.isActive())
        {
            isnormal_attacking = true;
            if(Jrange.iscollided(player2->x,player2->y,player2->x+HUMAN_LENGTH,player2->y+HUMAN_HEIGHT) && !player2->isdefence)
            {
                player2->remainblood -= 10;
            }
        }
        else
        {
            isnormal_attacking =  false;
        }
    }
    else if(kind == KIND_SKILL)
    {
        //只在技能动画时间内
        if(!normal_attacking_time.isActive() && skill_attacking_time.isActive() && !big_attacking_time.isActive())
        {
            isskill_attacking = true;
            //可以改范围来改碰撞
            if(Krange.iscollided(player2->x,player2->y,player2->x+HUMAN_LENGTH,player2->y+HUMAN_HEIGHT) && !player2->isdefence)
            {
                player2->remainblood -= 20;
            }
        }
        else
        {
            isskill_attacking = false;
        }
    }
    else if(kind == KIND_BIG)
    {
        if(!normal_attacking_time.isActive() && !skill_attacking_time.isActive() && big_attacking_time.isActive())
        {
            isbig_attacking = true;
            if(Irange.iscollided(player2->x,player2->y,player2->x+HUMAN_LENGTH,player2->y+HUMAN_HEIGHT))
            {
                player2->remainblood -= 50;
            }
        }
        else
        {
            isbig_attacking = false;
        }
    }
}

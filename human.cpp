#include "Human.h"
#include "config.h"
#include "gameengine.h"
#include <QDebug>
Human::Human(int Num){
    height = 100;
    length = 100; 
    jump_time.setInterval(JUMP_DURATION);
    jump_time.setSingleShot(true);
    jump_counter = 0;
    goleft = false;
    goright = false;
    if(Num == 1)loadHuman1();
    else loadHuman2();

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
    //人物图片---
    human.load(":/human1.png");
    //血条
    lifebar.setRect(LIFEBAR_X,LIFEBAR_Y,LIFEBAR_LENGTH,LIFEBAR_HEIGHT);
    blood.setRect(LIFEBAR_X,LIFEBAR_Y,LIFEBAR_LENGTH,LIFEBAR_HEIGHT);
}
//设置玩家二的角色
void Human::loadHuman2()
{
    x = 500;
    y = 750;
    //人物图片---
    human.load(":/human2.png");
    //血条
    lifebar.setRect(LIFEBAR_X,LIFEBAR_Y,LIFEBAR_LENGTH,LIFEBAR_HEIGHT);
    blood.setRect(LIFEBAR_X,LIFEBAR_Y,LIFEBAR_LENGTH,LIFEBAR_HEIGHT);
}
void Human::jump()
{
    if(jump_time.isActive()){
        y-=jump_time.remainingTime()/45;
    }
    else{

        if(y + GAME_ACCELERATION * GAME_RATE * GAME_RATE * fall_counter< Ui::LineY - height)
        {
            y += GAME_ACCELERATION * GAME_RATE * GAME_RATE * fall_counter ++;
        }
        else
        {
            y = Ui::LineY - height;
            fall_counter = 1;
            jump_counter = 0;
        }

    }
}
void Human::move()
{
    if(goleft == true && goright == true)
    {
        return ;
    }
    if(goleft == true)x -= MOVE_SIZE;
    else if(goright == true)x += MOVE_SIZE;
}

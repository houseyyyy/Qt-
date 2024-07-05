#include "human.h"
#include "config.h"
#include "mainwindow.h"
#include <QDebug>
Human::Human(){
    x = 500;
    y = 750;
    height = 100;
    length = 100;
    human.load(":/human1.png");
    jump_time.setInterval(JUMP_DURATION);
    jump_time.setSingleShot(true);
    jump_counter = 0;
    goleft = false;
    goright = false;
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

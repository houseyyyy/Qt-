#include "human.h"
#include "config.h"
#include "mainwindow.h"
#include <QDebug>
Human::Human(){
    goleft = false;
    goright = false;
    stop = true;
    x = 500;
    y = 750;
    moveSize = 4;
    height = 100;
    length = 100;
    human.load(":/human1.png");
    jump_time.setInterval(JUMP_DURATION);
    jump_time.setSingleShot(true);
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
        }

    }
}
void Human::move()
{
    if(goleft == true)
    {
        x -= moveSize;
    }
    else if(goright == true)
    {
        x += moveSize;
    }
}

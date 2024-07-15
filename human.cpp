#include "Human.h"
#include "config.h"
#include "gameengine.h"
#include"box.h"
#include <QDebug>
Human::Human(int Num)
{
    isnormalhurt = false;
    isskillhurt = false;
    isbighurt = false;
    for(int i = 0;i < 3;i++)
    {
        currentA[i] = 0;
        if(!i)framecontrolA[i] = -1;
        else framecontrolA[i] = 0;
    }
    framecontrol = 0;
    current = 0;
    px = 0;
    py = 0;
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
Human::Human(){
    goleft = false;
    goright = false;
    isjumping=false;
    isbig_attacking = false;
    isdefence = false;
    isskill_attacking = false;
    isnormal_attacking = false;
}
//设置玩家一的角色
void Human::loadHuman1()
{
    height = 130;
    length = 175;
    x = 500;
    y = 900;
    //manbox.setbox(x,y,x+HUMAN_LENGTH,y+HUMAN_HEIGHT);//不知道hsy宽高有没有写反
    left=false;
    right=true;
    //人物图片---
    humanR.load(":/pic/esther/daijiyou.png");
    humanL.load(":/pic/esther/daijizuo.png");
    blockL.load(":/pic/esther/blockL.png");
    blockR.load(":/pic/esther/blockR.png");
    for(int i=0;i<11;i++){
        JL[i].load(QString(":/Anime/tuciL/tuci_%1%2.png").arg(i/10).arg(i%10));
        JR[i].load(QString(":/Anime/tuciR/tuci_%1%2.png").arg(i/10).arg(i%10));
    }
    for(int i=0;i<11;i++)
    {
        WalkL[i].load(QString(":/Anime/EWalkL/walk1_%1%2.png").arg(i/10).arg(i%10));
        WalkR[i].load(QString(":/Anime/EWalkR/walk1_%1%2.png").arg(i/10).arg(i%10));
    }
    for(int i=0;i<6;i++)
    {
        KL[i].load(QString(":/Anime/zhanjiL/zhanji_%1%2.png").arg(i/10).arg(i%10));
        KR[i].load(QString(":/Anime/zhanjiR/zhanji_%1%2.png").arg(i/10).arg(i%10));
    }
    for(int i=0;i<32;i++)
    {
        IL[i].load(QString(":/Anime/daL/da_%1%2.png").arg(i/10).arg(i%10));
        IR[i].load(QString(":/Anime/daR/da_%1%2.png").arg(i/10).arg(i%10));
    }
    jumpL.load(":/Anime/jumpL/jump_08.png");
    jumpR.load(":/Anime/jumpR/jump_08.png");

    //血条
    lifebar.setRect(0,50,500,50);
    blood.setRect(0,50,remainblood*5,50);//最后再改成宏
}
//设置玩家二的角色
void Human::loadHuman2()
{
    height = 260;
    length = 200;
    x = 1400;
    y = 900;
    left=true;
    right=false;
    //manbox.setbox(x,y,x+HUMAN_LENGTH,y+HUMAN_HEIGHT);//不知道hsy宽高有没有写反
    humanR.load(":/pic/nicolai/nicolaiR.png");
    humanL.load(":/pic/nicolai/nicolaiL.png");
    blockL.load(":/pic/nicolai/blockL.png");
    blockR.load(":/pic/nicolai/blockR.png");
    for(int i=0;i<11;i++){
        JL[i].load(":/pic/nicolai/tuciL.png");
        JR[i].load(":/pic/nicolai/tuciR.png");
    }
    for(int i=0;i<11;i++)
    {
        WalkL[i].load(QString(":/Anime/nico/WalkL/walk_%1%2.png").arg(i/10).arg(i%10));
        WalkR[i].load(QString(":/Anime/nico/WalkR/walk_%1%2.png").arg(i/10).arg(i%10));
    }
    for(int i=0;i<6;i++)
    {
        KL[i].load(":/pic/nicolai/zhanjiL.png");
        KR[i].load(":/pic/nicolai/zhanjiR.png");
    }
    for(int i=0;i<12;i++)
    {
        IL[i].load(QString(":/Anime/nico/daL/da_%1%2.png").arg(i/10).arg(i%10));
        IR[i].load(QString(":/Anime/nico/daR/da_%1%2.png").arg(i/10).arg(i%10));
    }
    jumpL.load(":/pic/nicolai/jumpL.png");
    jumpR.load(":/pic/nicolai/jumpR.png");
    jump_time.setInterval(JUMP_DURATION);
    jump_time.setSingleShot(true);
    jump_counter = 0;

    //血条
    lifebar.setRect(1420,50,500,50);
    blood.setRect(1920-remainblood*5,50,remainblood*5,50);//最后再改成宏
    //人物图片---
}
void Human::jump()
{
    if(isbig_attacking || isnormal_attacking || isskill_attacking)return;
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

        if(y + GAME_ACCELERATION * GAME_RATE * GAME_RATE * fall_counter< Ui::LineY - HUMAN_HEIGHT)
        {
            y += GAME_ACCELERATION * GAME_RATE * GAME_RATE * fall_counter ++;
        }
        else
        {
            isjumping=false;
            y = Ui::LineY - HUMAN_HEIGHT;
            fall_counter = 1;
            jump_counter = 0;
        }

    }
}
void Human::move()
{
    if(isbig_attacking || isnormal_attacking || isskill_attacking)return;
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
        if(x - MOVE_SIZE>=0)
        {
            x -= MOVE_SIZE;
        }
        else
        {
            x = 0;
        }
        framecontrol++;
        framecontrol=framecontrol%3;
        if(framecontrol==2)
        {
            current++;
            current=current%11;
        }
        left=true;
        right=false;
    }
    else if(goright == true)
    {
        if(x + MOVE_SIZE<=Ui::sizeOfRow)
        {
            x += MOVE_SIZE;
        }
        else
        {
           x = Ui::sizeOfRow;
        }

        framecontrol++;
        framecontrol=framecontrol%3;
        if(framecontrol==2)
        {
            current++;
            current=current%11;
        }
        right=true;
        left=false;
    }
}
QPixmap Human::getImg1()
{
    if(isdefence==true)
    {
      if(left==true&&right==false)
      {
        px=20;
        py=23;
        height = 150;
        length = 205;
        return blockL;
      }
      if(left==false&&right==true)
      {
        px=20;
        py=23;
        height = 150;
        length = 205;
        return blockR;
      }
      else
      {
        px=0;
        py=33;
        height = 130;
        length = 175;
        return humanL;
      }
    }
    else
    {
     if(isnormal_attacking||isskill_attacking||isbig_attacking)
     {
         if(isnormal_attacking&&left==true)
         {
             px=20;
             py=33;
             height = 300;
             length = 180;
             framecontrolA[0]++;
             framecontrolA[0]=framecontrolA[0]%11;
             if(framecontrolA[0]==10)
             {
                 currentA[0]++;
                 currentA[0]=currentA[0]%11;
             }
             return JL[currentA[0]];
         }
         if(isnormal_attacking&&right==true)
         {
             px=20;
             py=33;
             height = 300;
             length = 180;
             framecontrolA[0]++;
             framecontrolA[0]=framecontrolA[0]%11;
             if(framecontrolA[0]==10)
             {
                 currentA[0]++;
                 currentA[0]=currentA[0]%11;
             }
             return JR[currentA[0]];
         }
         if(isskill_attacking&&left==true)
         {
             px=20;
             py=33;
             height = 380;
             length = 210;
             framecontrolA[1]++;
             framecontrolA[1]=framecontrolA[1]%16;
             if(framecontrolA[1]==15)
             {
                 currentA[1]++;
                 currentA[1]=currentA[1]%6;
             }
             return KL[currentA[1]];
         }
         if(isskill_attacking&&right==true)
         {
             px=20;
             py=33;
             height = 380;
             length = 210;
             framecontrolA[1]++;
             framecontrolA[1]=framecontrolA[1]%16;
             if(framecontrolA[1]==15)
             {
                 currentA[1]++;
                 currentA[1]=currentA[1]%6;
             }
             return KR[currentA[1]];
         }
         if(isbig_attacking&&left==true)
         {
             px=540;
             py=453;
             height = 1100;
             length = 900;
             framecontrolA[2]++;
             framecontrolA[2]=framecontrolA[2]%11;
             if(framecontrolA[2]==10)
             {
                 currentA[2]++;
                 currentA[2]=currentA[2]%32;
             }
             return IL[currentA[2]];
         }
         if(isbig_attacking&&right==true)
         {
             px=540;
             py=453;
             height = 1100;
             length = 900;
             framecontrolA[2]++;
             framecontrolA[2]=framecontrolA[2]%11;
             if(framecontrolA[2]==10)
             {
                 currentA[2]++;
                 currentA[2]=currentA[2]%32;
             }
             return IR[currentA[2]];
         }
         else
         {
             px=0;
             py=13;
             height = 130;
             length = 175;
             return humanL;
         }
     }
     else
     {
      if(isjumping==false)
      {
          if(goleft==false&&goright==false&&left==true&&right==false)
          {
              px=0;
              py=13;
            height = 130;
            length = 175;
            return humanL;
          }
          if(goleft==false&&goright==false&&left==false&&right==true)
          {
              px=0;
              py=13;
            height = 130;
            length = 175;
            return humanR;
          }
          if(goleft==true&&goright==false)
          {
            px=0;
            py=13;
            height = 130;
            length = 185;
            return WalkL[current];
          }
          if(goleft==false&&goright==true)
          {
            px=0;
            py=13;
            height = 130;
            length = 185;
            return WalkR[current];
          }
          else
          {
            px=0;
            py=13;
            height = 130;
            length = 175;
            return humanL;
          }
      }
      else
      {
        if(goleft==true&&goright==false)
        {
            px=0;
            py=13;
            height = 130;
            length = 185;
            return jumpL;
        }
        if(goleft==false&&goright==true)
        {
            px=0;
            py=13;
            height = 130;
            length = 185;
            return jumpR;
        }
        if(goleft==false&&goright==false&&left==true&&right==false)
        {
            px=0;
            py=13;
            height = 130;
            length = 185;
            return jumpL;
        }
        if(goleft==false&&goright==false&&left==false&&right==true)
        {
            px=0;
            py=13;
            height = 130;
            length = 185;
            return jumpR;
        }
        else
        {
            px=0;
            py=13;
            height = 130;
            length = 185;
            return jumpL;
        }
      }
     }
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
                if(!player2->isnormalhurt)remainblood-=20;
                player2->isnormalhurt=true;
            }
        }
        else
        {
            player2->isnormalhurt=false;
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
                if(!player2->isskillhurt)remainblood-=10;
                player2->isskillhurt=true;
            }
        }
        else
        {
            player2->isskillhurt=false;
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
                if(!player2->isbighurt)remainblood-=30;
                player2->isbighurt=true;
            }
        }
        else
        {
            player2->isbighurt=false;
            isbig_attacking = false;
        }
    }
}
void Human::setOtherplayer(Human* otherdata)
{
    x = otherdata->x;
    y = otherdata->y;
    //qDebug() << x << y;
    current =otherdata->current;
    goleft = otherdata->goleft;
    goright = otherdata->goright;
    left = otherdata->left;
    right = otherdata->right;
    isjumping = otherdata->isjumping;
    isnormal_attacking = otherdata->isnormal_attacking;
    isskill_attacking = otherdata->isskill_attacking;
    isbig_attacking = otherdata->isbig_attacking;
    isdefence = otherdata->isdefence;
    manbox.setbox(otherdata->x,otherdata->y,otherdata->x+165,otherdata->y+210);
    remainblood = otherdata->remainblood;
    qDebug() << remainblood;

}
QPixmap Human::getImg2()
{
    if(isdefence==true)
    {
      if(left==true&&right==false)
      {
          px=120;
          py=100;
        height = 330;
        length = 350;
        return blockL;
      }
      if(left==false&&right==true)
      {
          px=72;
          py=100;
        height = 330;
        length = 350;
        return blockR;
      }
      else
      {
          px=140;
          py=20;
        height = 240;
        length = 200;
        return humanL;
      }
    }
    else
    {
     if(isnormal_attacking||isskill_attacking||isbig_attacking)
     {
         if(isnormal_attacking&&left==true)
         {
             px=250;
             py=20;
             height = 600;
             length = 180;
             framecontrolA[0]++;
             framecontrolA[0]=framecontrolA[0]%11;
             if(framecontrolA[0]==10)
             {
                 currentA[0]++;
                 currentA[0]=currentA[0]%11;
             }
             return JL[currentA[0]];
         }
         if(isnormal_attacking&&right==true)
         {
             px=250;
             py=20;
             height =600;
             length = 180;
             framecontrolA[0]++;
             framecontrolA[0]=framecontrolA[0]%11;
             if(framecontrolA[0]==10)
             {
                 currentA[0]++;
                 currentA[0]=currentA[0]%11;
             }
             return JR[currentA[0]];
         }
         if(isskill_attacking&&left==true)
         {
             px=400;
             py=100;
             height = 750;
             length = 380;
             framecontrolA[1]++;
             framecontrolA[1]=framecontrolA[1]%16;
             if(framecontrolA[1]==15)
             {
                 currentA[1]++;
                 currentA[1]=currentA[1]%6;
             }
             return KL[currentA[1]];
         }
         if(isskill_attacking&&right==true)
         {
             px=250;
             py=100;
             height = 750;
             length = 380;
             framecontrolA[1]++;
             framecontrolA[1]=framecontrolA[1]%16;
             if(framecontrolA[1]==15)
             {
                 currentA[1]++;
                 currentA[1]=currentA[1]%6;
             }
             return KR[currentA[1]];
         }
         if(isbig_attacking&&left==true)
         {
             px=340;
             py=150;
             height = 800;
             length = 550;
             framecontrolA[2]++;
             framecontrolA[2]=framecontrolA[2]%33;
             if(framecontrolA[2]==32)
             {
                 currentA[2]++;
                 currentA[2]=currentA[2]%12;
             }
             return IL[currentA[2]];
         }
         if(isbig_attacking&&right==true)
         {
             px=340;
             py=150;
             height = 800;
             length = 550;
             framecontrolA[2]++;
             framecontrolA[2]=framecontrolA[2]%33;
             if(framecontrolA[2]==32)
             {
                 currentA[2]++;
                 currentA[2]=currentA[2]%12;
             }
             return IR[currentA[2]];
         }
         else
         {
             px=140;
             py=20;
           height = 240;
           length = 200;
             return humanL;
         }
     }
     else
     {
      if(isjumping==false)
      {
          if(goleft==false&&goright==false&&left==true&&right==false)
          {
              px=140;
              py=20;
            height = 240;
            length = 200;
            return humanL;
          }
          if(goleft==false&&goright==false&&left==false&&right==true)
          {
              px=0;
              py=20;
            height = 240;
            length = 200;
            return humanR;
          }
          if(goleft==true&&goright==false)
          {
              px=140;
              py=20;
            height = 250;
            length = 190;
            return WalkL[current];
          }
          if(goleft==false&&goright==true)
          {
              px=0;
              py=20;
            height = 250;
            length = 190;
            return WalkR[current];
          }
          else
          {
              px=140;
              py=20;
            height = 240;
            length = 200;
            return humanL;
          }
      }
      else
      {
        if(goleft==true&&goright==false)
        {
            px=140;
            py=20;
            height = 240;
            length = 200;
            return jumpL;
        }
        if(goleft==false&&goright==true)
        {
            px=0;
            py=20;
            height = 240;
            length = 200;
            return jumpR;
        }
        if(goleft==false&&goright==false&&left==true&&right==false)
        {
            px=140;
            py=20;
            height = 240;
            length = 200;
            return jumpL;
        }
        if(goleft==false&&goright==false&&left==false&&right==true)
        {
            px=0;
            py=20;
            height = 240;
            length = 200;
            return jumpR;
        }
        else
        {
            px=140;
            py=20;
            height = 240;
            length = 200;
            return jumpL;
        }
      }
     }
    }
    //human 类里有isnormal_attacking,isskill_attacking来判断状态，根据这个你去绑定动画
}

void Human::changebox1()
{
    manbox.setbox(x,y,x+130,y+165);
    if(right==true)
    {
        Jrange.setbox(x+130,y+80,x+390,y+80);
        Krange.setbox(x+130,y+80,x+260,y+80);
        Irange.setbox(x+130,y+80,x+260,y+80);
    }
    else if(left==true)
    {
        Jrange.setbox(x-260,y+80,x,y+80);
        Krange.setbox(x-130,y+80,x,y+80);
        Irange.setbox(x-130,y+80,x,y+80);
    }
}

void Human::changebox2()
{
    manbox.setbox(x,y,x+200,y+260);
    if(right==true)
    {
        Jrange.setbox(x+130,y+80,x+390,y+90);
        Krange.setbox(x+130,y+80,x+260,y+90);
        Irange.setbox(x+130,y+80,x+260,y+90);
    }
    else if(left==true)
    {
        Jrange.setbox(x-260,y+80,x,y+90);
        Krange.setbox(x-130,y+80,x,y+90);
        Irange.setbox(x-130,y+80,x,y+90);
    }
}

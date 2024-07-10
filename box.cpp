#include "box.h"
void Box::setbox(int X1,int Y1,int X2,int Y2)
{
    x1=X1;
    y1=Y1;
    x2=X2;
    y2=Y2;
}
bool Box::iscollided(int x3,int y3,int x4,int y4)
{
    // 检查一个矩形是否在另一个矩形的左边或右边
    if (x1 >= x4 || x3 >= x2)
    {
        return false;
    }

    // 检查一个矩形是否在另一个矩形的上方或下方
    if (y1 >= y4 || y3 >= y2)
    {
        return false;
    }

    // 如果没有返回 false，则矩形相交
    return true;
}

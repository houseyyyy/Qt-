#ifndef BOX_H
#define BOX_H
class Box
{
public:
    int x1;//左上角x坐标
    int y1;//左上角y坐标
    int x2;//右下角x坐标
    int y2;//右下角y坐标
    void setbox(int ,int ,int ,int );
    bool iscollided(int ,int ,int ,int );
};

#endif // BOX_H

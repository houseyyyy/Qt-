#include "client.h"
#include <QString>
Client::Client(){
   player = new Human;
   player->x = 500;
   player->y = 900;
   player->remainblood=100;
};

//连接
bool Client::Connect(QString ip,QString port)
{
    socket.connectToHost(ip,port.toInt());
    if(!socket.waitForConnected(2000)){
        qDebug("连接失败");
        return 0;
    }
    qDebug("成功连接");
    connect(&socket,SIGNAL(readyRead()),this,SLOT(receiveData()));
    return 1;
}

//接受数据
void Client::receiveData()
{
    QByteArray array=socket.readAll();
    int data[15];
    for (int i=0; i<15; i++)
    {
        int unTemp;
        memcpy(&unTemp, array.data() + sizeof(int) * i, sizeof(int));
        data[i] = unTemp;
    }
    player->x=data[0]; player->y=data[1];player->goleft = data[2];player->goright = data[3];
    player->isjumping = data[4];player->isnormal_attacking = data[5];
    player->isskill_attacking = data[6];player->isbig_attacking = data[7];player->isdefence = data[8];
    player->left = data[9];player->right = data[10];player->remainblood = data[11];
    player->length=data[12];player->height=data[13];player->current=data[14];
}

//发送数据
void Client::sendData(Human* human)
{
    QByteArray data;
    int self[] = {human->x,human->y,human->goleft,human->goright,human->isjumping,human->isnormal_attacking,human->isskill_attacking,human->isbig_attacking,human->isdefence,human->left,human->right,human->remainblood,human->length,human->height,human->current};
    data.append((char*)self,sizeof(int)*15);
    socket.write(data);
}


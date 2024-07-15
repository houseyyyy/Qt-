#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}
{
    player = new Human;
    player->x = 1400;
    player->y = 900;
    player->remainblood=100;
}

//开启监听
void Server::Connect(int port)
{
    listen(QHostAddress::Any,port);
}
//玩家连入（自动）
void Server::incomingConnection(qintptr handle){
    socket.setSocketDescriptor(handle);
    qDebug("成功连入");
    connect(&socket,SIGNAL(readyRead()),this,SLOT(receiveData()));
    isConnected=1;
}
//接收数据
void Server::receiveData()
{
    // QByteArray
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
    //qDebug() << data[11];
}
//发送数据
void Server::sendData(Human* human)
{
    if(isConnected){
        QByteArray data;
        int self[] = {human->x,human->y,human->goleft,human->goright,human->isjumping,human->isnormal_attacking,human->isskill_attacking,human->isbig_attacking,human->isdefence,human->left,human->right,human->remainblood,human->length,human->height,human->current};
        data.append((char*)self,sizeof(int)*15);
        socket.write(data);
    }
}

#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}
{
    x = 400;
    y = 750;
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
    int data[2];
    for (int i=0; i<2; i++)
    {
        int unTemp;
        memcpy(&unTemp, array.data() + sizeof(int) * i, sizeof(int));
        //qDebug() << unTemp <<" \n"[i == 1];
        data[i] = unTemp;
    }
    x=data[0];
    y=data[1];
}
//发送数据
void Server::sendData(int x,int y)
{
    if(isConnected){
        QByteArray array;
        int self[] = {x,y};
        array.append((char*)self,sizeof(int) * 2);
        socket.write(array);
    }
}
//获取数据

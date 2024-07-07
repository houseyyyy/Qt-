#include "client.h"
#include <QString>
Client::Client(){};

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
    // QByteArray
    QByteArray array=socket.readAll();
    //待完成   把array里面的数据读下来
    int data[2];
    for (int i=0; i<3; i++)
    {
        int unTemp;
        memcpy(&unTemp, array.data() + sizeof(int) * i, sizeof(int));
        data[i] = unTemp;
    }
    x=data[0];
    y=data[1];
}

//发送数据
void Client::sendData(int x,int y)
{
    QByteArray array;
    array.append(QChar(x));
    array.append(QChar(y));
    socket.write(array);
}


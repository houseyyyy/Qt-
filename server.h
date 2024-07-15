#ifndef SERVER_H
#define SERVER_H

#include "Human.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QDebug>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void Connect(int port);
    void sendData(Human*);

    Human* player;
    //存client的数据
    bool isConnected=0;

private:
    QTcpSocket socket;    

private slots:
    void incomingConnection(qintptr handle);
    void receiveData();
signals:
    void dataReceived();
    void getMessage();
};
#endif // SERVER_H

#ifndef CLIENT_H
#define CLIENT_H

#include "Human.h"
#include <QTcpSocket>

class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client();
    bool Connect(QString ip,QString port);
    void sendData(Human*); //？？？？
    void getdata();//没写
    Human* player;
private slots:
    void receiveData();
private:
    QTcpSocket socket;
};

#endif // CLIENT_H

#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client();
    bool Connect(QString ip,QString port);
    void sendData(int x,int y); //？？？？
    void getdata();//没写
    //对方数据
    int x;
    int y;
private slots:
    void receiveData();
private:
    QTcpSocket socket;
};

#endif // CLIENT_H

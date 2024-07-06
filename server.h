#ifndef SERVER_H
#define SERVER_H

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
    void sendData(int x,int y);//??????

    int x;
    int y;
    //存client的数据
private:
    QTcpSocket socket;    
    bool isConnected=0;

private slots:
    void incomingConnection(qintptr handle);
    void receiveData();
signals:
    void dataReceived();
    void getMessage();
};
#endif // SERVER_H

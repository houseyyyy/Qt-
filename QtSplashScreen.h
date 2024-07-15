#ifndef QTSPLASHSCREEN_H
#define QTSPLASHSCREEN_H

#include <QObject>

#include <QSplashScreen>
#include <QProgressBar>
#include <QTime>
#include <QCoreApplication>
class QtSplashScreen : public QSplashScreen
{
    Q_OBJECT
public:

    QtSplashScreen(QPixmap pixmap, QWidget* parent = 0);
    ~QtSplashScreen();
    void  setRange(int min, int max);
    void  updateNum(int n);
    void  showMessageText(QString str);
    void  lodaDataBase();
private:

signals:

private:
QProgressBar* m_progressBar;

};

#endif // QTSPLASHSCREEN_H

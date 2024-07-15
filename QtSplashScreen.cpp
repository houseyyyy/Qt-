#include "QtSplashScreen.h"
#include "QDebug"
QtSplashScreen::QtSplashScreen(QPixmap pixmap, QWidget *parent):
    QSplashScreen(parent, pixmap)
{
    installEventFilter(this);//设置事件发送
    m_progressBar = new QProgressBar(this);
    m_progressBar->setAlignment(Qt::AlignCenter);
    m_progressBar->setGeometry(0, pixmap.height()-15, pixmap.width(), 15);   // 设置进度条的位置
    m_progressBar->setStyleSheet("QProgressBar{height:22px; text-align:center; font-size:14px; color:white; border-radius:11px; background:#000033;}"
                    "QProgressBar::chunk{border-radius:11px;background:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 #000000,stop:1 #999999);}");

    m_progressBar->setValue(0);
}

QtSplashScreen::~QtSplashScreen()
{

}

void QtSplashScreen::setRange(int min, int max)
{
    m_progressBar->setRange(min,max);
}

void QtSplashScreen::updateNum(int n)
{
    m_progressBar->setValue(n);//更新进度条进度
    //    mySleep(10);//停止10ms
}

void QtSplashScreen::showMessageText(QString str)
{
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;  //字体显示位置
    showMessage(str, topRight, Qt::white);
}

void QtSplashScreen::lodaDataBase()
{

}



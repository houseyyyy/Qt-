#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QWidget>
#include "gameengine.h"
#include <QPainter>
#include<QStyleOption>

namespace Ui {
class GameMenu;
}

class GameMenu : public QWidget
{
    Q_OBJECT

public:
    explicit GameMenu(QWidget *parent = nullptr);
    ~GameMenu();
private slots:

    void on_serverStart_clicked();
    void on_clientStart_clicked();
private:

    Ui::GameMenu *ui;
    GameEngine *game;
};
#endif // GAMEMENU_H

#include "gamemenu.h"
#include "ui_gamemenu.h"

GameMenu::GameMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameMenu)
{
    ui->setupUi(this);
    //game = new MainWindow;
}

GameMenu::~GameMenu()
{
    delete ui;
    delete game;
}
void GameMenu::on_serverStart_clicked()
{
    game->loadPlayer1(ui->serverPort->text().toInt());
    game->show();
    this->hide();
}


void GameMenu::on_clientStart_clicked()
{
    game->loadPlayer2(ui->clientIP->text(),ui->clientPort->text());
    game->show();
    this->hide();
}

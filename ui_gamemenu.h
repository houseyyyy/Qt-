/********************************************************************************
** Form generated from reading UI file 'gamemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMENU_H
#define UI_GAMEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMenu
{
public:
    QPushButton *clientStart;
    QPushButton *serverStart;
    QLineEdit *clientIP;
    QLineEdit *serverPort;
    QLineEdit *clientPort;

    void setupUi(QWidget *GameMenu)
    {
        if (GameMenu->objectName().isEmpty())
            GameMenu->setObjectName(QString::fromUtf8("GameMenu"));
        GameMenu->resize(666, 395);
        GameMenu->setStyleSheet(QString::fromUtf8("QWidget#GameMenu\n"
"{\n"
"    border-image:url(:/pic/folder.jpg)\357\274\233\n"
"}\n"
""));
        clientStart = new QPushButton(GameMenu);
        clientStart->setObjectName(QString::fromUtf8("clientStart"));
        clientStart->setGeometry(QRect(490, 240, 71, 41));
        clientStart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"      border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: rgb(149,149,149);\n"
"      min-width: 60px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:10pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
"  }\n"
" QPushButton:hover {\n"
"	border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: rgb(206,206,206);\n"
"      min-width: 60px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:9pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
" }"));
        serverStart = new QPushButton(GameMenu);
        serverStart->setObjectName(QString::fromUtf8("serverStart"));
        serverStart->setGeometry(QRect(350, 130, 81, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        serverStart->setFont(font);
        serverStart->setStyleSheet(QString::fromUtf8("  QPushButton {\n"
"      border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: rgb(149,149,149);\n"
"      min-width: 40px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:11pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
"  }\n"
" QPushButton:hover {\n"
"	border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: rgb(206,206,206);\n"
"      min-width: 40px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:10pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
" }"));
        clientIP = new QLineEdit(GameMenu);
        clientIP->setObjectName(QString::fromUtf8("clientIP"));
        clientIP->setGeometry(QRect(80, 240, 171, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        clientIP->setFont(font1);
        clientIP->setStyleSheet(QString::fromUtf8(""));
        serverPort = new QLineEdit(GameMenu);
        serverPort->setObjectName(QString::fromUtf8("serverPort"));
        serverPort->setGeometry(QRect(80, 130, 171, 41));
        serverPort->setFont(font1);
        clientPort = new QLineEdit(GameMenu);
        clientPort->setObjectName(QString::fromUtf8("clientPort"));
        clientPort->setGeometry(QRect(310, 240, 141, 41));
        clientPort->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(GameMenu);

        QMetaObject::connectSlotsByName(GameMenu);
    } // setupUi

    void retranslateUi(QWidget *GameMenu)
    {
        GameMenu->setWindowTitle(QCoreApplication::translate("GameMenu", "Form", nullptr));
        clientStart->setText(QCoreApplication::translate("GameMenu", "Start", nullptr));
        serverStart->setText(QCoreApplication::translate("GameMenu", "Start", nullptr));
        clientIP->setPlaceholderText(QCoreApplication::translate("GameMenu", "IP\345\234\260\345\235\200", nullptr));
        serverPort->setPlaceholderText(QCoreApplication::translate("GameMenu", "Port\347\253\257\345\217\243", nullptr));
        clientPort->setPlaceholderText(QCoreApplication::translate("GameMenu", "Port\347\253\257\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMenu: public Ui_GameMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMENU_H

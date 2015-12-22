/********************************************************************************
** Form generated from reading UI file 'lcd_show.ui'
**
** Created: Sat Dec 5 04:08:24 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LCD_SHOW_H
#define UI_LCD_SHOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lcd_show
{
public:
    QWidget *centralWidget;
    QPushButton *btn_message;
    QPushButton *btn_door;
    QPushButton *btn_check;
    QPushButton *pushButton;
    QLabel *lbl_date;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lcd_show)
    {
        if (lcd_show->objectName().isEmpty())
            lcd_show->setObjectName(QString::fromUtf8("lcd_show"));
        lcd_show->resize(480, 320);
        centralWidget = new QWidget(lcd_show);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_message = new QPushButton(centralWidget);
        btn_message->setObjectName(QString::fromUtf8("btn_message"));
        btn_message->setGeometry(QRect(40, 30, 111, 81));
        btn_door = new QPushButton(centralWidget);
        btn_door->setObjectName(QString::fromUtf8("btn_door"));
        btn_door->setGeometry(QRect(180, 30, 111, 81));
        btn_check = new QPushButton(centralWidget);
        btn_check->setObjectName(QString::fromUtf8("btn_check"));
        btn_check->setGeometry(QRect(320, 30, 111, 81));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 140, 391, 51));
        lbl_date = new QLabel(centralWidget);
        lbl_date->setObjectName(QString::fromUtf8("lbl_date"));
        lbl_date->setGeometry(QRect(180, 0, 251, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lbl_date->setFont(font);
        lcd_show->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(lcd_show);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 24));
        lcd_show->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lcd_show);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        lcd_show->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(lcd_show);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        lcd_show->setStatusBar(statusBar);

        retranslateUi(lcd_show);
        QObject::connect(btn_message, SIGNAL(clicked()), lcd_show, SLOT(show_message()));

        QMetaObject::connectSlotsByName(lcd_show);
    } // setupUi

    void retranslateUi(QMainWindow *lcd_show)
    {
        lcd_show->setWindowTitle(QApplication::translate("lcd_show", "lcd_show", 0, QApplication::UnicodeUTF8));
        btn_message->setText(QApplication::translate("lcd_show", "Message", 0, QApplication::UnicodeUTF8));
        btn_door->setText(QApplication::translate("lcd_show", "Open door", 0, QApplication::UnicodeUTF8));
        btn_check->setText(QApplication::translate("lcd_show", "Check Memo", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("lcd_show", "Setting", 0, QApplication::UnicodeUTF8));
        lbl_date->setText(QApplication::translate("lcd_show", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class lcd_show: public Ui_lcd_show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LCD_SHOW_H

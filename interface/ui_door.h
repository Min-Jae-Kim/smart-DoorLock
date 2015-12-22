/********************************************************************************
** Form generated from reading UI file 'door.ui'
**
** Created: Thu Dec 3 16:48:48 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOOR_H
#define UI_DOOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_door
{
public:
    QLabel *lbl_door;
    QPushButton *btn_1;
    QPushButton *btn_4;
    QPushButton *btn_7;
    QPushButton *btn_cls;
    QPushButton *btn_0;
    QPushButton *btn_2;
    QPushButton *btn_8;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_bs;
    QPushButton *btn_3;
    QPushButton *btn_9;
    QLineEdit *txt_pw;
    QPushButton *btn_bck;
    QPushButton *btn_cfm;

    void setupUi(QWidget *door)
    {
        if (door->objectName().isEmpty())
            door->setObjectName(QString::fromUtf8("door"));
        door->resize(480, 320);
        lbl_door = new QLabel(door);
        lbl_door->setObjectName(QString::fromUtf8("lbl_door"));
        lbl_door->setGeometry(QRect(20, 20, 421, 21));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        lbl_door->setFont(font);
        btn_1 = new QPushButton(door);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(220, 60, 81, 61));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        btn_1->setFont(font1);
        btn_4 = new QPushButton(door);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(220, 120, 81, 61));
        btn_4->setFont(font1);
        btn_7 = new QPushButton(door);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(220, 180, 81, 61));
        btn_7->setFont(font1);
        btn_cls = new QPushButton(door);
        btn_cls->setObjectName(QString::fromUtf8("btn_cls"));
        btn_cls->setGeometry(QRect(220, 240, 81, 61));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        btn_cls->setFont(font2);
        btn_0 = new QPushButton(door);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(300, 240, 81, 61));
        btn_0->setFont(font1);
        btn_2 = new QPushButton(door);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(300, 60, 81, 61));
        btn_2->setFont(font1);
        btn_8 = new QPushButton(door);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(300, 180, 81, 61));
        btn_8->setFont(font1);
        btn_5 = new QPushButton(door);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(300, 120, 81, 61));
        btn_5->setFont(font1);
        btn_6 = new QPushButton(door);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(380, 120, 81, 61));
        btn_6->setFont(font1);
        btn_bs = new QPushButton(door);
        btn_bs->setObjectName(QString::fromUtf8("btn_bs"));
        btn_bs->setGeometry(QRect(380, 240, 81, 61));
        btn_bs->setFont(font1);
        btn_3 = new QPushButton(door);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(380, 60, 81, 61));
        btn_3->setFont(font1);
        btn_9 = new QPushButton(door);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(380, 180, 81, 61));
        btn_9->setFont(font1);
        txt_pw = new QLineEdit(door);
        txt_pw->setObjectName(QString::fromUtf8("txt_pw"));
        txt_pw->setGeometry(QRect(20, 80, 181, 41));
        QFont font3;
        font3.setPointSize(17);
        txt_pw->setFont(font3);
        txt_pw->setEchoMode(QLineEdit::Password);
        txt_pw->setReadOnly(true);
        btn_bck = new QPushButton(door);
        btn_bck->setObjectName(QString::fromUtf8("btn_bck"));
        btn_bck->setGeometry(QRect(30, 220, 151, 51));
        QFont font4;
        font4.setPointSize(15);
        btn_bck->setFont(font4);
        btn_cfm = new QPushButton(door);
        btn_cfm->setObjectName(QString::fromUtf8("btn_cfm"));
        btn_cfm->setGeometry(QRect(30, 150, 151, 51));
        btn_cfm->setFont(font4);

        retranslateUi(door);

        QMetaObject::connectSlotsByName(door);
    } // setupUi

    void retranslateUi(QWidget *door)
    {
        door->setWindowTitle(QApplication::translate("door", "Form", 0, QApplication::UnicodeUTF8));
        lbl_door->setText(QApplication::translate("door", "Enter password to access", 0, QApplication::UnicodeUTF8));
        btn_1->setText(QApplication::translate("door", "1", 0, QApplication::UnicodeUTF8));
        btn_4->setText(QApplication::translate("door", "4", 0, QApplication::UnicodeUTF8));
        btn_7->setText(QApplication::translate("door", "7", 0, QApplication::UnicodeUTF8));
        btn_cls->setText(QApplication::translate("door", "Clear All", 0, QApplication::UnicodeUTF8));
        btn_0->setText(QApplication::translate("door", "0", 0, QApplication::UnicodeUTF8));
        btn_2->setText(QApplication::translate("door", "2", 0, QApplication::UnicodeUTF8));
        btn_8->setText(QApplication::translate("door", "8", 0, QApplication::UnicodeUTF8));
        btn_5->setText(QApplication::translate("door", "5", 0, QApplication::UnicodeUTF8));
        btn_6->setText(QApplication::translate("door", "6", 0, QApplication::UnicodeUTF8));
        btn_bs->setText(QApplication::translate("door", "<-", 0, QApplication::UnicodeUTF8));
        btn_3->setText(QApplication::translate("door", "3", 0, QApplication::UnicodeUTF8));
        btn_9->setText(QApplication::translate("door", "9", 0, QApplication::UnicodeUTF8));
        txt_pw->setText(QString());
        btn_bck->setText(QApplication::translate("door", "back", 0, QApplication::UnicodeUTF8));
        btn_cfm->setText(QApplication::translate("door", "comfirm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class door: public Ui_door {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOOR_H

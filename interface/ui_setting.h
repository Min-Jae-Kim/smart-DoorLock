/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created: Sat Dec 5 03:31:06 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QLabel *lbl_Screen;
    QComboBox *box_srnTime;
    QPushButton *btn_conf;
    QPushButton *btn_cancel;
    QLabel *lbl_pw;
    QLineEdit *txt_newpw;

    void setupUi(QWidget *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName(QString::fromUtf8("setting"));
        setting->resize(480, 320);
        lbl_Screen = new QLabel(setting);
        lbl_Screen->setObjectName(QString::fromUtf8("lbl_Screen"));
        lbl_Screen->setGeometry(QRect(70, 40, 201, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lbl_Screen->setFont(font);
        box_srnTime = new QComboBox(setting);
        box_srnTime->setObjectName(QString::fromUtf8("box_srnTime"));
        box_srnTime->setGeometry(QRect(290, 40, 131, 31));
        btn_conf = new QPushButton(setting);
        btn_conf->setObjectName(QString::fromUtf8("btn_conf"));
        btn_conf->setGeometry(QRect(210, 230, 91, 41));
        btn_cancel = new QPushButton(setting);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(330, 230, 91, 41));
        lbl_pw = new QLabel(setting);
        lbl_pw->setObjectName(QString::fromUtf8("lbl_pw"));
        lbl_pw->setGeometry(QRect(70, 110, 201, 31));
        lbl_pw->setFont(font);
        txt_newpw = new QLineEdit(setting);
        txt_newpw->setObjectName(QString::fromUtf8("txt_newpw"));
        txt_newpw->setGeometry(QRect(290, 110, 131, 31));
        txt_newpw->setEchoMode(QLineEdit::Password);
        txt_newpw->setReadOnly(false);

        retranslateUi(setting);

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QWidget *setting)
    {
        setting->setWindowTitle(QApplication::translate("setting", "Form", 0, QApplication::UnicodeUTF8));
        lbl_Screen->setText(QApplication::translate("setting", "Screen Saver Time", 0, QApplication::UnicodeUTF8));
        btn_conf->setText(QApplication::translate("setting", "Confirm", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("setting", "Cancel", 0, QApplication::UnicodeUTF8));
        lbl_pw->setText(QApplication::translate("setting", "Change password", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H

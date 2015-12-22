/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created: Sun Nov 29 03:26:25 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_H
#define UI_MESSAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_message
{
public:
    QLineEdit *txt_subject;
    QPushButton *btn_send;
    QPushButton *btn_back;
    QLineEdit *txt_name;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *txt_content;
    QLabel *label_3;

    void setupUi(QWidget *message)
    {
        if (message->objectName().isEmpty())
            message->setObjectName(QString::fromUtf8("message"));
        message->resize(480, 320);
        txt_subject = new QLineEdit(message);
        txt_subject->setObjectName(QString::fromUtf8("txt_subject"));
        txt_subject->setGeometry(QRect(30, 30, 191, 31));
        btn_send = new QPushButton(message);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        btn_send->setGeometry(QRect(370, 10, 80, 61));
        btn_back = new QPushButton(message);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(370, 90, 80, 61));
        txt_name = new QLineEdit(message);
        txt_name->setObjectName(QString::fromUtf8("txt_name"));
        txt_name->setGeometry(QRect(240, 30, 91, 31));
        label = new QLabel(message);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 50, 16));
        label_2 = new QLabel(message);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 10, 50, 16));
        txt_content = new QTextEdit(message);
        txt_content->setObjectName(QString::fromUtf8("txt_content"));
        txt_content->setGeometry(QRect(30, 80, 301, 75));
        label_3 = new QLabel(message);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 60, 61, 16));

        retranslateUi(message);

        QMetaObject::connectSlotsByName(message);
    } // setupUi

    void retranslateUi(QWidget *message)
    {
        message->setWindowTitle(QApplication::translate("message", "Form", 0, QApplication::UnicodeUTF8));
        btn_send->setText(QApplication::translate("message", "send", 0, QApplication::UnicodeUTF8));
        btn_back->setText(QApplication::translate("message", "back", 0, QApplication::UnicodeUTF8));
        txt_name->setText(QString());
        label->setText(QApplication::translate("message", "subject", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("message", "name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("message", "content", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class message: public Ui_message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H

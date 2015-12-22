#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QPainter>
#include <QDialog>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
namespace Ui {
class message;
}

class message : public QWidget
{
    Q_OBJECT
    
public:
    explicit message(QWidget *parent = 0);
    bool eventFilter(QObject *obj, QEvent *ev);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void init_socket();
    void init_keyboard();
    ~message();
    
private slots:

    void on_btn_back_clicked();

    void on_btn_send_clicked();
signals:
    void msg_reset_timers();
private:
    Ui::message *ui;
    QLineEdit *curEdit;

    int clnt_sock;
    struct sockaddr_in serv;

    bool write_content;
    bool m_press_toggle;
    bool m_release_toggle;
    bool m_shift_toggle;
    bool m_shift_turn_toggle;

    QRect m_TextArea;
    QRect m_rcKey[4][10];
    QRect m_rcKeySp[4];
    QString m_strKey[4];
    QString m_strKey_Sh[4];
    QString m_strKeySp[4];
    QRect m_rcSelectedKey;
    QString m_strSelectedKey;

};

#endif // MESSAGE_H

#ifndef CHECKMEMO_H
#define CHECKMEMO_H

#include <QWidget>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include "QString"
#include "QChar"

namespace Ui {
class checkmemo;
}

class checkmemo : public QWidget
{
    Q_OBJECT
    
public:
    explicit checkmemo(QWidget *parent = 0);
    ~checkmemo();
    void update_list();
private slots:
    void on_btn_back_clicked();
signals:
    void check_reset_timers();
private:
    Ui::checkmemo *ui;
    int fd;
    QString msg[20];
};

#endif // CHECKMEMO_H

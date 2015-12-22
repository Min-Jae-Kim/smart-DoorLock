#ifndef DOOR_H
#define DOOR_H

#include <QWidget>
#include "checkmemo.h"
#include <QLineEdit>
#include <QLabel>


#include "setting.h"



#define DOOR 0
#define MEMO 1
#define SETTING 2
#define RE_PASS 3
namespace Ui {
class door;
}

class door : public QWidget
{
    Q_OBJECT
    
public:
    explicit door(QWidget *parent = 0);
    void set_wrong(bool * wrong);
    void set_open(bool * open);
    void set_setting(setting * st);
    void mode(int M);
    void set_checkmemo(checkmemo * ch);
    void set_PassLine(QLineEdit * pw_line);
    QLabel * get_label();
    ~door();
    
private slots:
    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_0_clicked();

    void on_btn_cls_clicked();

    void on_btn_bs_clicked();

    void on_btn_bck_clicked();

    void on_btn_cfm_clicked();
signals:
    void door_reset_timers();
private:
    Ui::door *ui;
    int wr_count;
    checkmemo *c;
    setting *s;
    QLineEdit * line;
    QString new_pass;
    int Mode;
    bool Is_rePassAgain;
    bool * Is_wrong;
    bool * Is_open;
};

#endif // DOOR_H

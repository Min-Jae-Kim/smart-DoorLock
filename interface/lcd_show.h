#ifndef LCD_SHOW_H
#define LCD_SHOW_H

#include <QMainWindow>
#include "message.h"
#include "door.h"
#include "checkmemo.h"
#include "memothread.h"
#include "setting.h"
#include "weatherthread.h"
#include "screensaver.h"
#include "dooropenthread.h"
#include <QMouseEvent> //
#include <QProcess>
#include <QTimer>
#include <QTime>
#include <QGraphicsScene>

namespace Ui {
class lcd_show;
}

class lcd_show : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit lcd_show(QWidget *parent = 0);
     void mousePressEvent(QMouseEvent *e);
     void mouseMoveEvent(QMouseEvent *e);
     int saverLimitTime;
    ~lcd_show();
    
private slots:
    void on_btn_message_clicked();
    void on_timer();
    void on_btn_door_clicked();

    void on_btn_check_clicked();

    void on_thread_update();
    void on_thread_error(const char * str);
    void on_reset_timer();
    void on_pushButton_clicked();

private:
    Ui::lcd_show *ui;
    QGraphicsScene * m_scene;
    bool * Is_three_wrong;
    bool * Is_open_door;
    int three_wrong_time;
    int open_door_time;
    int saved_timer;
    bool is_saved_timer;
    message m;
    door d;
    checkmemo c;
    setting st;
    screensaver s;
    memothread *t;
    weatherthread *w;
    dooropenthread *door_open;
    QTimer * m_pTimer;
    QString strProgram;
    QStringList list;
    QProcess process;
};

#endif // LCD_SHOW_H

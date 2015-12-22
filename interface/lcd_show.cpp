#include "lcd_show.h"
#include "ui_lcd_show.h"
#include "QMessageBox"
#include <stdio.h>
#include <unistd.h>

#define DOOR 0
#define MEMO 1
#define SETTING 2

lcd_show::lcd_show(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::lcd_show)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene(this);

    setMouseTracking(true);

    saverLimitTime = 15;

    m_pTimer = new QTimer(this);
    strProgram = "./sys";
    list << "192.168.25.10";
    process.start(strProgram, list);
    Is_three_wrong = new bool;
    Is_open_door = new bool;

    *Is_three_wrong = false;
    *Is_open_door = false;

    three_wrong_time = 0;
    open_door_time = 0;

    is_saved_timer = false;
    saved_timer = 0;

    d.set_wrong(Is_three_wrong);
    d.set_open(Is_open_door);


    t = new memothread(this);
    w = new weatherthread(this);
    door_open = new dooropenthread(this);
    connect(t, SIGNAL(updateList()), this, SLOT(on_thread_update()));
    connect(t, SIGNAL(errorCode(const char)), this, SLOT(on_thread_error(const char)));
    connect(door_open, SIGNAL(door_open_errorCode(const char)), this, SLOT(on_thread_error(const char)));
    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(on_timer()));
    connect(&m, SIGNAL(msg_reset_timers()), this, SLOT(on_reset_timer()));
    connect(&c, SIGNAL(check_reset_timers()), this, SLOT(on_reset_timer()));
    connect(&d, SIGNAL(door_reset_timers()), this, SLOT(on_reset_timer()));
    connect(&st, SIGNAL(set_reset_timer()), this, SLOT(on_reset_timer()));
    connect(&s, SIGNAL(saver_reset_timer()), this, SLOT(on_reset_timer()));
    connect(w, SIGNAL(signalWeather(const char*)), &s, SLOT(on_weather_setting(const char*)));
    m_pTimer->start(1000);
    t->start();
    w->start();
    door_open->start();
}


lcd_show::~lcd_show(){
    delete ui;
}
void lcd_show::mouseMoveEvent(QMouseEvent *e)
{
    is_saved_timer = false;
    saved_timer = 0;
}
void lcd_show::mousePressEvent(QMouseEvent *e)
{
    is_saved_timer = false;
    saved_timer = 0;

}

void lcd_show::on_timer()
{
    if(open_door_time >= 5)
    {
        (*Is_open_door) = false;
        system("sudo ./door_bell -c");
        open_door_time = 0;
    }
    if((*Is_open_door) == true)
    {
        open_door_time++;
    }


    if(three_wrong_time >= 5)
    {
        (*Is_three_wrong) = false;
        three_wrong_time  = 0;

    }
    if((*Is_three_wrong) == true)
    {
        three_wrong_time++;
    }
    ui->lbl_date->setText(QDateTime::currentDateTime().toString(QString("yyyy/MM/dd A hh:mm:ss")));
  //  ui->lcd_date->display(QTime::currentTime().toString(QString("A hh:mm:ss")));
    if(!is_saved_timer){
        saved_timer++;
        if(saved_timer > saverLimitTime){
            is_saved_timer = true;
            s.showFullScreen();
        }
    }
}

void lcd_show::on_btn_message_clicked(){
    is_saved_timer = true;
    m.showFullScreen();
   // ui->txt_test->setText("button");
}


void lcd_show::on_btn_door_clicked(){

    d.mode(DOOR);
    if( (*Is_three_wrong) == true)
    {
        QString mesg;
        mesg.sprintf("You cannot open the door\n left time : %d",5-three_wrong_time);
        QMessageBox::information(this,"REJECT",mesg);
    }
    else{
        is_saved_timer = true;
        d.showFullScreen();
    }
}

void lcd_show::on_btn_check_clicked(){
    d.mode(MEMO);
    d.set_checkmemo(&c);
    if( (*Is_three_wrong) == true)
    {
        QString mesg;
        mesg.sprintf("You cannot access MEMO \n left time : %d",5-three_wrong_time);
        QMessageBox::information(this,"REJECT",mesg);
    }
    else{
        is_saved_timer = true;
        d.showFullScreen();
    }
 //   c.showFullScreen();
}

void lcd_show::on_thread_update(){
    c.update_list();
    return ;
}

void lcd_show::on_thread_error(const char *str){
    QMessageBox::critical(this,"SOCKET",str);
    return ;
}

void lcd_show::on_reset_timer(){
    is_saved_timer = false;
    saved_timer = 0;
}

void lcd_show::on_pushButton_clicked()
{
    d.mode(SETTING);
    st.saverTimerSetting(&saverLimitTime);
    d.set_setting(&st);
    if( (*Is_three_wrong) == true)
    {
        QString mesg;
        mesg.sprintf("You cannot access SETTING\n left time : %d",5-three_wrong_time);
        QMessageBox::information(this,"REJECT",mesg);
    }
    else{
        is_saved_timer = true;
        d.showFullScreen();
    }
}

#include "door.h"
#include "ui_door.h"
#include <stdio.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

door::door(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::door)
{
    wr_count = 0;
    Is_rePassAgain = false;
    ui->setupUi(this);
}

door::~door()
{
    delete ui;
}
QLabel * door::get_label()
{
    return ui->lbl_door;

}

void door::set_wrong(bool * wrong)
{
    Is_wrong = wrong;
}
void door::set_open(bool *open)
{
    Is_open = open;
}
void door::set_checkmemo(checkmemo *ch)
{
    this->c = ch;
}
void door::set_setting(setting *st)
{
    this->s = st;
}
void door::set_PassLine(QLineEdit * pw_line)
{
    line = pw_line;
}

void door::mode(int M)
{
    Mode = M;
}

void door::on_btn_1_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("1");
}

void door::on_btn_2_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("2");
}

void door::on_btn_3_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("3");
}

void door::on_btn_4_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("4");
}

void door::on_btn_5_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("5");
}

void door::on_btn_6_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("6");
}

void door::on_btn_7_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("7");
}

void door::on_btn_8_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("8");
}

void door::on_btn_9_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("9");
}

void door::on_btn_0_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->insert("0");
}

void door::on_btn_cls_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->clear();
}


void door::on_btn_bs_clicked()
{
    system("sudo ./door_eff");
    ui->txt_pw->backspace();
}

void door::on_btn_bck_clicked()
{
    ui->txt_pw->clear();
    Is_rePassAgain = false;
    if(Mode == RE_PASS)
    {
        line->clear();

    }
    emit door_reset_timers();
    close();
}

void door::on_btn_cfm_clicked()
{
    QFile pw_file("./password");
    QString line;
    if(ui->txt_pw->text() == "")
    {
        QMessageBox::information(this,"VOID","Please input password");
        return ;
    }
    if( pw_file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&pw_file);
        line = in.readLine();
    }
    if(Mode == RE_PASS)
    {
        if(Is_rePassAgain == false)
        {
            new_pass = ui->txt_pw->text();
            ui->lbl_door->setText("Please input new password again to confirm");
            ui->txt_pw->clear();
            Is_rePassAgain = true;
        }
        else
        {
            if(new_pass == ui->txt_pw->text())
            {
                QMessageBox::information(this,"Change","Password is chnaged correctly");
                this -> close();

                this->line->setText(ui->txt_pw->text());
                Is_rePassAgain = false;
               // this -> close();
            }
            else
            {
                QMessageBox::information(this,"Change","Password is not mached\n please try again");
                ui->txt_pw->clear();
                this->close();
            }
            Is_rePassAgain = false;
        }
        ui->txt_pw->clear();
        //Is_rePassAgain = false;
        return ;
    }
    if(ui->txt_pw->text() == line)
    {
       // QMessageBox::information(this,"password","It is correct password");
        ui->txt_pw->clear();
        close();
        switch(Mode)
        {
            case DOOR:
                system("sudo ./door_bell -o");
                (*Is_open) = true;
                break;
            case MEMO:
                c->showFullScreen();
                break;
            case SETTING:
                s->showFullScreen();
                break;
            case RE_PASS:


                break;
        }

        wr_count = 0;
    }
    else
    {
        wr_count++;
        line.sprintf("Wrong password \n(count : %d)",wr_count);
        QMessageBox::critical(this,"password",line);
        ui->txt_pw->clear();
    }

    if(wr_count == 3)
    {
        QMessageBox::information(this,"quit","You enter the wrong password in 3 times. \n You can try again after 5 secs.");
        wr_count = 0;
        ui->txt_pw->clear();
        (*Is_wrong) = true;
        close();
    }

}

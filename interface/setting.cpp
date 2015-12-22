#include "setting.h"
#include "ui_setting.h"
#include "door.h"
#include "QMessageBox"
#include "QFile"
#include "QTextStream"
#include "lcd_show.h"

#define RE_PASS 3
setting::setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    ui->box_srnTime->insertItem(0,"15");
    ui->box_srnTime->insertItem(1,"30");
    ui->box_srnTime->insertItem(2,"45");
    ui->box_srnTime->insertItem(3,"60");



    //ui->box_srnTime->setCurrentIndex();
    ui->txt_newpw->installEventFilter(this);
}

setting::~setting()
{
    delete ui;
}
void setting::saverTimerSetting(int * saverLimitTime)
{
    sTimeLimit = saverLimitTime;
    switch(*saverLimitTime)
    {
        case 15:
            ui->box_srnTime->setCurrentIndex(0);
            break;
        case 30:
            ui->box_srnTime->setCurrentIndex(1);
            break;
        case 45:
            ui->box_srnTime->setCurrentIndex(2);
            break;
        case 60:
            ui->box_srnTime->setCurrentIndex(3);
            break;
    }
}

bool setting::eventFilter(QObject *obj, QEvent *ev)
{
    static door d;
    if(obj == ui->txt_newpw)
    {
        if(ev->type() == QEvent::MouseButtonPress)
        {
            d.mode(RE_PASS);
            d.set_PassLine(ui->txt_newpw);
            d.get_label()->setText("Input new password what you want");
            d.showFullScreen();
            return true;
        }
    }

    return  QWidget::eventFilter(obj,ev);
}

void setting::on_btn_cancel_clicked()
{
    ui->txt_newpw->clear();
    emit set_reset_timer();
    this->close();
}

void setting::on_btn_conf_clicked()
{
    if(ui->txt_newpw->text() == "")
    {
       // QMessageBox::critical(this,"ERROR","new password is void \n Please input your new password");
        this->close();
        return;
    }

    QFile pw_file("./password");
    QString line;
    if( pw_file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&pw_file);
        out << ui->txt_newpw->text();

    }
    emit set_reset_timer();
    this->close();
}

void setting::on_box_srnTime_activated(int index)
{
    QMessageBox::information(this,"test",ui->box_srnTime->currentText());
    *sTimeLimit = ui->box_srnTime->currentText().toInt();

}

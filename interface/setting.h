#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
//#include "door.h"


namespace Ui {
class setting;
}

class setting : public QWidget
{
    Q_OBJECT
    
public:
    explicit setting(QWidget *parent = 0);
    bool eventFilter(QObject *obj, QEvent *ev);
    void saverTimerSetting(int * saverLimitTime);
    ~setting();
    
private slots:
    void on_btn_cancel_clicked();

    void on_btn_conf_clicked();
    void on_box_srnTime_activated(int index);

signals:
    void set_reset_timer();
private:
    int * sTimeLimit;
    Ui::setting *ui;
  //  door d;
};

#endif // SETTING_H

#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <QProcess>
#include <QMouseEvent>
#include <QMessageBox>
#include "lcd_show.h"
#include <QWidget>


//lcd_show w;
class AllEvent : public QWidget
{
    private:
    lcd_show *w;

    public:
    AllEvent(lcd_show *pw)
    {
        w = pw;
    }

    void mouseMoveEvent(QMouseEvent *e)
    {
       QMessageBox::information(this,"aa","aa");

    }
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lcd_show w;

    AllEvent ae(&w);


    w.setMouseTracking(true);
    w.showFullScreen();
  
   
  //  w.get_ui();

    return a.exec();
}

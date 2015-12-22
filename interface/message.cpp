#include "message.h"
#include "ui_message.h"
#include "QTextEdit"
#include "QTextCursor"
#include "QMouseEvent"
#include "QMessageBox"


#define CX_BUTTON 43
#define CY_BUTTON 30
#define START_X 30
#define START_Y 160

#define PORT 9091
#define ADDR "192.168.25.10"
message::message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);

    ui->txt_subject->installEventFilter(this);
    ui->txt_name->installEventFilter(this);

    ui->txt_content->installEventFilter(this);
    ui->txt_content->viewport()->installEventFilter(this);
  //  m_TextArea.setRect(ui->txt_content->pos().x(),ui->txt_content->pos().y(),ui->txt_content->width(),ui->txt_content->height());

  //  m_TextArea.setRect(30,80,301,75);
    ui->txt_subject ->setFocus();



    curEdit = ui->txt_subject;
    write_content = false;
    m_press_toggle = false;
    m_release_toggle = false;

    m_shift_toggle = false;
    m_shift_turn_toggle = false;

    init_keyboard();

}

message::~message()
{
    delete ui;
}
void message::init_keyboard()
{
    for(int i =0;i<4;i++)
    {
        for(int j = 0;j<10;j++)
        {
            m_rcKey[i][j].setRect(START_X + CX_BUTTON*j, START_Y + CY_BUTTON*i,  CX_BUTTON, CY_BUTTON);
        }
    }

    m_rcKeySp[0].setRect(START_X, START_Y + CY_BUTTON*4, CX_BUTTON*2,  CY_BUTTON);

    m_rcKeySp[1].setRect(START_X + CX_BUTTON*3, START_Y + CY_BUTTON*4,  CX_BUTTON*4, CY_BUTTON);

    m_rcKeySp[2].setRect(START_X + CX_BUTTON*7, START_Y + CY_BUTTON*4,  CX_BUTTON*3, CY_BUTTON);

    m_rcKeySp[3].setRect(START_X + CX_BUTTON*2, START_Y + CY_BUTTON*4,  CX_BUTTON, CY_BUTTON);

    m_strKey[0] = "1234567890";
    m_strKey[1] = "qwertyuiop";
    m_strKey[2] = "asdfghjkl'";
    m_strKey[3] = "zxcvbnm,./";

    m_strKey_Sh[0] = "!@#$%^&*()";
    m_strKey_Sh[1] = "QWERTYUIOP";
    m_strKey_Sh[2] = "ASDFGHJKL\"";
    m_strKey_Sh[3] = "ZXCVBNM<>?";

    m_strKeySp[0] = "<-";
    m_strKeySp[1] = "Space";
    m_strKeySp[2] = "Enter";
    m_strKeySp[3] = "Sh";

}
void message::paintEvent(QPaintEvent *event)
{

    QPainter p(this);



    p.fillRect(START_X,START_Y,CX_BUTTON*10,CY_BUTTON*5,QBrush(Qt::yellow));

    p.setPen(QPen(Qt::black,1,Qt::SolidLine));

    p.drawRect(START_X,START_Y, CX_BUTTON*10 , CY_BUTTON*5);

    for(int i = 1 ; i<5;i++)
        p.drawLine(START_X,START_Y + CY_BUTTON*i,START_X + CX_BUTTON*10,START_Y + CY_BUTTON*i);

    for(int i = 1 ;i < 10 ; i++)
        p.drawLine(START_X + CX_BUTTON*i,START_Y,START_X + CX_BUTTON*i,START_Y + CY_BUTTON*4);

    p.drawLine(START_X + CX_BUTTON*2,START_Y + CY_BUTTON*4, START_X + CX_BUTTON*2,START_Y + CY_BUTTON*5);
    p.drawLine(START_X + CX_BUTTON*3,START_Y + CY_BUTTON*4, START_X + CX_BUTTON*3,START_Y + CY_BUTTON*5);
    p.drawLine(START_X + CX_BUTTON*7,START_Y + CY_BUTTON*4, START_X + CX_BUTTON*7,START_Y + CY_BUTTON*5);


    for(int i = 0 ; i<4;i++)
        for(int j= 0;j<10;j++)
        {
            if(m_shift_toggle == false)
                 p.drawText(m_rcKey[i][j],Qt::AlignCenter,QString(m_strKey[i][j]));
            else
                p.drawText(m_rcKey[i][j],Qt::AlignCenter,QString(m_strKey_Sh[i][j]));
        }

    for(int i=0;i<4;i++)
        p.drawText(m_rcKeySp[i],Qt::AlignCenter,m_strKeySp[i]);

    if(m_shift_toggle == true)
    {
        /*
        if(m_shift_turn_toggle == true)
        {
            p.fillRect(m_rcKeySp[3],QBrush(Qt::yellow));
            p.drawRect(m_rcKeySp[3]);
            p.drawText(m_rcKeySp[3],Qt::AlignCenter,m_strKeySp[3]);
            m_shift_toggle = false;
            m_shift_turn_toggle = false;
        }
        else
        {*/
            p.fillRect(m_rcSelectedKey,QBrush(Qt::green));
            p.drawRect(m_rcSelectedKey);
            p.drawText(m_rcSelectedKey,Qt::AlignCenter,m_strSelectedKey);
        //}
    }
    if(m_shift_turn_toggle == true)
    {
        p.fillRect(m_rcKeySp[3],QBrush(Qt::yellow));
        p.drawRect(m_rcKeySp[3]);
        p.drawText(m_rcKeySp[3],Qt::AlignCenter,m_strKeySp[3]);
        m_shift_toggle = false;
        m_shift_turn_toggle = false;
    }

    if(m_press_toggle == true)
    {

        if(m_release_toggle == true)
        {
            p.fillRect(m_rcSelectedKey,QBrush(Qt::yellow));
            p.drawRect(m_rcSelectedKey);
            p.drawText(m_rcSelectedKey,Qt::AlignCenter,m_strSelectedKey);
            m_press_toggle = false;
            m_release_toggle = false;
        }
        else
        {
            p.fillRect(m_rcSelectedKey,QBrush(Qt::blue));
            p.drawRect(m_rcSelectedKey);
            p.setPen(Qt::white);
            p.drawText(m_rcSelectedKey,Qt::AlignCenter,m_strSelectedKey);
        }
    }
   // QWidget::paintEvent(event);
    /*
    for(int x=0;x<100; x++)
    {
        for(int y = 0 ; y < 100 ; y++)
            painter.drawPoint(x,y);
    }
    */
}
void message::mousePressEvent(QMouseEvent * e)
{
    QPoint point = e->pos();
    QPainter p(this);
    int i;
    bool find = false;
    m_rcSelectedKey = QRect(-1,-1,-1,-1);
    m_strSelectedKey = "";
  /*  ui->txt_subject->setText(QString("x: %1").arg(point.x()));
    ui->txt_subject->insert(QString(" y: %1").arg(point.y()));*/
    /*
    if(m_TextArea.contains(point))
    {
        write_content = true;
        ui->txt_subject->setText("test");
        return;
    }*/

    for(i = 0;i<4;i++)
    {
        for(int j = 0 ; j <10; j++)
        {
            if(m_rcKey[i][j].contains(point))
            {
                m_rcSelectedKey = m_rcKey[i][j];
                if(m_shift_toggle == false)
                    m_strSelectedKey = m_strKey[i][j];
                else
                     m_strSelectedKey = m_strKey_Sh[i][j];
                //       ui->txt_name->setText("click");
                find = true;
                break;
            }

        }
        if(find == true)
            break;
    }

    if(i == 4) //BS,Space, Enter
    {
        for(int j=0;j<4;j++)
        {
            if(m_rcKeySp[j].contains(point))
            {
                m_rcSelectedKey = m_rcKeySp[j];
                m_strSelectedKey = m_strKeySp[j];
                break;
            }
        }
    }

    if(QString::compare("",m_strSelectedKey) != 0)
    {

        if(m_strSelectedKey == "Sh")
        {
            if(m_shift_toggle == false)
            {
                m_shift_toggle = true;
                update();
                return;
            }
            else
            {
                m_shift_turn_toggle = false;

                update();
                return;
            }
        }
        m_press_toggle = true;
        update();
        if(write_content == false)
        {
            if(curEdit != NULL)
            {
                if(i == 4)
                {
                    if(m_strSelectedKey == "<-")
                    {
                        curEdit->backspace();
   //                     curEdit->insert(QString(QChar(0x08)));
                    }
                    else if(m_strSelectedKey == "Space")
                        curEdit->insert(QString(" "));
                    else if(m_strSelectedKey == "Enter")
                        curEdit->insert(QString(QChar(0x0d)));
                }
                else{
                    curEdit-> insert(m_strSelectedKey);
                    curEdit->setFocus();
                }
            }
        }
        else if(write_content == true)
        {
          //  ui->txt_subject->setText("in");
            ui->txt_content->moveCursor(QTextCursor::End);
            if(i == 4)
            {
                if(m_strSelectedKey == "<-")
                {
                 //   ui->txt_content->insertPlainText(QString(QChar(0x08)));
                //    ui->txt_content->moveCursor(QTextCursor::deleteChar());
                    QTextCursor cursor = ui->txt_content->textCursor();
                    cursor.deletePreviousChar();
                    return ;
                }
                else if(m_strSelectedKey == "Space")
                    ui->txt_content->insertPlainText(QString(" "));
                else if(m_strSelectedKey == "Enter")
                    ui->txt_content->insertPlainText(QString(QChar(0x0d)));
            }
            else{
                ui->txt_content->insertPlainText(m_strSelectedKey);

            }
            ui->txt_content->moveCursor(QTextCursor::End);
        }
        if(m_shift_toggle == true)
        {
            m_shift_turn_toggle = true;
            update();
        }
    }

}
void message::mouseReleaseEvent(QMouseEvent *e)
{
    QPainter p(this);

    if(!m_rcSelectedKey.isNull())
    {
        m_release_toggle = true;
        update();

    }
}
void message::on_btn_send_clicked()
{
    char buf[4096] = {0,};

    if(ui->txt_subject->text() == "")
    {
        QMessageBox::information(this,"Subject","Please Input Subject");
        ui->txt_subject->setFocus();
        curEdit = ui->txt_subject;
        write_content = false;
        return ;
    }

    if(ui->txt_name->text() == "")
    {
        QMessageBox::information(this,"Name","Please Input your Name");
        ui->txt_name->setFocus();
        curEdit = ui->txt_name;
        write_content = false;
        return;
    }

    if(ui->txt_content->toPlainText() == "")
    {
        QMessageBox::information(this,"Content","Please Input Content");
        ui->txt_content->setFocus();
        write_content = true;
        return ;

    }

    init_socket();
    sprintf(buf,"%s|%s|%s",ui->txt_subject->text().toAscii().data()
            ,ui->txt_name->text().toAscii().data()
            ,ui->txt_content->toPlainText().toAscii().data());

    write(clnt_sock,buf,sizeof(buf));
    ::close(clnt_sock);
    QMessageBox::information(this,"Message","Success to send Message!");
}

void message::init_socket()
{
    if( (clnt_sock = socket(PF_INET,SOCK_STREAM,0)) < 0)
    {
        QMessageBox::critical(this,"SOCKET","Can't create socket");
        return ;
    }

    memset(&serv,0,sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(ADDR);
    serv.sin_port = htons(PORT);

    if(::connect(clnt_sock,(struct sockaddr *)&serv,sizeof(serv)) < 0)
    {
        QMessageBox::information(this,"CONNECT","Can't connect to server");
        return ;
    }
}

void message::on_btn_back_clicked()
{

    ui->txt_subject->clear();
    ui->txt_name->clear();
    ui->txt_subject->setFocus();
    ui->txt_content->clear();
    write_content = false;

    curEdit = ui->txt_subject;
    emit msg_reset_timers();
    this->close();
}
/*
void message::on_pushButton_3_clicked()
{
    if(write_content == false)
    {
        if(curEdit != NULL)
        {
            curEdit-> insert("q");
            curEdit->setFocus();
        }
    }
    else if(write_content == true)
    {
        ui->txt_subject->setText("in");
        ui->txt_content->moveCursor(QTextCursor::End);
        ui->txt_content->insertPlainText("q");
        ui->txt_content->moveCursor(QTextCursor::End);
    }

   // ui->txt_subject->setText("a");

}*/
bool message::eventFilter(QObject *obj, QEvent *ev)
{

    if(obj == ui->txt_subject)
    {
        if(ev->type() == QEvent::MouseButtonPress)
        {
            curEdit = ui->txt_subject;
            write_content = false;
            //ui->txt_subject->setText("test");
            return true;
        }
    }
    else if(obj == ui->txt_name)
    {
        if(ev->type() == QEvent::MouseButtonPress)
        {
            curEdit = ui->txt_name;
            write_content = false;
            //ui->txt_subject->setText("test");
            return true;
        }
    }
    else if(obj == ui->txt_content || obj == ui->txt_content->viewport())
    {
        if(ev->type() == QEvent::MouseButtonPress)
        {
            write_content = true;
          //  ui->txt_subject->setText("test");
            return true;
        }
    }

    return  QWidget::eventFilter(obj,ev);
}





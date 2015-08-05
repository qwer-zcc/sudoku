#include "difficult.h"
#include <QApplication>
#include <QDesktopWidget>

ChooseWindow::ChooseWindow(QWidget *parent):
    QWidget(parent,Qt::WindowStaysOnTopHint)
{
    setGeometry(100,100,120,160);
    QDesktopWidget *desktop=QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);
    group=new QGroupBox("Difficulty",this);
    group->setGeometry(10,10,100,130);
    radio1=new QRadioButton("Easy",this);
    radio2=new QRadioButton("Normal",this);
    radio3=new QRadioButton("Hard",this);
    radio4=new QRadioButton("Impossible",this);
    radio1->move(20,35);
    radio2->move(20,60);
    radio3->move(20,85);
    radio4->move(20,110);
    connect(radio1,SIGNAL(clicked(bool)),this,SLOT(radioChange()));
    connect(radio2,SIGNAL(clicked(bool)),this,SLOT(radioChange()));
    connect(radio3,SIGNAL(clicked(bool)),this,SLOT(radioChange()));
    connect(radio4,SIGNAL(clicked(bool)),this,SLOT(radioChange()));
    dif=1;
}

int ChooseWindow::Difficult()
{
    return dif;
}

void ChooseWindow::radioChange()
{
    if (sender()==radio1)
    {
        dif=1;
    }
    else if (sender()==radio2)
    {
        dif=2;
    }
    else if (sender()==radio3)
    {
        dif=3;
    }
    else if (sender()==radio4)
    {
        dif=4;
    }
}


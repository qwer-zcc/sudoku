#include "block.h"

Block::Block(QWidget *parent)
    :QWidget(parent)
{
    nub=new QLineEdit(this);
    nub->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPixelSize(30);
    nub->setFont(font);
    nub->setMinimumSize(50,50);
    nub->setMaximumSize(50,50);
    QRegExp regExp("[1-9]*");
    nub->setValidator(new QRegExpValidator(regExp,this));
    connect(nub,SIGNAL(textChanged(QString)),this,SLOT(dataChange(QString)));
    nub->setText("");
    QPalette pal=nub->palette();
    pal.setColor(QPalette::Text,QColor(10,120,200));
    nub->setPalette(pal);
    da=-1;Ena=0;
}
int Block::data()
{
    return da;
}

QString Block::text()
{
    return nub->text();
}

void Block::setData(const QString &data)
{
    nub->setText(data);
}

void Block::setValue(int a)
{
    if (a<1)
    {
        nub->setText("");
        da=-1;
    }
    else
    {
        nub->setText(QString::number(a));
        da=a;
    }
}
void Block::setEna(int ok)
{
    nub->setEnabled(bool(ok));
    Ena=ok;
}
void Block::dataChange(const QString &data)
{
    if (data.isEmpty())
        da=-1;
    else da=data.toInt();
    if (data.size()==0 || data.size()==1)
        nub->setStyleSheet("QLineEdit { font: \"Times New Roman\" 30px; }");
    else if (data.size()==2 || data.size()==3)
        nub->setStyleSheet("QLineEdit { font:18px; }");
    else if (data.size()==4)
        nub->setStyleSheet("QLineEdit { font:12px; }");
    if (Ena==0) ChangeColor(QColor(255,0,0));
    else ChangeColor(QColor(10,120,200));
}
void Block::ChangeColor(const QColor &color)
{
    QPalette pale;
    pale.setColor(QPalette::Text,color);
    nub->setPalette(pale);
}
QPoint Block::getPos()
{
    return p;
}
void Block::setPos(int x,int y)
{
    QPoint pos;
    pos.setX(x);
    pos.setY(y);
    this->p=pos;
}
void Block::setPos(const QPoint &p)
{
    this->p=p;
}

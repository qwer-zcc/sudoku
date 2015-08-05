#ifndef GLINE_H
#define GLINE_H

#include <QWidget>
#include <QPainter>
#include <QColor>

class GLine : public QWidget
{

public:
    GLine(QWidget *parent=0);
    void setPen(int penSize,const QColor &color);
    void draw(int z,int len);

protected:
    void paintEvent(QPaintEvent *);


private:
    int penSize;
    QColor penColor;
    int z;
    int len;
};

#endif // GLINE_H


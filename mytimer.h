#ifndef MYTIMER
#define MYTIMER
#include <Qwidget>
#include <QTime>

class myTimer : public QWidget
{
public:
    myTimer(QWidget *parent=0);
    int current_hour();
    int current_minute();
    int current_second();
    int hour();
    int minute();
    int second();
    void Start();
    void Stop();
    void update();
    void Continue();
    void Pause();
    void Clear();
private:
    QTime Begin_time,End_time,current_time;
    int prehour,preminute,presecond,flag;
};

#endif // MYTIMER


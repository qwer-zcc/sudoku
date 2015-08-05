#include "mytimer.h"

myTimer::myTimer(QWidget *parent)
    :QWidget(parent)
{
    prehour=preminute=presecond=0;
    current_time=QTime::currentTime();
    Begin_time=QTime::currentTime();
    End_time=QTime::currentTime();
    flag=0;
}

void myTimer::Clear()
{
    prehour=preminute=presecond=0;
    current_time=QTime::currentTime();
    Begin_time=QTime::currentTime();
    End_time=QTime::currentTime();
    flag=0;
}

void myTimer::update()
{
    current_time=QTime::currentTime();
}

int myTimer::current_hour()
{
    update();
    return current_time.hour();
}

int myTimer::current_minute()
{
    update();
    return current_time.minute();
}

int myTimer::current_second()
{
    update();
    return current_time.second();
}

int myTimer::hour()
{
    return End_time.hour()-Begin_time.hour()+prehour;
}

int myTimer::minute()
{
    return hour()*60+End_time.minute()-Begin_time.minute()+preminute;
}

int myTimer::second()
{
    return minute()*60+End_time.second()-Begin_time.second()+presecond;
}

void myTimer::Start()
{
    update();
    Begin_time=QTime::currentTime();
    End_time=QTime::currentTime();
    prehour=preminute=presecond=0;
    flag=1;
}
void myTimer::Stop()
{
    update();
    if (flag) End_time=QTime::currentTime();
    flag=0;
}
void myTimer::Pause()
{
    update();
    if (flag==1)
    {
        End_time=QTime::currentTime();
        prehour+=End_time.hour()-Begin_time.hour();
        preminute+=(End_time.hour()-Begin_time.hour())*60+End_time.minute()-Begin_time.minute();
        presecond+=(End_time.hour()-Begin_time.hour())*3600+(End_time.minute()-Begin_time.minute())*60+End_time.second()-Begin_time.second();
    }
    flag=2;
}
void myTimer::Continue()
{
    update();
    if (flag==2)
    {
		flag=1;
		Begin_time=current_time;
		End_time=current_time;
    }
}

#ifndef DIFFICULT
#define DIFFICULT
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
 
class ChooseWindow : public QWidget
{
    Q_OBJECT
public:
    ChooseWindow(QWidget *parent=0);
    int Difficult();
public slots:
    void radioChange();
private:
    QGroupBox *group;
    QRadioButton *radio1,*radio2,*radio3,*radio4;
    int dif;
};

#endif // DIFFICULT


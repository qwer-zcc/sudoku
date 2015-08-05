#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "block.h"
#include "gline.h"
#include "mytimer.h"
#include "difficult.h"
#include "judge.h"
#include <QMainWindow>
#include <QFrame>
#include <QPushButton>
#include <QAction>
#include <QLayout>
#include <cstring>
#include <cstdlib>
#include <QMenu>
#include <QPainter>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void CreateBlocks();
    void drawLine();
    void build_new_one();
    void Makebutton();
    void CreateAction();
    int Delete_some_blocks();
private slots:
    void check_finish();
    void New_game();
    void Continue_game();
    void Pause_game();
    void Show_help();
    void Show_dif();
    

private:
    Ui::MainWindow *ui;
    QFrame *frame;
    myTimer *Timer1;
    ChooseWindow *Choose;
    Block *blocks[10][10];
    Judge *myjudge;
    int Type;
};

#endif // MAINWINDOW_H

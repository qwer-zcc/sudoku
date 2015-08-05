#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <QTime>
#include <QAction>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i,a,b) for (int i=a;i<=b;i++)
int a[15][15],dt[15][15],bl[15],br[15],finish,res[15][15],vis[15],rem;
QString str[15][15];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon());
    frame=new QFrame(this);
	Timer1=new myTimer();
    Choose=new ChooseWindow();
    myjudge=new Judge();
    CreateAction();
    CreateBlocks();
    drawLine();
    Makebutton();
    build_new_one();
    this->setCentralWidget(frame);
    this->setFixedSize(frame->width(),frame->height()+ui->menuBar->height()+30);
    this->setWindowTitle("Sudoku");
    Choose->show();
}

void MainWindow::CreateAction()
{
    QAction *Action_new=new QAction(this);
    Action_new->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_N));
    addAction(Action_new);
    QAction *Action_continue=new QAction(this);
    Action_continue->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_C));
    addAction(Action_continue);
    QAction *Action_pause=new QAction(this);
    Action_pause->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_P));
    addAction(Action_pause);
    QAction *Action_help=new QAction(this);
    Action_help->setShortcut(QKeySequence::WhatsThis);
    addAction(Action_help);
    QAction *Action_dif=new QAction(this);
    Action_dif->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_D));
    addAction(Action_dif);
    
    connect(Action_new,SIGNAL(triggered(bool)),SLOT(New_game()));
    connect(Action_continue,SIGNAL(triggered(bool)),SLOT(Continue_game()));
    connect(Action_pause,SIGNAL(triggered(bool)),SLOT(Pause_game()));
    connect(Action_help,SIGNAL(triggered(bool)),SLOT(Show_help()));
    connect(Action_dif,SIGNAL(triggered(bool)),SLOT(Show_dif()));
}

void MainWindow::Show_dif()
{
    Choose->show();
}

void MainWindow::Show_help()
{
    QMessageBox help(QMessageBox::NoIcon,"What's this","This is a sudoku game.\n\n<C+N> to start a new game.\n<C+P> to pause the game.\n<C+C> to continue the game.\n<C+D> to choose difficulty\n\n\nProducted by qwer_zcc",QMessageBox::Ok);
    help.exec();
}

void MainWindow::New_game()
{
    QMessageBox ask(QMessageBox::NoIcon,"New game","Start a new game?",QMessageBox::Yes | QMessageBox::No,NULL);
    if (ask.exec()==QMessageBox::Yes) build_new_one();
//    QMessageBox::about(0,"New game","Start a new game?");
}

void MainWindow::Continue_game()
{
    if (Type==2)
    {
		Timer1->Continue();
		rep(i,0,8) rep(j,0,8)
		{
			if (dt[i][j]>0) blocks[i][j]->setEna(0);
			else blocks[i][j]->setEna(1);
            blocks[i][j]->setData(str[i][j]);
		}
        Type=1;
    }
}

void MainWindow::Pause_game()
{
    if (Type==1)
    {
		Timer1->Pause();
		rep(i,0,8) rep(j,0,8) str[i][j]=blocks[i][j]->text();
		rep(i,0,8) rep(j,0,8)
		{
            blocks[i][j]->ChangeColor(QColor(255,0,0));
			blocks[i][j]->setEna(0);
            if (dt[i][j]==0)
            {
                blocks[i][j]->setData("?");
				blocks[i][j]->ChangeColor(QColor(10,120,200));
            }
		}
        Type=2;
    }
}



void MainWindow::check_finish()
{
    int ok=1;
    rep(i,0,8) rep(j,0,8)
        if (blocks[i][j]->text().size()!=1) ok=0;
    rep(i,0,8) rep(j,0,8)
        res[i][j]=blocks[i][j]->text().toInt();
    rep(i,0,9) vis[i]=0;
    rep(i,0,8)
    {
        rep(j,0,8) vis[res[i][j]]=1;
        rep(j,1,9) if (!vis[j]) ok=0;
        rep(j,0,8) vis[res[i][j]]=0;
        rep(j,0,8) vis[res[j][i]]=1;
        rep(j,1,9) if (!vis[j]) ok=0;
        rep(j,0,8) vis[res[j][i]]=0;
    }
    rep(i,0,8) rep(j,0,8)
    {
        rep(l,bl[i],br[i]) rep(r,bl[j],br[j]) vis[res[l][r]]=1;
        rep(k,1,9) if (!vis[k]) ok=0;
        rep(l,bl[i],br[i]) rep(r,bl[j],br[j]) vis[res[l][r]]=0;
    }
    if (ok)
    {
        Type=0;
		Timer1->Stop();
		int a=Timer1->hour(),b=Timer1->minute()%60,c=Timer1->second()%60;
		QString timestring="";
		if (a>0) timestring+=QString::number(a,10)+":";
		if (a>0 && a<10) timestring="0"+timestring;
		if (b<10) timestring+="0"+QString::number(b,10)+":";
		else timestring+=QString::number(b,10)+":";
		if (c<10) timestring+="0"+QString::number(c,10);
		else timestring+=QString::number(c,10);
        QMessageBox::about(NULL,"Result","Successful!\nused time: "+timestring);
    }
    else QMessageBox::about(NULL,"Result","Not yet.");
}

void MainWindow::Makebutton()
{
    QPushButton *Check=new QPushButton("check",this);
    Check->move(175,470);
    connect(Check,SIGNAL(clicked(bool)),this,SLOT(check_finish()));
}

void MainWindow::CreateBlocks()
{
    rep(i,0,8) rep(j,0,8)
    {
        blocks[i][j]=new Block(frame);
        blocks[i][j]->setPos(i,j);
        blocks[i][j]->move(i*50,j*50);
    }
    frame->setMinimumSize(451,451);
}

void MainWindow::drawLine()
{
    GLine *H[4],*V[4];
    QColor color;
    QRgb rgb=qRgb(0,0,0);
    color.setRgb(rgb);
    rep(i,0,3) H[i]=new GLine(frame),H[i]->setPen(3,color),H[i]->draw(1,frame->height());
    rep(i,0,3) V[i]=new GLine(frame),V[i]->setPen(3,color),V[i]->draw(0,frame->height());
    rep(i,1,3) H[i]->move(50*i*3-1,0);
    rep(i,1,3) V[i]->move(0,50*i*3-1);
}

int check(int x,int y,int c)
{
	rep(i,0,8)
	{
		if (i!=y && a[x][i]==c) return 0;
		if (i!=x && a[i][y]==c) return 0;
	}
	rep(i,bl[x],br[x]) rep(j,bl[y],br[y])
		if (!(i==x && j==y) && a[i][j]==c) return 0;
	return 1;
}

int rnd(int n)
{
	return rand()%n;
}
void dfs(int x,int y)
{
	if (x>8)
	{
		finish=1;
		return;
	}
	int xx=x,yy=y;
	yy++;
	if (yy==9) xx++,yy=0;
	if (a[x][y])
	{
		if (check(x,y,a[x][y]))
			dfs(xx,yy);
		return;
	}
	int tmp[10];
	rep(i,1,9) tmp[i]=i;
	random_shuffle(tmp+1,tmp+10,rnd);
	rep(i,1,9)
		if (check(x,y,tmp[i]))
		{
			a[x][y]=tmp[i];
			dfs(xx,yy);
			if (finish) return;
			a[x][y]=0;
		}
}
void Rebuild()
{
	finish=0;
	dfs(0,0);
}

void Rand_one()
{
	while(1)
	{
		rep(i,0,8) rep(j,0,8) a[i][j]=dt[i][j]=0;
		rep(ti,1,11)
		{
			int p=rand()%9,q=rand()%9,c=rand()%9+1;
			while (a[p][q]!=0 || !check(p,q,c)) p=rand()%9,q=rand()%9,c=rand()%9+1;
			a[p][q]=dt[p][q]=c;
		}
		Rebuild();
		if (finish) break;
	}
    rep(i,0,8) rep(j,0,8) dt[i][j]=a[i][j];
}
int MainWindow::Delete_some_blocks()
{
	int cur=81,tot=40;rem=34;
	while (cur)
	{
		int p=rand()%9,q=rand()%9,fail=0;
		while (!dt[p][q]) p=rand()%9,q=rand()%9;
		rep(i,1,9)
			if (i!=dt[p][q])
			{
				rep(j,0,8) rep(k,0,8) a[j][k]=dt[j][k];
				a[p][q]=i;
				Rebuild();
				if (finish) {fail=1;break;}
			}
        if (tot<0) return 0;
        if (!fail) dt[p][q]=0,cur--;
        else {tot--;continue;}
        if (cur>rem) continue;
        myjudge->In(dt);
        if (myjudge->result()>=Choose->Difficult()) break;
	}
    rep(i,0,8) rep(j,0,8) a[i][j]=dt[i][j];
    Rebuild();
    return 1;
}

void MainWindow::build_new_one()
{
    Timer1->Clear();
    Timer1->Start();
    Type=1;
    rep(i,0,8) bl[i]=i/3*3,br[i]=i/3*3+2;
    rep(i,0,8) rep(j,0,8) dt[i][j]=a[i][j]=0;
    while (1)
    {
		Rand_one();
        if (Delete_some_blocks()) break;
    }
    rep(i,0,8) rep(j,0,8)
    {
        if (dt[i][j]>0)
        {
			blocks[i][j]->setValue(dt[i][j]);
			blocks[i][j]->setEna(0);
			blocks[i][j]->ChangeColor(QColor(255,0,0));
        }
        else
        {
            blocks[i][j]->setValue(0);
            blocks[i][j]->setEna(1);
            blocks[i][j]->ChangeColor(QColor(10,120,200));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

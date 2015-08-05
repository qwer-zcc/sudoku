#include "judge.h"
#include <iostream>
#include <cstdio>
using namespace std;
#define pb push_back
#define rep(i,a,b) for (int i=a;i<=b;i++)
const int Easy=1,Normal=2,Hard=3,Impossible=4;

Judge::Judge(QWidget *parent)
    :QWidget(parent)
{
    rep(i,0,8) rep(j,0,8) a[i][j]=0;
    rep(i,0,8) rep(j,0,8) rep(k,1,9) can[i][j][k]=0;
}

void Judge::Sure(int x,int y,int c)
{
	a[x][y]=c;
	Notsure--;
	rep(i,0,8)
	{
		if (i!=y) can[x][i][c]=0;
		if (i!=x) can[i][y][c]=0;
	}
	rep(i,bl[x],br[x]) rep(j,bl[y],br[y])
		if (!(i==x && j==y)) can[i][j][c]=0;
}

int Judge::Naked_Single()
{
	rep(i,0,8) rep(j,0,8)
	{
		if (a[i][j]) continue;
		int cnt=0,pos=0;
		rep(k,1,9)
			if (can[i][j][k]) cnt+=can[i][j][k],pos=k;
		if (cnt==1) {Sure(i,j,pos);return 1;}
	}
	return 0;
}

int Judge::Hidden_Single()
{
	rep(i,1,9)
	{
		rep(j,0,8)
		{
			int cnt=0,pos=0;
			rep(k,0,8)
				if (can[j][k][i]) cnt++,pos=k;
			if (cnt==1 && !a[j][pos]) {Sure(j,pos,i);return 1;}
		}
		rep(j,0,8)
		{
			int cnt=0,pos=0;
			rep(k,0,8)
				if (can[k][j][i]) cnt++,pos=k;
			if (cnt==1 && !a[pos][j]) {Sure(pos,j,i);return 1;}
		}
		for(int p=0;p<9;p+=3) for(int q=0;q<9;q+=3)
		{
			int cnt=0,posj=0,posk=0;
			rep(j,bl[p],br[p]) rep(k,bl[q],br[q])
				if (can[j][k][i]) cnt++,posj=j,posk=k;
			if (cnt==1 && !a[posj][posk]) {Sure(posj,posk,i);return 1;}
		}
	}
	return 0;
}

int count_1(int bit)
{
	int cnt=0;
	rep(i,0,8)
		if (bit&(1<<i)) cnt++;
	return cnt;
}

void Judge::Addbit(int x,int y)
{
	rep(i,0,8)
		if (!can[x][y][i+1] && (tmpbit&(1<<i))) tmpbit-=1<<i;
}

void Judge::Delbit(int x,int y)
{
	rep(i,0,8)
		if (can[x][y][i+1] && (tmpbit&(1<<i))) tmpbit-=1<<i;
}

void Judge::Addbit2(int x,int y)
{
	rep(i,0,8)
		if (can[x][y][i+1]) tmpbit|=1<<i;
}

int Judge::get_hash(int x,int y)
{
	int num=0;
	rep(i,1,9) num=num*2+can[x][y][i];
	return num;
}
void Judge::dfs(int w,int curtot,int bit,int limit)
{
	if (w>8)
	{
		if (curtot==limit) all.pb(bit);
		return;
	}
	if (curtot>limit) return;
	dfs(w+1,curtot,bit,limit);
	dfs(w+1,curtot+1,bit|(1<<w),limit);
}


int Judge::Naked(int tot)
{
	all.clear();
	dfs(0,0,0,tot);
	rep(i,0,8)
	{
		for(int p=0;p<(int)all.size();p++)
		{
			tmpbit=0;
			rep(j,0,8)
				if (all[p]&(1<<j)) Addbit2(i,j);
			if (count_1(tmpbit)==tot)
			{
				int ok=0;
				rep(j,0,8)
					if (!(all[p]&(1<<j)))
					{
						rep(k,0,8)
							if ((tmpbit&(1<<k)) && can[i][j][k+1]) can[i][j][k+1]=0,ok=1;
					}
				if (ok) return 1;
			}
		}
	}
	rep(i,0,8)
	{
		for(int p=0;p<(int)all.size();p++)
		{
			tmpbit=0;
			rep(j,0,8)
				if (all[p]&(1<<j)) Addbit2(j,i);
			if (count_1(tmpbit)==tot)
			{
				int ok=0;
				rep(j,0,8)
					if (!(all[p]&(1<<j)))
					{
						rep(k,0,8)
							if ((tmpbit&(1<<k)) && can[j][i][k+1]) can[j][i][k+1]=0,ok=1;
					}
				if (ok) return 1;
			}
		}
	}
	for(int u=0;u<=9;u+=3) for(int v=0;v<=9;v+=3)
	{
		for(int p=0;p<(int)all.size();p++)
		{
			tmpbit=0;
			rep(j,0,8)
				if (all[p]&(1<<j)) Addbit2(u+j/3,v+j%3);
			if (count_1(tmpbit)==tot)
			{
				int ok=0;
				rep(j,0,8)
					if (!(all[p]&(1<<j)))
					{
						rep(k,0,8)
							if ((tmpbit&(1<<k)) && can[u+j/3][v+j%3][k+1]) can[u+j/3][v+j%3][k+1]=0,ok=1;
					}
				if (ok) return 1;
			}
		}
	}


	return 0;
}

int Judge::Hidden(int tot)
{
	all.clear();
	dfs(0,0,0,tot);
	rep(i,0,8)
	{
		for(int p=0;p<(int)all.size();p++)
		{
			tmpbit=(1<<9)-1;
			rep(j,0,8)
				if (all[p]&(1<<j)) Addbit(i,j);
				else Delbit(i,j);
			if (count_1(tmpbit)==tot)
			{
				int ok=0;
				rep(j,0,8)
					if (all[p]&(1<<j))
					{
						rep(k,0,8)
							if (!(tmpbit&(1<<k)) && can[i][j][k+1]) can[i][j][k+1]=0,ok=1;
					}
				if (ok) return 1;
			}
		}
	}
	rep(i,0,8)
	{
		for(int p=0;p<(int)all.size();p++)
		{
			tmpbit=(1<<9)-1;
			rep(j,0,8)
				if (all[p]&(1<<j)) Addbit(j,i);
				else Delbit(j,i);
			if (count_1(tmpbit)==tot)
			{
				int ok=0;
				rep(j,0,8)
					if (all[p]&(1<<j))
					{
						rep(k,0,8)
							if (!(tmpbit&(1<<k)) && can[j][i][k+1]) can[j][i][k+1]=0,ok=1;
					}
				if (ok) return 1;
			}
		}
	}

	for(int u=0;u<=9;u+=3) for(int v=0;v<=9;v+=3)
	{
		for(int p=0;p<(int)all.size();p++)
		{
			tmpbit=(1<<9)-1;
			rep(j,0,8)
				if (all[p]&(1<<j)) Addbit(u+j/3,v+j%3);
				else Delbit(u+j/3,v+j%3);
			if (count_1(tmpbit)==tot)
			{
				int ok=0;
				rep(j,0,8)
					if (all[p]&(1<<j))
					{
						rep(k,0,8)
							if (!(tmpbit&(1<<k)) && can[u+j/3][v+j%3][k+1]) can[u+j/3][v+j%3][k+1]=0,ok=1;
					}
				if (ok) return 1;
			}
		}
	}
	return 0;
}

int Judge::Intersection()
{
	// grid -> row
	rep(num,1,9)
	{
		for(int p=0;p<9;p+=3) for(int q=0;q<9;q+=3)
		{
			rep(i,0,8) vis[i]=0;
			rep(i,0,2) rep(j,0,2)
				if (!a[bl[p]+i][bl[q]+j] && can[bl[p]+i][bl[q]+j][num]) vis[i]=1;
			int cnt=0,pos=0;
			rep(i,0,2) if (vis[i]) cnt++,pos=i;
			if (cnt==1)
			{
				int ok=0;
				rep(i,0,9)
					if (bl[i]!=q && can[bl[p]+pos][i][num]==1) ok=1,can[bl[p]+pos][i][num]=0;
				if (ok) return 1;
			}
		}
	}

	// grid -> column
	rep(num,1,9)
	{
		for(int p=0;p<9;p+=3) for(int q=0;q<9;q+=3)
		{
			rep(i,0,8) vis[i]=0;
			rep(i,0,2) rep(j,0,2)
				if (!a[bl[p]+i][bl[q]+j] && can[bl[p]+i][bl[q]+j][num]) vis[j]=1;
			int cnt=0,pos=0;
			rep(i,0,2) if (vis[i]) cnt++,pos=i;
			if (cnt==1)
			{
				int ok=0;
				rep(i,0,9)
					if (bl[i]!=p && can[i][bl[q]+pos][num]==1) ok=1,can[i][bl[q]+pos][num]=0;
				if (ok) return 1;
			}
		}
	}

	// row -> grid
	rep(num,1,9)
	{
		rep(i,0,8)
		{
			rep(j,0,8) vis[j]=0;
			rep(j,0,8)
				if (!a[i][j] && can[i][j][num]) vis[bl[j]]++;
			int cnt=0,pos=0;
			rep(j,0,8) if (vis[j]) cnt++,pos=j;
			if (cnt==1)
			{
				int ok=0;
				rep(p,bl[i],br[i])
					if (p!=i)
					{
						rep(q,bl[pos],br[pos])
							if (can[p][q][num]==1) ok=1,can[p][q][num]=0;
					}
				if (ok) return 1;
			}
		}
	}

	// column -> grid
	rep(num,1,9)
	{
		rep(i,0,8)
		{
			rep(j,0,8) vis[j]=0;
			rep(j,0,8)
				if (!a[j][i] && can[j][i][num]) vis[bl[j]]++;
			int cnt=0,pos=0;
			rep(j,0,8) if (vis[j]) cnt++,pos=j;
			if (cnt==1)
			{
				int ok=0;
				rep(p,bl[i],br[i])
					if (p!=i)
					{
						rep(q,bl[pos],br[pos])
							if (can[q][p][num]==1) ok=1,can[q][p][num]=0;
					}
				if (ok) return 1;
			}
		}
	}
	return 0;
}

/*
int X_wing()
{
	return 0;
}

int Swordfish()
{
	return 0;
}

int XY_wing()
{
	return 0;
}

int XYZ_wing()
{
	return 0;
}
*/

/*
int choose_one_from_two()
{
}
*/

void Judge::get_result()
{
    rep(i,0,14) tot[i]=0;
	while (Notsure>0)
	{
		if (Naked_Single()) tot[1]++;
		else if (Hidden_Single()) tot[2]++;
		else if (Naked(2)) tot[3]++; // Naked_Pair
		else if (Hidden(2)) tot[4]++; // Hidden_Pair
		else if (Naked(3)) tot[5]++; // Naked_Triplet
		else if (Hidden(3)) tot[6]++; // Hidden_Triplet
		else if (Naked(4)) tot[7]++; // Naked_Quad
		else if (Hidden(4)) tot[8]++; // Hidden_Quad
		else if (Intersection()) tot[9]++; // Intersection_Removel
        /*
		else if (X_wing()) tot[10]++;
		else if (Swordfish()) tot[11]++;
		else if (XY_wing()) tot[12]++;
		else if (XYZ_wing()) tot[13]++;
        */
		else {res=Impossible;return;}
	}
    /*
	puts("\n");
    */
    rep(i,1,14) cerr<<tot[i]<<" ";cerr<<endl;
    
	double D=0,up=0,down=0;
	rep(i,1,14) up+=tot[i]*w[i],down+=tot[i];
	if (down==0) {res=Easy;return;}
	D=sqrt(1.*up/down);
    cerr<<D<<endl;
	//printf("%.10lf\n",D);
	if (D<1.05) res=Easy;
	else if (D<1.5) res=Normal;
	else if (D<2.5) res=Hard;
	else res=Impossible;
    cerr<<res<<endl;
}


void Judge::init_can()
{
	Notsure=81;
	rep(i,0,8) rep(j,0,8) rep(k,0,9) can[i][j][k]=0;
	rep(i,0,8) rep(j,0,8)
	{
		if (a[i][j]==0) rep(k,1,9) can[i][j][k]=1;
		else can[i][j][a[i][j]]=1;
	}
	rep(i,0,8) rep(j,0,8)
		if (a[i][j]>0) Sure(i,j,a[i][j]);
}

/*
void print()
{
	rep(i,0,8)
	{
		rep(j,0,8) printf("%d",a[i][j]);
		puts("");
	}
}
*/

void Judge::In(int in[][15])
{
	w[1]=1; w[2]=5; w[3]=10; w[4]=15; w[5]=20; w[6]=25; w[7]=30; w[8]=35; w[9]=40; w[10]=500; w[11]=1000; w[12]=3000; w[13]=5000; w[14]=8000;
	rep(i,0,8) rep(j,0,8) a[i][j]=in[i][j];
	rep(i,0,8) bl[i]=i/3*3,br[i]=i/3*3+2;
	init_can();
	get_result();
}
int Judge::result()
{
	return res;
}

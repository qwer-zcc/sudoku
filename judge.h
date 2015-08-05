#ifndef JUDGE
#define JUDGE
#include <QWidget>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

class Judge : public QWidget
{
public:
    Judge(QWidget *parent=0);
    void In(int in[][15]);
    int result();
    void Sure(int x,int y,int c);
    int Naked_Single();
    int Hidden_Single();
    void Addbit(int x,int y);
    void Delbit(int x,int y);
    void Addbit2(int x,int y);
    int get_hash(int x,int y);
    void dfs(int w,int curtot,int bit,int limit);
    int Naked(int tot);
    int Hidden(int tot);
    int Intersection();
    void get_result();
    void init_can();
private:
    int can[15][15][15],a[15][15],w[15],bl[15],br[15],tot[15],vis[15];
    int Notsure,res,tmpbit;
    map<int,int> Hash;
    vector<int> all;
};

#endif // JUDGE


/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (300001)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

int n,m,k,ans;
vector<int> x[30001],y[30001];
vector<int>::iterator t;

void init(){
#ifdef Judge
	freopen("1628.in","r",stdin);
	freopen("1628.out","w",stdout);
//	SpeedUp;
#endif
	int i,j,a,b;
    scanf("%d%d%d",&n,&m,&k);
    for (ans=0,i=1;i<=n;++i)
    {
        y[i].push_back(0);
        y[i].push_back(m+1);
    }
    for (i=1;i<=m;++i)
    {
        x[i].push_back(0);
        x[i].push_back(n+1);
    }
    for (i=1;i<=k;++i)
    {
        scanf("%d%d",&a,&b);
        y[a].push_back(b);
        x[b].push_back(a);
    }
    for (i=1;i<=n;++i)  sort(y[i].begin(),y[i].end());
    for (i=1;i<=m;++i)  sort(x[i].begin(),x[i].end());
    for (i=1;i<=n;++i)
        for (j=1;j<y[i].size();++j)
            if (y[i][j]-y[i][j-1] > 2)
                ++ans;
            else if (y[i][j]-y[i][j-1] == 2)
            {
                a=y[i][j]-1;
                t=upper_bound(x[a].begin(),x[a].end(),i);
                b=*t;
                if (b-*(--t) == 2)  ++ans;
            }
    for (i=1;i<=m;++i)
        for (j=1;j<x[i].size();++j)
            if (x[i][j]-x[i][j-1] > 2)
                ++ans;
    printf("%d\n",ans);
		
}

int main(){
	init();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}

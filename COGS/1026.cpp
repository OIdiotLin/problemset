#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 505
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Node{
	int x,y;
};

int G[MAXN][MAXN],f[MAXN][MAXN];
Node s[MAXN*MAXN];
int R,C,Ans,N;

int cmp(const void *a,const void *b){
	return G[(*(Node*)a).x][(*(Node*)a).y]-G[(*(Node*)b).x][(*(Node*)b).y];
}

void init()
{
	int cnt=0;
	Ans=0;
	SpeedUp;
	#ifdef FILE
	freopen("shunzhi.in","r",stdin);
	freopen("shunzhi.out","w",stdout);
	#endif
	cin>>R>>C;
	N=R*C;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			cin>>G[i][j];
			s[cnt++]=(Node){i,j};
		}
	qsort(s,N,sizeof(Node),cmp);
}

void Dp()
{
	f[s[N-1].x][s[N-1].y]=1;
	for(int i=N-2;i>=0;i--)
	{
		int x=s[i].x;
		int y=s[i].y;
		if(x>0 && G[x-1][y]>G[x][y] && f[x-1][y]+1>f[x][y])
			f[x][y]=f[x-1][y];
		if(x<N-1 && G[x+1][y]>G[x][y] && f[x+1][y]+1>f[x][y])
			f[x][y]=f[x+1][y];
		if(y>0 && G[x][y-1]>G[x][y] && f[x][y-1]+1>f[x][y])
			f[x][y]=f[x][y-1];
		if(y<N-1 && G[x][y+1]>G[x][y] && f[x][y+1]+1>f[x][y])
			f[x][y]=f[x][y+1];
		f[x][y]++;
		if(f[x][y]>Ans)
			Ans=f[x][y];
	}
}

void work()
{
	init();
	Dp();
	cout<<Ans<<endl;
}

int main()
{
	work();
	return 0;
}


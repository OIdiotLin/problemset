#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 50
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N;
int f[MAXN][MAXN],T[MAXN][MAXN];
int Node[MAXN],Pre[MAXN];

void Make(int x,int y)
{
	if(T[x][y])
	{
		Pre[0]++;
		Pre[Pre[0]]=T[x][y];
	}
	if(T[x][y]>x)
		Make(x,T[x][y]-1);
	if(T[x][y]<y)
		Make(T[x][y]+1,y);
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("jfecs.in","r",stdin);
	freopen("jfecs.out","w",stdout);
	#endif
	memset(f,0,sizeof(f));
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>Node[i];
	}
	Pre[0]=0;
}

void Dp_Tree(int x,int y)
{
	int score,t1;
	
	if(x>y)
	{
		f[x][y]=1;
	}
	if(x==y)
	{
		f[x][y]=Node[x];
		T[x][y]=x;
	}
	if(x<y)
	{
		for(int i=x;i<=y;i++)
		{	if(f[x][i-1]==0)
				Dp_Tree(x,i-1);
			if(f[i+1][y]==0)
				Dp_Tree(i+1,y);
			score=f[x][i-1]*f[i+1][y]+Node[i];		//Merge the top L,top R
			if(score>f[x][y])
			{
				f[x][y]=score;
				t1=i;
			}
		}
		T[x][y]=t1;
	}
}

void work()
{
	init();
	Dp_Tree(1,N);
	cout<<f[1][N]<<endl;	//Question A
	
	Make(1,N);
	for(int i=1;i<=Pre[0];i++)
		cout<<Pre[i]<<" ";
	cout<<endl;
}

int main()
{
	work();
	return 0;
}


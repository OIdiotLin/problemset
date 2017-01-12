#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 200010
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
#define LINE "-------------------------------------------------------------------"
using namespace std;

struct TNode{
	int L,R;
	int x,y;
};

TNode T[MAXN];
int N,Q;

void Make(int L,int R,int k)
{
	T[k]=(TNode){L,R,0,INF};
	if(L<R)
	{
		Make(L,(L+R)>>1,k<<1);
		Make(((L+R)>>1)+1,R,(k<<1)+1);
	}
}

void Insert(int x,int i,int k)
{
	T[k].x=max(T[k].x,x);
	T[k].y=min(T[k].y,x);
	if(T[k].L!=T[k].R)
	{
		if(i<=((T[k].L+T[k].R)>>1))
			Insert(x,i,k<<1);
		else
			Insert(x,i,(k<<1)+1);
	}
}

void init()
{
	int height;
	SpeedUp;
	#ifdef FILE
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	#endif
	cin>>N>>Q;
	Make(1,N,1);
	for(int i=1;i<=N;i++)
	{
		cin>>height;
		Insert(height,i,1);
	}
	#ifdef Debug
	cout<<"Insert Successfully !"<<endl
		<<LINE<<endl
		<<"Num\t|\tL\t|\tR\t|\tx\t|\ty"<<endl
		<<LINE<<endl;
	for(int i=1;i<=N;i++)
		cout<<i<<"\t|\t"<<T[i].L<<"\t|\t"<<T[i].R<<"\t|\t"<<T[i].x<<"\t|\t"<<T[i].y<<endl;
	cout<<LINE<<endl;
	#endif
}

void Question(int L,int R,int &x0,int &y0,int k)
{
	int xL,xR,yL,yR;
	xL=xR=0;
	yL=yR=INF;
	
	if(L<=T[k].L && R>=T[k].R)
	{
		x0=T[k].x;
		y0=T[k].y;
		return;
	}
	if(L<=((T[k].L+T[k].R)>>1))
		Question(L,R,xL,yL,k<<1);
	if(R>((T[k].L+T[k].R)>>1))
		Question(L,R,xR,yR,(k<<1)+1);
	x0=max(xL,xR);
	y0=min(yL,yR);
}

void work()
{
	while(Q--)
	{
		int A,B,x0=0,y0=INF;
		cin>>A>>B;
		Question(A,B,x0,y0,1);
		cout<<x0-y0<<endl;
	}
}

int main()
{
	init();
	work();
	return 0;
}

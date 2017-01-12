#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#define MAXN 1505
#define MAXM 1005
#define INF 0x7FFFFFFF
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

struct Edge{
	int T,W;
	Edge *next;
};
struct Node{
	int S,c;
	int W[2];		//0 means L     1 means R.
	Node *F[2];
};

Edge E[2*MAXN],*V[MAXN];
Node Cave[MAXN];
int N,M,cnt;
int f[MAXN][MAXM];
int Ans;

void AddE(int Start,int Target,int Weight)
{
	E[++cnt].next=V[Start];
	V[Start]=E+cnt;
	V[Start]->T=Target;	
	V[Start]->W=Weight;
}

void Make(Node &k,int Rt)
{
	int i=&k-Cave,tmp;
	k.c=0;
	k.S=1;
	for(Edge *e=V[i];e;e=e->next)
	{
		tmp=e->T;
		if(tmp==Rt)
			continue;
		k.W[k.c]=e->W;
		Make(Cave[tmp],i);
		k.F[k.c]=Cave+tmp;
		k.S+=k.F[k.c]->S;
		k.c++;
	}
}

void init()
{
	int s,t,w;
	SpeedUp;
	#ifdef FILE
	freopen("hole.in","r",stdin);
	freopen("hole.out","w",stdout);
	#endif
	cnt=0;
	memset(f,-1,sizeof(f));
	cin>>N>>M;
	for(int i=1;i<=N-1;i++)
	{
		cin>>s>>t>>w;
		AddE(s,t,w);
		AddE(t,s,w);
	}
	Make(Cave[1],0);			//0 means root.
	#ifdef Debug
	cout<<"Make BTree END!"<<endl;
	#endif
}

int DpTree(int i,int x)		//The root is i, under which put x Node;
{
	if(f[i][x]==-1)
	{
		int rest,t1,t2;
		if(x==0)				//didn't put any equipments. 
			rest=0;
		else
		{
			switch(Cave[i].c)
			{
				case 0:{
					rest=(x==1 ? 0 : INF);
					break;
				}
				case 1:{
					rest=(x-1)*(M-(x-1))*Cave[i].W[0];	//left
					t1=Cave[i].F[0]-Cave;
					rest+=DpTree(t1,x-1);
					break;
				}
				default :{
					int restX,ReB=0;
					t1=Cave[i].F[0]-Cave;
					t2=Cave[i].F[1]-Cave;
					ReB=max(ReB,x-Cave[t2].S-1);
					for(rest=INF;ReB<=x-1 && ReB<=Cave[t1].S;ReB++)
					{
						restX=DpTree(t1,ReB)+DpTree(t2,x-ReB-1);
						restX+=(ReB*(M-ReB)*Cave[i].W[0]+(x-ReB-1)*(M-(x-ReB-1))*Cave[i].W[1]);
						rest=min(rest,restX);
					}
					break;
				}
			}
		}
		f[i][x]=rest;
	}
	return f[i][x];
}

void work()
{
	init();
	Ans=DpTree(1,M);
	#ifdef Debug
	cout<<Ans<<endl;
	#endif
	double S=(double)M*(M-1)/2.0;
	cout<<fixed<<setprecision(2)<<(double)Ans/S<<endl;
}

int main()
{
	work();
	return 0;
}


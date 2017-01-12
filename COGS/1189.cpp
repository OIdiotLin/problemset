#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 3010
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

struct TNode{
	int num,cost;
	TNode *next;
};

int N,M,Ans;
int f[MAXN][MAXN],Profit[MAXN],ChildNum[MAXN];
TNode child[MAXN];

inline int Min(int a,int b){return a>b ? b : a;}
inline int Max(int a,int b){return a>b ? a : b;}

void Add_Node(int A,int C,TNode &p)
{
	TNode *t=new(TNode);
	t->num=A;
	t->cost=C;
	t->next=p.next;
	p.next=t;
}


void init()
{
	int group,r1,r2;
	SpeedUp;
	#ifdef FILE
	freopen("televi.in","r",stdin);
	freopen("televi.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			f[i][j]=-INF;
	for(int i=1;i<=N-M;i++)		//Repeater
	{
		cin>>group;
		for(int j=1;j<=group;j++)
		{
			cin>>r1>>r2;
			Add_Node(r1,r2,child[i]);
		}
	}
	for(int i=N-M+1;i<=N;i++)
		cin>>Profit[i];
	#ifdef Debug
	cout<<"Reading Data Successfully!!"<<endl
		<<"---------------------------"<<endl;
	#endif
	Ans=0;
}

void Get(int x)
{	
	int tmpNum,tmpCost;
	if(x>N-M)	//жу╤к 
	{
		f[x][1]=Profit[x];
		ChildNum[x]=1;
		return;
	}
	TNode *t=child[x].next;
	#ifdef Debug
	cout<<"\t Get("<<x<<"): x <= N-M  ("<<N-M<<")"<<endl;
	#endif
	while(t)
	{
		tmpNum=t->num;
		tmpCost=t->cost;
		Get(tmpNum);
		ChildNum[x]+=ChildNum[tmpNum];
		t=t->next;
	}
	t=child[x].next;
	while(t)
	{
		tmpNum=t->num;
		tmpCost=t->cost;
		for(int i=ChildNum[x];i;i--)
			for(int j=Min(ChildNum[tmpNum],i);j>=0;j--)
			{
				f[x][i]=Max(f[x][i],f[tmpNum][j]+f[x][i-j]-tmpCost);
			}
		t=t->next;
	}
}

void work()
{
	Get(1);
	for(int i=1;i<=M;i++)
	{
		if(f[1][i]>=0)
			if(i>Ans)
			{
				Ans=i;
			}
	}
	cout<<Ans<<endl; 
}

int main()
{
	init();
	work();	
	return 0;
}


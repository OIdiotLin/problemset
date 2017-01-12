#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 50
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

struct fCake{
	int V,S;
};
fCake C[MAXN];
int M,N,Ans;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	#endif
	Ans=INF;
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{
		C[M-i+1]=(fCake){C[M-i+2].V+i*i*i,C[M-i+2].S+2*i*i};
	}
	C[1].S+=M*M;
	#ifdef Debug
	{
		for(int i=1;i<=M;i++)
			cout<<C[i].V<<"\t"<<C[i].S<<endl;
	}
	#endif
}

void dfs(fCake k,int r,int h,int X)
{
	#ifdef Debug
	cout<<"dfs( "<<k.V<<" (V), "<<k.S<<" (S), "<<r<<" , "<<h<<" , "<<X<<" ) Start."<<endl;
	#endif
	if(k.V>N || (k.V==N && X<=M) || k.S<0 || k.V<0)
		return;
	if(X==M+1)
	{
		if(k.V==N)
			Ans=min(Ans,k.S);
		return;
	}
	if(k.V+C[X].V>N || k.S+C[X].S>Ans || Ans<=((N-k.V)<<1)/r+k.S)
		return;
		
	fCake tmpC={0,0};
	int restV=N-k.V-C[X+1].V;
	for(int i=r-1;i>=M-X+1 && i;i--)
	{
		
		if(X==M)
		{
			if(restV%(i*i)==0)
			{
				int t=restV/(i*i);
				if(t>=h)
					continue;
				tmpC.S=k.S+i*t*2;
				if(X==1)
					tmpC.S+=i*i;	//减去下底面 
				tmpC.V=k.V+i*i*t;
				dfs(tmpC,i,t,X+1);
			}
			continue;
		}
		int t=min(restV/(i*i),h-1);
		for(int j=t;j>=M-X+1;j--)
		{
			tmpC.S=k.S+i*j*2;
			if(X==1)
				tmpC.S+=i*i;		//减去下底面
			tmpC.V=k.V+i*i*j;
			dfs(tmpC,i,j,X+1); 
		}
	}
}

void work()
{
	dfs((fCake){0,0},N,N,1);
	cout<<((Ans==INF) ? 0 : Ans)<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


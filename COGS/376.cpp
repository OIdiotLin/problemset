#include <iostream>
#include <cstring>
#include <cstdio>
#include <deque>
#define MAXN 5010
#define SpeedUp ios::sync_with_stdio(false)
#define pb push_back
#define Debug
#define FILE
using namespace std;

int N,S;
deque<int> Q;
int d[MAXN],T[MAXN],F[MAXN];
int f[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("batch.in","r",stdin);
	freopen("batch.out","w",stdout);
	#endif
	memset(d,0,sizeof(d));
	memset(T,0,sizeof(T));
	memset(F,0,sizeof(F));
	memset(f,0,sizeof(f));
	cin>>N>>S;
	for(int i=1;i<=N;i++)
	{
		cin>>T[i]>>F[i];
		T[i]+=T[i-1];
	}
	for(int i=N;i;i--)
		f[i]=f[i+1]+F[i];
		
}

int Cal(int a,int b){return T[b]-T[a-1];}

void Dp()
{
	Q.pb(N+1);
	f[N+1]=0;
	for(int i=N;i;i--)
	{
		while(Q.size()>1 && f[i]*Cal(Q[1],Q[0]-1)>=d[Q[1]]-d[Q[0]])
			Q.pop_front();
		d[i]=d[Q[0]]+f[i]*(S+Cal(i,Q[0]-1));
		while(Q.size()>1)
		{
			int real=(d[i]-d[Q[Q.size()-1]])*Cal(Q[Q.size()-1],Q[Q.size()-2]-1);
			int want=(d[Q[Q.size()-1]]-d[Q[Q.size()-2]])*Cal(i,Q[Q.size()-1]-1);
			if(real<=want)
				Q.pop_back();
			else 
				break;
		}
		Q.pb(i);
	}
}

void work()
{
	Dp();
	cout<<d[1]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


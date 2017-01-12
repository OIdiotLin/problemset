#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 65
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,M,L,Sum;
int stick[MAXN];
bool vis[MAXN];
inline bool cmp(int a,int b){return a>b;}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("sticka.in","r",stdin);
	freopen("sticka.out","w",stdout);
	#endif
	cin>>N;
	Sum=0;
	for(int i=1;i<=N;i++){
		cin>>stick[i];
		Sum+=stick[i];
	}
	sort(stick+1,stick+N+1,cmp);
}

bool dfs(int S,int k,int cur){
	if(cur==M) return true;
	if(S==L) return dfs(0,1,cur+1);
	int t=0,i;
	for(i=k;i<=N;i++){
		if(vis[i] && stick[i]!=t && stick[i]+S<=L){
			t=stick[i];
			vis[i]=false;
			if(dfs(S+stick[i],i+1,cur)) break;
			vis[i]=true;
			#ifdef Debug
			cout<<"Stick["<<i<<"] is "<<Stick[i]<<endl;
			#endif
			if(k==1) return false;
		}
	}
	if(i==N+1)return false;
	return true;
}

void work()
{
	for(L=stick[1];L<=Sum;L++){
		if(Sum%L==0){
			M=Sum/L;
			memset(vis,true,sizeof(vis));
			if(dfs(0,1,0)) break;
		}
	}
	cout<<L<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


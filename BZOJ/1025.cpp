#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 1005
#define MAXM 200
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
#define Debug
using namespace std;
typedef long long LL;

int N;
int cnt;
bool v[MAXM][MAXN];
LL f[MAXM][MAXN];
int P[MAXM];

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
	cnt=0;
	for(int i=2;i<=N;i++){
		bool o=true;
		for(int j=2;j*j<=i;j++)
			if(i%j==0){
				o=false;
				break;
			}
		if(o)
			P[++cnt]=i;
	}
	#ifdef Debug
	cout<<"Init END"<<endl;
	#endif
}

LL dfs(int k,int s){
	#ifdef Debug
	cout<<"dfs("<<k<<","<<s<<")"<<endl;
	#endif
	if(v[k][s]){
		return f[k][s];
	}
	v[k][s]=true;
	if(k==0){
		f[k][s]=1;
		return 1;
	}
	int t=P[k];
	f[k][s]=dfs(k-1,s);
	for(;t<=s;t*=P[k]){
		f[k][s]+=dfs(k-1,s-t);
	}
	return f[k][s];
}

int main()
{
	init();
	cout<<dfs(cnt,N)<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(v)+sizeof(P)+sizeof(f))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


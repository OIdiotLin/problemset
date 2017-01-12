/*
	Work on OIdiot's PC
	System: Ubuntu 14.04 Kylin
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (105)
#define INF (0x7fffffff)
const double PI=acos(-1);
const int ZCY=1000000007;

int N,tot;
int s[MAXN];

void init(){
	#ifdef Judge
	freopen("hospital.in","r",stdin);
	freopen("hospital.out","w",stdout);
	SpeedUp;
	#endif
	cin>>N;
	memset(dist,0x7fffffff,sizeof(dist));
	for(int i=1;i<=N;i++){
		cin>>s[i]>>x>>y;
		dist[i][i]=0;
		if(x) dist[i][x]=dist[x][i]=1;
		if(y) dist[i][y]=dist[y][i]=1;
	}
}

void floyd(){
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++){
			if(i==k) continue;
			for(int j=1;j<=N;j++)
				if(i!=j && k!=j)
					dist[k][j]=min(dist[k][j],dist[k][i]+dist[j][i]);
		}
}

void work(){
	floyd();
	for(int i=1;im=AJ

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
	#endif
	return 0;
}
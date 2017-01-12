#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 205
#define MAXV 5005
#define MAXK 55
#define INF (1<<28)
#define MIN (-0xf)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

struct Item{
	int Value,Weight;
}A[MAXN];

int K,V,N,Ans;
int f[MAXK][MAXV*100],d[2][MAXK];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("bags.in","r",stdin);
	freopen("bags.out","w",stdout);
	#endif
	cin>>K>>V>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i].Weight>>A[i].Value;
	}
	memset(f,MIN,sizeof(f));
	Ans=0;
}

void Dp()
{
	f[1][0]=0;
	int C0,C1,cnt;
	for(int t=1;t<=N;t++){
		for(int i=V;i>=A[t].Weight;i--){
			for(int j=1;j<=K;j++){
				d[0][j]=f[j][i];
				d[1][j]=f[j][i-A[t].Weight]+A[t].Value;
			}
			for(C0=1,C1=1,cnt=1;cnt<=K;cnt++){
				if(d[0][C0]>d[1][C1]){
					f[cnt][i]=d[0][C0];
					C0++;
				}
				else{
					f[cnt][i]=d[1][C1];
					C1++;
				}
			}
		}
	}
	for(int i=1;i<=K;i++){
		Ans+=f[i][V];
	}
}

int main()
{
	init();
	Dp();
	cout<<Ans<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(sizeof(f)+sizeof(d)+sizeof(A))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


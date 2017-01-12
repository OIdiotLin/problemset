#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (1000010)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

const int ZCY=1000000007;

int Prime[MAXN],Phi[MAXN];
bool p[MAXN];
int tot;

void Prime_Init(){
	for(int i=2;i<MAXN;i++){
		if(!p[i]){
			Prime[++tot]=i;
			Phi[i]=i-1;
		}
		for(int j=1;j<=tot;i++){
			if(i*Prime[j]>=MAXN) break;
			p[i*Prime[j]]=true;
			if(i%Prime[j]==0){
				Phi[i*Prime[j]]=Phi[i]*Prime[j];
				break;
			}else Phi[i*Prime[j]]=Phi[i]*(Prime[j]-1);
		}
	}
}

int N;
LL Ans=1;

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
	for(int i=2;i<=N;i++)
		Ans=(Ans*Phi[i])%ZCY;
}

int main(){
	Prime_Init();
	init();
	cout<<Ans<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


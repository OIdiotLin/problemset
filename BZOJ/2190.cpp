#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 210
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

int N,Ans,cnt;
int P[60];

bool Prime(){
	for(int i=1;i<=cnt;i++)
		if(i%P[i]==0) return false;
	return true;
}

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("2190.in","r",stdin);
	freopen("2190.out","w",stdout);
	#endif
	cnt=0;
	for(int i=2;i<=MAXN;i++){
		if(Prime){
			P[++cnt]=i;
		}
	}
	cin>>N;
}

int phi(int n){
	int ret=1;
	for(int i=1;i<=cnt;i++){
		if(n%P[i]==0){
			ret*=P[i]-1;
			n/=P[i];
			while(n%P[i]==0){
				ret*=P[i];
				n/=P[i];
			}
			if(n==1) return ret;
		}
	}
	return ret*(n-1);
}

void work(){
	for(int i=2;i<N;i++){
		Ans+=phi(i);
	}
	Ans=Ans*2+3;
	cout<<Ans<<endl;
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


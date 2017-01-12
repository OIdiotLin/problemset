#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 100005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
#define pb(i) push_back(i)
using namespace std;
typedef long long LL;

int T,N;
int Phi[MAXN],f[MAXN];

void init()
{
	vector<int> p;
	#ifdef FILE
	SpeedUp;
	freopen("alien.in","r",stdin);
	freopen("alien.out","w",stdout);
	#endif
	cin>>T;
	for(int i=2;i<MAXN;i++){
		if(!Phi[i]){
			Phi[i]=i-1;
			p.pb(i);
		}
		for(int j=0;(LL)(i)*p[j]<MAXN;j++){
			if(i%p[j])
				Phi[i*p[j]]=Phi[i]*(p[j]-1);
			else{
				Phi[i*p[j]]=Phi[i]*p[j];
				break;
			}
		}
	}
	for(int i=2;i<MAXN;i++){
		f[i]=((i&1) ? f[Phi[i]] : f[i>>1]+1);
	}
}

void work(){
	int p,q;
	#ifdef Debug
	cout<<"T="<<T<<endl;
	#endif
	while(T--){
		cin>>N;
		bool F=false;				//Base = 2;
		LL Ans=0;
		for(int i=1;i<=N;i++){
			#ifdef Debug
			cout<<"cnt="<<i<<endl;
			#endif
			cin>>p>>q;
			if(p==2) F=true;
			Ans+=(LL)(q)*f[p];
		}
		cout<<Ans+!F<<endl;
	}
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(f)+sizeof(Phi))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


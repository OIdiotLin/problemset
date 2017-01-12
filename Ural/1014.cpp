#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
//#define Debug
using namespace std;
typedef long long LL;

int N;
string s;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
}

void work(){
	if(N==0){
		cout<<10<<endl;
	}
	else if(N==1){
		cout<<1<<endl;
	}
	else{
		for(int i=9;i>=2;i--){
			while(N%i==0){
				N/=i;
				#ifdef Debug
				cout<<"N = "<<N<<endl;
				#endif
				s=(char)(i+'0')+s;
			}
		}
		if(N>10) cout<<-1<<endl;
		else cout<<s<<endl;
	}
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(s))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


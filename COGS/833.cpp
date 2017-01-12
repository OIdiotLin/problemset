#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

struct cmp{
	bool operator ()(int a,int b)
	{
		return a>b;
	}
};

priority_queue <int> Q;
int N,K;
int S[105];

void init()
{
	int a;
	#ifdef FILE
	SpeedUp;
	freopen("humble.in","r",stdin);
//	freopen("humble.out","w",stdout);
	#endif
	cin>>K>>N;
	for(int i=1;i<=K;i++){
		cin>>S[i];
	}
}

void work(){
	int x;
	for(int i=1;i<=K;i++)
		Q.push(1*S[i]);
	for(int i=1;i<=N;i++){
		x=Q.top();
		while(1){
			Q.pop();
			if(x!=Q.top()) break;
		}
		for(int j=1;j<=K;j++){
			int t=x*S[j];
			Q.push(x*S[j]); 
		}
	}
	cout<<x<<endl;
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


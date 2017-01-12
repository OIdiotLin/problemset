#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 1000005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,Min,Max;
bool Time[MAXN];
int Ans0,Ans1;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	#endif
	memset(Time,false,sizeof(Time));
	cin>>N;
	Min=INF,Max=0;
	Ans0=Ans1=0;
	for(int i=1;i<=N;i++){
		int begin,end;
		cin>>begin>>end;
		Min=min(begin,Min);
		Max=max(Max,end);
		for(int t=begin;t<end;t++)
			Time[t]=true;
	}
}

void work(){
	bool t=Time[Min];
	int S=1;
	int i;
	for(i=Min+1;i<Max;i++){
		if(t!=Time[i]){
			if(t) Ans0=max(Ans0,S);
			else  Ans1=max(Ans1,S);
			t=Time[i];
			S=1;
		}
		else S++;
	}
	if(t!=Time[i]){
			if(t) Ans0=max(Ans0,S);
			else  Ans1=max(Ans1,S);
			t=Time[i];
			S=1;
	}
	cout<<Ans0<<" "<<Ans1<<endl;
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


#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 10005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct data{
	int Len,Freq;
	int Calc(){
		return Len*Freq;
	}
}Data[MAXN];
inline bool cmp(int a,int b){
	return Data[a].Calc()>Data[b].Calc();
}

int O[MAXN];
int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("linstorage.in","r",stdin);
	freopen("linstorage.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>Data[i].Len>>Data[i].Freq;
		O[i]=i;
	}
	sort(O+1,O+N+1,cmp);
}

void work(){
	for(int i=1;i<=N;i++)
		cout<<O[i]<<" ";
	cout<<endl;
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


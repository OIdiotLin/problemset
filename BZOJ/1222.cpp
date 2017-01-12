#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 6005
#define MAXM 30005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

struct Data{
	int t1,t2,t3;
}A[MAXN];

int Min(int a,int b){
	if(a==0)return b;
	if(b==0)return a;
	return (a>b ? b: a);
}

int Min(int a,int b,int c){
	return Min(a,min(b,c));
}

int f[MAXM];
int N,M;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("1222.in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
	cin>>N;
	M=0;
	for(int i=1;i<=N;i++){
		cin>>A[i].t1>>A[i].t2>>A[i].t3;
		M+=Min(A[i].t1,A[i].t2,A[i].t3);
	}
}

void Dp(){
	for(int i=1;i<=N;i++){
		for(int j=M;j>=0;j--){
			int t=INF;
			if ((A[i].t1)&&(j-A[i].t1>=0))
				t=min(t,f[j-A[i].t1]);
			if (A[i].t2>0)
				t=min(t,f[j]+A[i].t2);
			if ((A[i].t3>0)&&(j-A[i].t3>=0))
				t=min(t,f[j-A[i].t3]+A[i].t3);
			f[j]=t;
		}
	}
	int Ans=INF;
	for(int i=0;i<=M;i++){
		if(Ans>max(i,f[i]))
			Ans=max(i,f[i]);
	}
	cout<<Ans<<endl;
}

int main()
{
	init();
	Dp();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


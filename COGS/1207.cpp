#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define MAXN 50
#define MAXM 1605
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

int A[MAXN],S[MAXN];
bool f[MAXM][MAXM];
int N;
double Ans;

inline void rank(int a,int b,int c){
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
}

inline double Sq(int a,int b,int c){
	if(a+b<c || a==0) return 0;
	double p=(double)(a+b+c)/2.0;
	double ret=sqrt(p*(p-a)*(p-b)*(p-c));
	return ret;
}

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("pasture.in","r",stdin);
	freopen("pasture.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		S[i]=S[i-1]+A[i];
	}
	f[A[1]][0]=f[0][A[1]]=f[0][0]=true;
	Ans=0.0;
}

void work(){
	for(int i=2;i<=N;i++)
		for(int j=S[i];j>=0;j--)
			for(int k=S[i];k>=0;k--){
				if(j-A[i]>=0 && f[j-A[i]][k])
					f[j][k]=true;
				if(k-A[i>=0] && f[j][k-A[i]])
					f[j][k]=true;
			}
	for(int i=1;i<=S[N];i++){
		for(int j=1;j<=S[N];j++)
			if(f[i][j]){
				Ans=max(Ans,Sq(i,j,S[N]-i-j));
				#ifdef Debug
				cout<<"f["<<i<<"]["<<j<<"]"<<Ans<<endl;
				#endif
			}
	}
	cout<<(Ans==0 ? -1 :(int)(Ans*100))<<endl;
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


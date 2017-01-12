#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 1005
#define INF (0x7fffffff)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

int N,Ans;
int A[MAXN];

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("baseballa.in","r",stdin);
	freopen("baseballa.out","w",stdout);
	#endif
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	sort(A,A+N);
	A[N]=INF;
	Ans=0;
	#ifdef Debug
	for(int i=0;i<=N;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	#endif
}

int BinSearch(int x,int L,int R){
	if(L>=R) return L;
	int mid=(L+R>>1);
	if(A[mid]<x)
		return BinSearch(x,mid+1,R);
	else
		return BinSearch(x,L,mid);
}

int Count(int a,int b){
	return BinSearch(b+1,0,N)-BinSearch(a,0,N);
}

void work(){
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			int t=A[j]-A[i];
			Ans+=Count(A[j]+t,A[j]+2*t);
			#ifdef Debug
			cout<<"A["<<j<<"] - A["<<i<<"] = "<<t<<endl;
			#endif
		}
	}
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(A))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


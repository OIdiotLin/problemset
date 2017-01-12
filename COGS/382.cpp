#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstring>
#define SpeedUp ios::sync_with_stdio(false)
#define BigN_MAXN 50000
#define MAXN 10005
#define INF (1<<28)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

double A[MAXN],B[MAXN];
int N;
void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("sortt.in","r",stdin);
	freopen("sortt.out","w",stdout);
	#endif
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
}

int Merge(int L,int M,int R){
	memcpy(B+L,A+L,(R-L+1)*sizeof(double));
	int i=L,j=M+1,k=L;
	int ret=0;
	while(i<=M && j<=R){
		if(B[i]<=B[j])
			A[k++]=B[i++];
		else{
			A[k++]=B[j++];
			ret+=(M-i+1);
		}
	}
	while(i<=M)	A[k++]=B[i++];
	while(j<=R)	A[k++]=B[j++];
	return ret;
}

int work(int L,int R){
	int ret=0;
	if(L<R){
		int M=(L+R)/2;
		ret+=work(L,M);
		ret+=work(M+1,R);
		ret+=Merge(L,M,R);
	}
	return ret;
}

int main(){
	init();
	cout<<work(0,N-1)<<endl;
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<endl;
	#endif
	return 0;
}

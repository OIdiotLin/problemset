#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 100005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,K;
int A[MAXN],S[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("seqa.in","r",stdin);
	freopen("seqa.out","w",stdout);
	#endif
	cin>>N>>K;
	S[0]=0;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		S[i]=S[i-1]+A[i];
	}
}

void work()
{
	int L=0,R=S[N],Mid=(L+R)>>1;
	
	while(L<R){
		int t=0,cnt=0;
		bool P=true;
		for(int i=1;i<=N;i++)
			if(S[i]-S[t]>Mid){
				i--,cnt++;
				if(cnt==K){
					P=false;
					break;
				}
				t=i;
			}
		if(P){
			R=Mid;
			Mid=(R+L)>>1;
		}
		else{
			L=Mid+1;
			Mid=(L+R)>>1;
		}
	}
	cout<<Mid<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


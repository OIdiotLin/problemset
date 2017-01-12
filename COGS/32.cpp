#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 200
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int N,M,S;
int f[MAXN][MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("bit.in","r",stdin);
	freopen("bit.out","w",stdout);
	#endif
	cin>>N>>M;
	#ifdef Debug
	cout<<"N,M END"<<endl;
	#endif
	S=M*N;		//Whole Size.
	string st;
	for(int i=1;i<=N;i++){
		cin>>st;
		for(int j=0;j<M;j++){
			if(st[j]=='1') S--;
			if(st[j]=='0') f[i][j+1]=INF;
			#ifdef Debug
			cout<<st[j]<<" ";
			#endif
		}
		#ifdef Debug
		cout<<endl;
		#endif
	}
	#ifdef Debug
	cout<<"Reading END"<<endl;
	#endif
}

void Search(){
	int t=0;
	while(S){
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				if(f[i][j]==t){
					if(i>=2 && t+1<f[i-1][j]){		//Up
						f[i-1][j]=t+1;
						S--;
					}
					if(i<N && t+1<f[i+1][j]){		//Down
						f[i+1][j]=t+1;
						S--;
					}
					if(j>=2 && t+1<f[i][j-1]){		//Left
						f[i][j-1]=t+1;
						S--;
					}
					if(j<M && t+1<f[i][j+1]){		//Right
						f[i][j+1]=t+1;
						S--;
					}
				}
		t++;
		#ifdef Debug
		cout<<S<<endl;
		#endif
	}
	#ifdef Debug
	cout<<"Working END"<<endl;
	#endif
}

void Out()
{
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	init();
	Search();
	Out();
	return 0;
}


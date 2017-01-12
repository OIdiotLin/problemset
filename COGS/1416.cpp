#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 5010
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

char G[MAXN][MAXN];
int N;
int x,y;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("mrz.in","r",stdin);
	freopen("mrz.out","w",stdout);
	#endif
	cin>>N;
	string s;
	for(int i=0;i<N;i++){
		cin>>s;
		for(int j=0;j<N;j++){
			if(s[j]=='Z'){
				x=i+1,y=j+1;
			}
			G[i+1][j+1]=s[j];
		}
	}
	#ifdef Debug
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout<<G[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Z is on x="<<x<<" ,y="<<y<<endl;
	#endif
}

void work(){
	int ret=0;
	if(x!=1)
	for(int i=x-1;i&&G[i][y]!='+';i--){
		if(G[i][y]=='S') ret++;
	}
	
	if(x!=N)
	for(int i=x+1;i<=N&&G[i][y]!='+';i++){
		if(G[i][y]=='S') ret++;
	}

	if(y!=1)
	for(int i=y-1;i&&G[x][i]!='+';i--){
		if(G[x][i]=='S') ret++;
	}

	if(y!=N)
	for(int i=y+1;i<=N&&G[x][i]!='+';i++){
		if(G[x][i]=='S') ret++;
	}

	cout<<ret<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(sizeof(G))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


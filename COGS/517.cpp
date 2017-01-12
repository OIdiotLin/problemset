#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 10010
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

int W,N;
LL G[MAXN][MAXN]={0};

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("locust.in","r",stdin);
	freopen("locust.out","w",stdout);
	#endif
	cin>>W>>N;
}

void Insert()
{
	int x, y,z;
	cin>>x>>y>>z;
	G[x][y]+=z;
}

void Query()
{
	int x1,x2,y1,y2;
	LL ret=0;
	cin>>x1>>y1>>x2>>y2;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++){
			ret+=G[i][j];
		}
	cout<<ret<<endl;
}

void work()
{
	int o;
	while(N--){
		cin>>o;
		switch(o){
			case 1:{
				Insert();
				break;
			}
			case 2:{
				Query();
				break;
			}
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}


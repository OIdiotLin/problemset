#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 2505
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

int f[MAXN][5];
int N;
void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("quad.in","r",stdin);
	freopen("quad.out","w",stdout);
	#endif
	cin>>N;
}

void work(){
	for(int i=1;i<=N;i++)
		for(int j=1;j<=4;j++){
			if(j==1 || i==j)
				f[i][j]=1;
			else if(i<j)
				f[i][j]=0;
			else {
				for(int k=1;k<i;k++){
					if(k>=(N+1)>>1 || (i-k)>=(N+1)>>1 && j==2)
						continue;
					else 
						f[i][j]+=f[i-k][j-1];
				}
			}
		}
	cout<<f[N][4]<<endl;
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


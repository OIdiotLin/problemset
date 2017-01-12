#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN (50)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

bool is_pal(int a,int b){
	int X=a*b;
	int ReX=0,tmp=0,tmpX=X;
	while(tmpX){
		tmp=tmpX%10;
		ReX=ReX*10+tmp;
		tmpX/=10;
	}
	return (X==ReX) ? true :false;
}

void work()
{
	int Ans=0;
	for(int i=100;i<=999;i++)
		for(int j=100;j<=999;j++)
		{
			if(is_pal(i,j))
				Ans=max(Ans,i*j);
		}
	cout<<Ans<<endl;
}

int main()
{
	work();
	return 0;
}


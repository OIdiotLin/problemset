#include <iostream>
#include <cstring>
#define MAXN 110 
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("numgame.in","r",stdin);
	freopen("numgame.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
		a[i+N]=a[i];
	}
	for()
}

int main()
{
	
	return 0;
}


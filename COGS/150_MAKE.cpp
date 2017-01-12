#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define MAXN
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

void init()
{
	SpeedUp;
	#ifdef FILE
//	freopen(".in","r",stdin);
	freopen("bcl.in","w",stdout);
	#endif
}

int main()
{
	init();
	cout<<30000<<endl;
	for(int i=0;i<30000;i++)
	{
		cout<<(char)('A'+(rand()%26))<<endl;
	}
	return 0;
}


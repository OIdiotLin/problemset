#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

string S;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("8.in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
	cin>>S;
}

int Value(int L)
{
	int ret=1;
	for(int p=L;p<L+5;p++)
	{
		ret*=(int)(S[p]-'0');
	}
	return ret;
}

void work(){
	int MAX=-INF;
	for(int i=1;i<S.length()-5;i++)
	{
		MAX=max(MAX,Value(i));
	}
	cout<<MAX<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 105
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

string S[MAXN];
int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("letter.in","r",stdin);
	freopen("letter.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>S[i];
	sort(S+1,S+N+1);
}

void Out()
{
	for(int i=1;i<=N;i++)
		cout<<S[i]<<endl;
}

int main()
{
	init();
	Out();
	return 0;
}


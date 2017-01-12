#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 30
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;


int T;
char hash[MAXN]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b',\
				 'k','r','z','t','n','w','j','p','f','m','a','q'};

void init()
{
//	SpeedUp;
	#ifdef FILE
	freopen("2012a.in","r",stdin);
	freopen("2012a.out","w",stdout);
	#endif
	scanf("%d\n",&T);
	//cin>>T;
}

void work()
{
	string Origin;
	getline(cin,Origin);
	for(int i=0;i<Origin.size();i++)
	{
		if(Origin[i]==' ')
		{
			cout<<" ";
			continue;
		}
		cout<<hash[Origin[i]-'a'];
	}
	cout<<endl;
}

int main()
{
	init();
	for(int i=1;i<=T;i++)
	{
		cout<<"Case #"<<i<<": ";
		work();
	}
	return 0;
}


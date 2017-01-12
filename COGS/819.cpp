#include <iostream>
#include <cstring>
#include <cstdio>

#define MAXN 3000
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int N,Ans,Len;
string s;
int Count[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("stringnum.in","r",stdin);
	freopen("stringnum.out","w",stdout);
	#endif
	cin>>s;
	Ans=0;
	memset(Count,0,sizeof(Count));
	Len=s.length();
	for(int i=0;i<Len;i++)
	{
		Count[(int)(s[i]-'a'+1)]++;
	}
}


void dfs(string S,int D)
{
	for(int i=1;i<=MAXN;i++)
	{
		char c=(char)(i+'a'-1);
		if(Count[i])
		{
			Count[i]--;
			if(D==Len)
			{
				Ans++;
				if(S+c==s)
				{
					return;
				}
			}
			dfs(S+c,D+1);
			Count[i]++;
		}
	}
}

int main()
{
	init();
	dfs("",1);
	cout<<Ans<<endl;
	return 0;
}


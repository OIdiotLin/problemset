#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 5010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct String{
	int s[MAXN];
	int Len;
};

String A,B;
int f[MAXN][MAXN];

void init()
{
	string st;
	int cnt=0;
	SpeedUp;
	#ifdef FILE
	freopen("lcslength.in","r",stdin);
	freopen("lcslength.out","w",stdout);
	#endif
	memset(f,0,sizeof(f));
	cin>>st;
	while(st[cnt]!='.')
		A.s[++cnt]=st[cnt-1]-'A';
	A.Len=cnt;
	cin>>st;
	cnt=0;
	while(st[cnt]!='.')
		B.s[++cnt]=st[cnt-1]-'A';
	B.Len=cnt;
}

void Dp()
{
	for(int i=1;i<=A.Len;i++)
		for(int j=1;j<=B.Len;j++)
		{
			if(A.s[i]==B.s[j])
				f[i][j]=f[i-1][j-1]+1;
			else
				f[i][j]=max(f[i][j-1],f[i-1][j]);
		}
}

void work()
{
	init();
	Dp();
	cout<<f[A.Len][B.Len]<<endl;
}

int main()
{
	work();
	return 0;
}


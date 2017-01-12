#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1010
#define MAXM 55
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

string s;
int Len,M,cnt;
int f[MAXN][MAXM],d[MAXN][MAXN];

void init()
{
	cnt=0;
	SpeedUp;
	#ifdef FILE
	freopen("chars.in","r",stdin);
	freopen("chars.out","w",stdout);
	#endif
	cin>>s>>M;
	Len=s.length();
	for(int i=0;i<Len;i++)
		for(int j=0;j<M;j++)
			f[i][j]=INF;
	for(int i=0;i<Len;i++)
	{
		cnt=(cnt*10+s[i]-'0')%M;
		f[i][cnt]=0;
	}
	for(int i=0;i<Len;i++)
	{
		cnt=0;
		for(int j=i;j<Len;j++)
		{
			cnt=(cnt*10+s[j]-'0')%M;
			d[i][j]=cnt;
		}
	}
}

void Dp()
{
	for(int i=0;i<Len;i++)
		for(int j=0;j<M;j++)
			if(f[i][j]<INF)
				for(int k=i+1;k<Len;k++)
				{
					cnt=(d[i+1][k]*j)%M;
					if(f[i][j]+1<f[k][cnt])
						f[k][cnt]=f[i][j]+1;
				}
}

void OutPut()
{
	for(int i=0;i<M;i++)
		if(f[Len-1][i]<INF)
		{
			cout<<i<<" "<<f[Len-1][i]<<" ";
			break;
		}
	for(int i=M-1;i>=0;i--)
		if(f[Len-1][i]<INF)
		{
			cout<<i<<" "<<f[Len-1][i];
			break;
		}
	cout<<endl;
}

int main()
{
	init();
	Dp();
	OutPut();
	return 0;
}


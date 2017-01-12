#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define INF 1<<28
#define MAXN
#define Debug
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

typedef long long LL;

int Move[6][2];
int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
	char r;
	for(int i=0;i<=5;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>r;
			Move[i][j]=r-'A';
		}
	}
}

int Brute(int n)
{
	vector<int> S[3];
	for(int i=n;i;i--)
		S[0].push_back(i);
	int tail=0;
	for(int cnt=0;;)
	{
		if(S[1].size()==n || S[2].size()==n)
			return cnt;
		for(int i=0;i<=5;i++)
		{
			int s=Move[i][0],t=Move[i][1];
			if(S[s].size() && S[s].back()!=tail)
			{
				if(S[t].size()==0 || S[s].back()<S[t].back())
				{
					tail=S[s].back();
					S[s].pop_back();
					S[t].push_back(tail);
					cnt++;
					break;
				}
			}
		}
	}
}

void Recurrence(int n)
{
	int Ans_2=Brute(2),Ans_3=Brute(3);
	int A=Ans_3/Ans_2;
	int B=Ans_3-A*Ans_2;
	LL Ans=Ans_3;
	for(int i=4;i<=n;i++)
	{
		Ans=Ans*A+B;
	}
	cout<<Ans<<endl;
}

void work()
{
	if(N<=3)
	{
		cout<<Brute(N)<<endl;
		return;
	}
	Recurrence(N);
}

int main()
{
	init();
	work();
	return 0;
}


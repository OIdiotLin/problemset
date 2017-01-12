#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 30010
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

char A[MAXN];
int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("bcl.in","r",stdin);
	freopen("bcl.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>A[i];
}

void Greedy()
{
	int p1=1,p2=N,cnt=0;
	for(int i=1;i<=N;i++)
	{
		for(int L=p1,R=p2;L<=R;L++,R--)
		{	
			if(A[L]>A[R])
			{
				cout<<A[p2];
				p2--;
				cnt++;
				break;
			}
			else if(A[L]<A[R] || L==R || L+1==R)
			{
				cout<<A[p1];
				p1++;
				cnt++;
				break;
			}
		}
		if(cnt%80==0)
			cout<<endl;
	}
	cout<<endl;
}

int main()
{
	init();
	Greedy();
	return 0;
}


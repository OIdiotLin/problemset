#include <iostream>
#include <cstring>
#define MAXN 30
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int A[MAXN]={0},B[MAXN]={0};
int Ans=0;

void init()
{
	string pre,want;
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>pre;
	for(int i=0;i<pre.size();i++)
	{
		A[(int)pre[i]-'a']++;
	}
	cin>>want;
	for(int i=0;i<want.size();i++)
	{
		B[(int)want[i]-'a']++;
	}
}

void work()
{
	for(int i=0;i<MAXN;i++)
	{
		if(B[i]>0 && A[i]==0)
		{
			cout<<-1<<endl;
			return;
		}
		if(B[i]>A[i])
			Ans+=A[i];
		if(B[i]<=A[i])
			Ans+=B[i];
	}
	if(Ans==0)
	{
		cout<<-1<<endl;
		return;
	}
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();

	return 0;
}

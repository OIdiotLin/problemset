#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 150010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Building{
	int Begin,End;
	friend bool operator < (Building A,Building B){
		return A.End<B.End;
	}
}; 

Building T[MAXN];
priority_queue<int> Q;
int N,Ans;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("repair.in","r",stdin);
	freopen("repair.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>T[i].Begin>>T[i].End;
	sort(T+1,T+N+1);
	Ans=0;
}

void work()
{
	int tmp=0;
	for(int i=1;i<=N;i++)
	{
		if(T[i].Begin+tmp<=T[i].End)
		{
			Q.push(T[i].Begin);
			tmp+=T[i].Begin;
			Ans++;
		}
		else if(T[i].Begin<Q.top() && T[i].Begin+tmp-Q.top()<=T[i].End)
		{
			tmp-=Q.top()-T[i].Begin;
			Q.pop();
			Q.push(T[i].Begin);
		}
	}
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


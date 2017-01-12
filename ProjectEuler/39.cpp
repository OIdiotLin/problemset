#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
#define Debug
using namespace std;

int p;

int Solve(int p)
{
	int cnt=0;
	for(int a=1;a<p;a++)
		for(int b=a;a+b<p;b++){
			int c=p-a-b;
			if(a*a+b*b==c*c)
			{
				#ifdef Debug
				cout<<a<<" "<<b<<" "<<c<<endl;
				#endif
				cnt++;}
		}
	return cnt;
}

void work()
{
	int Ans;
	int Max=0;
	for(p=3;p<=1000;p++){
		int t=Solve(p);
		#ifdef Debug
		if(t)
		cout<<p<<" has "<<t<<" Ways."<<endl<<endl;
		#endif
		if(t>Max){
			Max=t;
			Ans=p;
		}
	}
	cout<<Ans<<endl;
}

int main()
{
	work();
	return 0;
}


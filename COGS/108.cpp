#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define Income 300
#define Base 100 
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int rest,Store;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	#endif
	rest=Store=0;
}

void Plan(int Month)
{
	int budget;
	cin>>budget;
	rest+=Income;
	if(rest<budget)
	{
		cout<<"-"<<Month<<endl;
		exit(0);
	}
	else
	{
		rest-=budget;
	}
	if(rest>Base)
	{
		Store+=rest-rest%Base;
		rest%=Base;
	}
	#ifdef Debug
	cout<<"Month "<<Month<<" :"<<endl
		<<"budget = "<<budget<<"\t\trest = "<<rest<<"\t\tStore = "<<Store<<endl;
	#endif
}

void work()
{
	for(int i=1;i<=12;i++)
	{
		Plan(i);
	}
	cout<<rest+1.2*Store<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


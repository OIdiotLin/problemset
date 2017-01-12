#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N;
int tY,tC;
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("sjb.in","r",stdin);
	freopen("sjb.out","w",stdout);
	#endif
	cin>>N;
	tY=tC=0;
}

void judge()
{
	char a,b;
	cin>>a>>b;
	if(a=='S'){
		if(b=='S')
			return;
		if(b=='J')
			tY++;
		if(b=='B')
			tC++;
	}
	if(a=='J'){
		if(b=='S')
			tC++;
		if(b=='J')
			return;
		if(b=='B')
			tY++;
	}
	if(a=='B'){
		if(b=='S')
			tY++;
		if(b=='J')
			tC++;
		if(b=='B')
			return;
	}
}

void work()
{
	init();
	for(int i=1;i<=N;i++)
		judge();
	if(tC>tY)
		cout<<"ck wins"<<endl;
	if(tC==tY)
		cout<<"both ywj and ck win"<<endl;
	if(tC<tY)
		cout<<"ywj wins"<<endl;
}

int main()
{
	work();
	return 0;
}


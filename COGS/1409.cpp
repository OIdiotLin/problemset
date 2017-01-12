#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define MAXN
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Node{
	double x;
	double y;
};
Node Soilder,C;
double R;
int DEAD,N;
char Team;

double Dist(Node a,Node b)
{
	double X=a.x-b.x,Y=a.y-b.y;
	return sqrt(X*X+Y*Y);
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("c4.in","r",stdin);
	freopen("c4.out","w",stdout);
	#endif
	cin>>C.x>>C.y>>R;
	DEAD=0;
	cin>>N;
}

void Bomb()
{
	while(N--)
	{
		cin>>Team>>Soilder.x>>Soilder.y;
		if(Team=='L')
			continue;
		else
		{
			if(Dist(Soilder,C)<=R)
				DEAD++;
		}
		
	}
}

void work()
{
	init();
	Bomb();
	cout<<DEAD<<endl;
}

int main()
{
	work();
	return 0;
}

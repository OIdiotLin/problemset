#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 4
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Pell_Root{
	int x0,y0;
};

struct Node{
	int f,g;
};

Pell_Root Solve(int n)
{
	Pell_Root s[MAXN];
	Node w[MAXN];
	int a[MAXN];
	s[0]=(Pell_Root){0,1};
	s[1]=(Pell_Root){1,0};
	a[2]=a[0]=(int)floor(sqrt((double)n));
	w[1]=(Node){0,1};
	
	while(true)
	{
		w[2].f=-w[1].f+a[2]*w[1].g;;
		w[2].g=(n-w[2].f*w[2].f)/w[1].g;
		a[3]=(int)floor((double)(w[2].f+a[0])/w[2].g);
		s[2]=(Pell_Root){a[2]*s[1].x0+s[0].x0,a[2]*s[1].y0+s[0].y0};
		if(s[2].x0*s[2].x0-n*s[2].y0*s[2].y0==1 && s[2].x0 && s[2].y0)
		{
			return s[2];
		}
		w[0]=w[1];
		w[1]=w[2];
		s[0]=s[1];
		s[1]=s[2];
		a[2]=a[3];
	}
}

void work()
{
	int N;
	Pell_Root A;
	cin>>N;
	A=Solve(N);
	cout<<A.x0<<" "<<A.y0<<endl;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("pell.in","r",stdin);
	freopen("pell.out","w",stdout);
	#endif
}

int main()
{
	init();
	work();
	return 0;
}


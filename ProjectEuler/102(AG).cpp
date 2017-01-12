#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define eps 1e-9
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

const int N=1000;

struct Point{
	int x,y;
};

double Slope(Point A,Point B){
	return (A.y-B.y)/(A.x-B.x);
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("102.txt","r",stdin);
//	freopen(".out","w",stdout);
	#endif
}

int main()
{
	
	return 0;
}


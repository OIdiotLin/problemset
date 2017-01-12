#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define MAXN 105
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;
const double Pi=acos(-1);

struct Point{
	double x,y;
	void read(){cin>>x>>y;}
}P[MAXN];
inline double dist(Point A,Point B){
	double X=(A.x-B.x)*(A.x-B.x),Y=(A.y-B.y)*(A.y-B.y);
	return sqrt(X+Y);
}

int N;
double R,Ans;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N>>R;
	for(int i=1;i<=N;i++)
		P[i].read();
	P[N+1]=P[1];
	Ans=Pi*R*2;
	for(int i=1;i<=N;i++)
		Ans+=dist(P[i],P[i+1]);
	cout<<fixed<<setprecision(2)<<Ans<<endl;
}

int main()
{
	init();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


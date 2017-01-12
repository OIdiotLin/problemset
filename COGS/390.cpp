#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#define MAXN 12000
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int V[MAXN];
double c[MAXN];
int N,cnt;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("simulator.in","r",stdin);
	freopen("simulator.out","w",stdout);
	#endif
	memset(V,0,sizeof(V));
	memset(c,0,sizeof(c));
	cnt=0;
	
	cin>>V[0]>>c[0];		//初始化模拟器质量、浓度。
	cin>>N; 
}

void operate()
{
	char Order;
	cin>>Order;
	if(Order=='Z')
	{
		#ifdef Debug
		cout<<"Reading Z Success!"<<endl;
		#endif
		cnt--;
		if(cnt<0)
			cnt=0;
		cout<<V[cnt]<<" "<<fixed<<setprecision(5)<<c[cnt]<<endl;
	}
	else
	{

		int v1,c1;
		cnt++;
		cin>>v1>>c1;
		V[cnt]=V[cnt-1]+v1;
		c[cnt]=(v1*c1+V[cnt-1]*c[cnt-1])/V[cnt];
		cout<<V[cnt]<<" "<<fixed<<setprecision(5)<<c[cnt]<<endl;
	}
}

void work()
{
	init();
	for(int i=1;i<=N;i++)
	{
		operate();
	}
}

int main()
{
	work();
	return 0;
}


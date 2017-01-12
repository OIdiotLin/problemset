#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef unsigned long long uLL;

inline int gcd(int a,int b){
	return (b==0 ? a : gcd(b,a%b));
} 
int W,H,L1,L2;
uLL Ans;
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("banner.in","r",stdin);
	freopen("banner.out","w",stdout);
	#endif
	cin>>W>>H>>L1>>L2;		
	L1*=L1,L2*=L2;		//Distance Square. ==> Sum of the two legs in the Rt Triangle.
	Ans=0;
}

void work(){
	for(int i=1;i<=W+1;i++)
		for(int j=1;j<=H+1;j++)
			if(gcd(i,j)==1)
				if(i*i+j*j>=L1 && i*i+j*j<=L2)
					Ans+=(W-i+1)*(H-j+1);
	Ans*=2;
	if(L1<=1) Ans+=W*(H+1)+H*(W+1);		//if the distance can be lower than 1, the wires can be connected between two adjacent Nodes;
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(uLL))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


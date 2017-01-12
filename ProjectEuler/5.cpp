#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

inline int gcd(int a,int b){
	return (b%a==0) ? a : gcd(b%a,a);
}
inline int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
inline int lcm(int x){
	if(x==3)
		return 6;
	return lcm(x,lcm(x-1));
}

int main()
{
	
	cout<<lcm(20)<<endl;
	return 0;
}


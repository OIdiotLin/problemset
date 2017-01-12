#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N;
long long list[]={1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("rook.in","r",stdin);
	freopen("rook.out","w",stdout);
	#endif
	cin>>N;
}

int main()
{
	init();
	cout<<list[N-1]<<endl;
	return 0;
}

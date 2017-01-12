#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N;

int cube(int a){
	return a*a*a;
}

bool Judge(int N)
{
	int c=N%10,b=(N/10)%10,a=N/100;
	if(cube(a)+cube(b)+cube(c)==N)
		return true;
	return false;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("daff.in","r",stdin);
	freopen("daff.out","w",stdout);
	#endif
	cin>>N;
}

int main()
{
	init();
	cout<<((Judge(N)) ? "TRUE" : "FALSE")<<endl;
	return 0;
}


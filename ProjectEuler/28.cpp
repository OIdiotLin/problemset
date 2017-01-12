#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
void work()
{
	LL S=1;
	for(int i=3;i<=1001;i+=2){
		S+=4*i*i-(i-1)*6;
	}
	cout<<S<<endl;
}

int main()
{
	work();
	return 0;
}


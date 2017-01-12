#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int R[]={0,1,2,3,4,5,6,7,8,9};

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

void work(){
	int cnt=1;
	while(cnt!=1000000){
		cnt++;
		next_permutation(R,R+10);
	}
	for(int i=0;i<10;i++){
		cout<<R[i];
	}
	cout<<endl;
}

int main()
{
	work();
	return 0;
}


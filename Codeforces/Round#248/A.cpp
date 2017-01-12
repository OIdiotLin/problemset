#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 100
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int A,B;
int S,N;
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
	S=0;
}

void work(){
	int r;
	for(int i=1;i<=N;i++){
		cin>>r;
		S+=r;
		if(r==100)A++;
		if(r==200)B++;
	}
	if(A%2==0 && B%2==0){
		cout<<"YES"<<endl;
		return;
	}
	if(B%2==0 && A%2!=0){
		cout<<"NO"<<endl;
		return;
	}
	if(A%B==0){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Wheel{
	int v,n;
	int begin[6],last[6];
	void read(){
		cin>>v>>n;
		for(int i=n-1;i>=0;i--)
			cin>>begin[i]>>last[i];
	}
}W[5];
const int N=5;
const int Pi2=360;
int notch[Pi2+5];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	#endif
	for(int i=0;i<N;i++){
		W[i].read();
	}
}

void work(int x){
	memset(notch,0,sizeof(notch));
	for(int i=0;i<N;i++){
		for(int j=0;j<W[i].n;j++){
			for(int k=W[i].begin[j];k<=W[i].begin[j]+W[i].last[j];k++){
				if(notch[k%Pi2]==i)
					notch[k%Pi2]++;
			}
			W[i].begin[j]=(W[i].begin[j]+W[i].v)%Pi2;
		}
	}
	for(int i=0;i<Pi2;i++){
		if(notch[i]==N){
			cout<<x<<endl;
			exit(0);
		}
	}
}

int main()
{
	init();
	for(int i=0;i<Pi2;i++)
		work(i);
	cout<<"none"<<endl;
	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


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

int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("poly.in","r",stdin);
	freopen("poly.out","w",stdout);
	#endif
	cin>>N;
}

void work(){
	int r;
	cin>>r;
	if(r>1){
		cout<<r<<"x^"<<N;
	}
	if(r==1){
		cout<<"x^"<<N;
	}
	if(r<0&&r!=-1){
		cout<<r<<"x^"<<N;
	}
	if(r==-1){
		cout<<"-x^"<<N;
	}
	for(int i=1;i<N;i++){
		cin>>r;
		if(r==1){
			cout<<"+x";
		}
		if(r==-1){
			cout<<"-x";
		}
		if(r<0&&r!=-1){
			cout<<r<<"x";
		}
		if(r>1){
			cout<<'+'<<r<<"x";
		}
		if(r==0) continue;
		if(N-i!=1) cout<<"^"<<N-i;
	}
	cin>>r;
	if(r>0){
		cout<<'+'<<r;
		return;
	}
	if(r==0){
		return;
	}
	if(r<0){
		cout<<r;
		return ;
	}
}

int main()
{
	init();
	work();
	cout<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


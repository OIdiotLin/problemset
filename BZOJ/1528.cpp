#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN ()
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

struct Node{
	int toy,last, ;
	bool operator < (const Node &b)const{
		return order<b.order;
	}
}A[MAXN];
priority_queue<Node> Q;
bool vis[MAXN];
int N,K,P;

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N>>K>>P;
	for(int i=1;i<=P;i++){
		cin>>A[i].toy;
		
	}
}

void work(){
	

int main(){
	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


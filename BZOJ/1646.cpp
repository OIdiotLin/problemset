#include <iostream>
#include <cstring>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (200010)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

bool vis[MAXN];
struct Node{
	int pos;
	int step;
};
queue<Node> Q;
int N,K;

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N>>K;
	vis[N]=true;
	Node t;
	t.pos=N;
	t.step=0;
	Q.push(t);
}

void BFS(){
	Node t,next;
	while(!Q.empty()){
		t=Q.front();
		Q.pop();
		if(t.pos==K){
			cout<<t.step<<endl;
			return;
		}
		if(!vis[t.pos-1] && t.pos>=1){
			next.pos=t.pos-1;
			next.step=t.step+1;
			vis[next.pos]=true;
			Q.push(next);
		}
		if(!vis[t.pos+1] && t.pos<=K){
			next.pos=t.pos+1;
			next.step=t.step+1;
			vis[next.pos]=true;
			Q.push(next);
		}
		if(!vis[t.pos<<1] && t.pos<=K){
			next.pos=t.pos<<1;
			next.step=t.step+1;
			vis[next.pos]=true;
			Q.push(next);
		}
	}
}		

int main(){
	init();
	BFS();	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


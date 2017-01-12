#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (150004)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

struct Team{
	int ID;
	int M;
	bool operator < (const Team &t)const {
		if(M==t.M) return ID>t.ID;
		return M>t.M;
	}
	void read(){
		cin>>ID>>M;
	}
	void print(){
		cout<<ID<<" "<<M<<endl;
	}
}T[MAXN];
int N;

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("1100.in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++) T[i].read();
	sort(T+1,T+N+1);
	for(int i=1;i<=N;i++) T[i].print();
}

int main(){
	init();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


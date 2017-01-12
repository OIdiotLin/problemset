#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 120
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

struct Seg{
	int L,R;
	bool operator < (const Seg &b) const {
		if(L==b.L) return R<b.R;
		return L<b.L;
	}
	void read(){
		cin>>L>>R;
		if(L>R) swap(L,R);
	}
	void print(){
		cout<<L<<" "<<R<<endl;
	}
}S[MAXN];
bool p[MAXN];
int N,cnt;

void init()
{
	int l,r;
	#ifdef FILE
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cnt=0;
	cin>>N;
	for(int i=1;i<=N;i++){
		S[i].read();
	}
	sort(S+1,S+N+1);
}

void work(){
	for(int i=N;i;i--){
		if(!p[i]){
			for(int j=i-1;j;j--)
				if(S[j].R>S[i].L){
					p[j]=true;
					cnt++;
				}else break;
		}
	}
	cout<<N-cnt<<endl;
	for(int i=1;i<=N;i++){
		if(!p[i])
			S[i].print();
	}
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


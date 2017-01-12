/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (100002)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputLL(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputLL(x)
#define read(x) x=getint()

struct Task{
	int d,p;
	bool operator < (const Task&b) const{
		return d<b.d;
	}
	void Read(){
		read(d),read(p);
	}
}A[MAXN];
int N;

void init(){
	#ifdef Judge
	freopen("1572.in","r",stdin);
	freopen("1572.out","w",stdout);
	SpeedUp;
	#endif
	read(N);
	for(int i=1;i<=N;i++)
		A[i].Read();
	sort(A+1,A+N+1);
}

priority_queue<int> Q;
void work(){
	LL Ans=0;
	for(int i=N;i;i--){
		Q.push(A[i].p);
		while(i>1 && A[i-1].d==A[i].d) Q.push(A[--i].p);
		LL t=A[i].d,cnt=0;
		while(!Q.empty() && cnt<t-A[i-1].d){
			Ans+=Q.top();
			Q.pop();
			cnt++;
		}
	}
	print(Ans);
}

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
	#endif
	return 0;
}
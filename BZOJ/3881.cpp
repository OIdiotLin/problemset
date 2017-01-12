/*
	Machine: Class4_B2
	System: Ubuntu_Kylin 14.10
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN ()
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define sqr(x)	((x)*(x))

struct Suffx_Automaton{
	struct Node{
		Node *fa,*son[27];
		int ans,step;
		inline void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=0;
		}
	}node[MAXN<<1],*fst,*fnl,*Ans[MAXN];
	int tot;

	void init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}

	inline void Add(int x){
		Node *p=fnl,*np=&node[++tot];
		np->Init();
		np->step=p->step+1;
		
	}
}SAM;

void init(){
#ifdef Judge
	freopen("3881.in","r",stdin);
	freopen("3881.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
}

void work(){
	;
}

int main(){
	init();
//#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
//#endif
	return 0;
}

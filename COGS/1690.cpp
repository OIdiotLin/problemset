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
#include <map>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (20005)
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

int N,K;
int C[MAXN];
int ans;

struct Suffix_Automaton{
	struct Node{
		map<int,int> son;
		Node *fa;
		int step,right;
		inline void Init(){
			son.clear();
			fa=NULL,step=right=0;
		}
	}node[MAXN<<1],*fst,*fnl,*tmp[MAXN<<1];
	int tot;

	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}

	inline void Add(int x){
		Node *p=fnl,*np=&node[++tot];
		np->step=p->step+1;
		np->right=1;
		while(p && p->son.find(x)==p->son.end()){
			p->son[x]=np-node;
			p=p->fa;
		}
		if(p==NULL){
			np->fa=fst;
		}else{
			Node *q=node+(p->son[x]);
			if(q->step==p->step+1){
				np->fa=q;
			}else{
				Node *nq=&node[++tot];
				*nq=*q;
				nq->step=p->step+1;
				nq->right=0;
				np->fa=q->fa=nq;
				while(p && p->son[x]==q-node){
					p->son[x]=nq-node;
					p=p->fa;
				}
			}
		}
		fnl=np;
	}

	void Calc_Info(){
		for(int i=1;i<=tot;i++)
			C[node[i].step]++;
		for(int i=1;i<=N;i++)
			C[i]+=C[i-1];
		for(int i=1;i<=tot;i++){
			Node *p=&node[i];
			tmp[C[p->step]--]=p;
		}
		for(int i=tot;i>1;i--){
			Node *p=tmp[i];
			if(p->fa){
				p->fa->right+=p->right;
				if(p->fa!=node+1 && p->fa->right>=K)
					ans=max(ans,p->fa->step);
			}
		}
	}
}SAM;

void init(){
	int x;
#ifdef Judge
	freopen("patterns.in","r",stdin);
	freopen("patterns.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(K);
	SAM.Init();
	for(int i=1;i<=N;i++)
		read(x),SAM.Add(x);
}

void work(){
	SAM.Calc_Info();
	print(ans);
}

int main(){
	init();
	work();
//#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(SAM))/1048576<<" MB."<<endl;
//#endif
	return 0;
}

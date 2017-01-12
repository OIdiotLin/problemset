/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXL (300001)
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
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

char S[MAXL];
int C[MAXL];
int len;

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[2];
		int right,step;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=right=0;
		}
	}node[MAXL<<1],*fst,*fnl,*tmp[MAXL<<1];
	int tot;
	
	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}
	
	void Add(int x){
		Node *p=fnl,*np=&node[++tot];
//		np->Init();
		np->step=p->step+1;
		np->right=1;
		while(p && !p->son[x]){
			p->son[x]=np;
			p=p->fa;
		}
		if(p==NULL){
			np->fa=fst;
		}else if(p->step+1==p->son[x]->step){
			np->fa=p->son[x];
		}else{
			Node *q=p->son[x],*nq=&node[++tot];
//			nq->Init();
			*nq=*q;
			nq->step=p->step+1;
			nq->right=0;
			np->fa=q->fa=nq;
			while(p && p->son[x]==q){
				p->son[x]=nq;
				p=p->fa;
			}
		}
		fnl=np;
	}
	
	void Topo(){
//		memset(C,0,sizeof(C));
		for(int i=1;i<=tot;i++)
			C[node[i].step]++;
		for(int i=1;i<=len;i++)
			C[i]+=C[i-1];
		for(int i=1;i<=tot;i++){
			Node *p=&node[i];
			tmp[C[p->step]--]=p;
		}
	}
	
	void Calc_Info(){
		for(int i=tot;i;i--){
			Node *p=tmp[i];
			if(p->fa)
				p->fa->right+=p->right;
		}
	}
	
	void dfs(Node *p){
		if(p==NULL)	return;
		if(p!=fst && p->right>1)print(p->right);
		for(int i=0;i<2;i++)
			if(p->son[i])
				dfs(p->son[i]);
	}
}SAM;

void init(){
	char ch;
#ifdef Judge
	freopen("2251.in","r",stdin);
	freopen("2251.out","w",stdout);
// 	SpeedUp;
#endif
	scanf("%d\n",&len);
	SAM.Init();
	for(int i=0;i<len;i++){
		ch=getchar();
		SAM.Add(ch=='1');
	}
}

void work(){
	SAM.Topo();
	SAM.Calc_Info();
	SAM.dfs(SAM.fst);
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
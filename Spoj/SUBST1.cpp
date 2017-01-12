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
#define MAXN (50005)
#define Sigma (52)
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
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

char S[MAXN];
int T,len;

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[Sigma];
		int step,d;
		LL ans;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=d=ans=0;
		}
	}node[MAXN<<1],*fst,*fnl;
	int tot;
	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}

	inline void Add(int x){
		Node *p=fnl,*np=&node[++tot];	np->Init();
		np->step=p->step+1;
		while(p && !p->son[x]){
			p->son[x]=np;
			p=p->fa;
		}
		if(p==NULL){
			np->fa=fst;
		}else if(p->son[x]->step==p->step+1){
			np->fa=p->son[x];
		}else{
			Node *q=p->son[x],*nq=&node[++tot];
			*nq=*q;
			nq->step=p->step+1;
			np->fa=q->fa=nq;
			while(p && p->son[x]==q){
				p->son[x]=nq;
				p=p->fa;
			}
		}
		fnl=np;
	}

	void dfs(Node *p,Node *fa){
		p->ans+=fa->ans;
		if(p->d>1){
			p->d--;
			return;
		}
		for(int x=0;x<Sigma;x++)
			if(p->son[x])
				dfs(p->son[x],p);
	}

	void Calc(){
		LL Ans=0;
		fst->ans=1;
		for(int u=1;u<=tot;u++)
			for(int x=0;x<Sigma;x++)
				if(node[u].son[x])
					node[u].son[x]->d++;
		for(int x=0;x<Sigma;x++)
			if(fst->son[x])
				dfs(fst->son[x],fst);
		for(int u=2;u<=tot;u++)
			Ans+=node[u].ans;
		print(Ans);
	}
}SAM;

void init(){
#ifdef Judge
	freopen("SUBST1.in","r",stdin);
	freopen("SUBST1.out","w",stdout);
//	SpeedUp;
#endif
	read(T);
}

inline int Encode(char x){
	if(x>='a' && x<='z')
		return x-'a';
	return x-'A'+26;
}

void work(){
	SAM.Init();
	scanf("%s",S);
	len=strlen(S);
	for(int i=0;i<len;i++){
		SAM.Add(Encode(S[i]));
	}
	SAM.Calc();
}

int main(){
	init();
	for(int i=1;i<=T;i++){
		work();
//		fprintf(stderr,"solved %d/%d.\n",i,T);
	}
#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(SAM)+sizeof(S))/1048576<<" MB."<<endl;
#endif
	return 0;
}

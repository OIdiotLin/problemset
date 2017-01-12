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
//#define Judge
//#define Debug
#define MAXN (50005)
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

int N,M;
string S;

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[26];
		int step;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=0;
		}
	}node[MAXN<<1],*fst,*fnl;
	int tot;
	
	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}
	void Add(int x){
#ifdef Debug
		printf("Adding '%c':\n",x+'A');
#endif
		Node *p=fnl,*np=&node[++tot];
		np->Init();
		np->step=p->step+1;
#ifdef Debug
		printf("\tnp's step=%d,np's id is %d\n",np->step,np-fst+1);
#endif
		while(p && !p->son[x]){
			p->son[x]=np;
			p=p->fa;
		}
		if(p==NULL){
			np->fa=fst;	
#ifdef Debug
			printf("\tFinding NULL and np's fa is %d\n",np->fa-fst+1);
#endif
		}else if(p->step+1==p->son[x]->step){
			np->fa=p->son[x];
#ifdef Debug
			printf("\tFinding next to.. and np's fa is %d\n",np->fa-fst+1);
#endif
		}else{
#ifdef Debug
			printf("\tAdding Support\n");
#endif
			Node *q=p->son[x],*nq=&node[++tot];
			nq->Init();
			*nq=*q;
			nq->step=p->step+1;
			np->fa=q->fa=nq;
#ifdef Debug
			printf("\tnq's step=%d , nq's id is %d, nq's fa is %d\n",nq->step,nq-fst+1,nq->fa-fst+1);
#endif
			while(p && p->son[x]==q){
				p->son[x]=nq;
				p=p->fa;
			}
		}
		fnl=np;
#ifdef Debug
		printf("\n");
#endif
	}
	
	int Run(){
		int i=0,res=0;
		while(i<M){
			for(Node *p=fst;S[i] && p->son[S[i]-'A'];p=p->son[S[i++]-'A']);
			++res;
		}
		return res;
	}
}SAM;

void init(){
	int tot=0;
#ifdef Judge
	freopen("2099.in","r",stdin);
	freopen("2099.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	SAM.Init();
	while(tot!=N){
		char ch=getchar();
		if(ch<'A'||ch>'Z') continue;
		SAM.Add(ch-'A');
		tot++;
	}
	tot=0;
	while(tot!=M){
		char ch=getchar();
		if(ch<'A'||ch>'Z') continue;
		tot++;
		S=S+ch;
	}
#ifdef Debug
	cout<<"Target string: "<<S<<endl;
#endif
}

void work(){
	print(SAM.Run());
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(SAM))/1048576<<" MB."<<endl;
#endif
	return 0;
}
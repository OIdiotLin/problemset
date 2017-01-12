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
#define MAXN (300005)
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

int C[MAXN];
int len;
LL ans;
char S[MAXN];

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[27];
		int step,right,Palmx;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=right=Palmx=0;
		}
	}node[MAXN<<1],*fst,*fnl,*tmp[MAXN<<1];
	bool vis[MAXN<<1];
	int tot;
#define id(p)	(p-node)
	inline void Init(){
		memset(vis,false,sizeof(vis));
		fst=fnl=&node[tot=1];
		fst->Init();
	}
	
	inline void Add(int x){
		Node *p=fnl,*np=&node[++tot];
		np->Init();
		np->Palmx=np->step=p->step+1;
		np->right=1;
		while(p && !p->son[x]){
			p->son[x]=np;
			p=p->fa;
		}
		if(p==NULL){
			np->fa=fst;
		}else if(p->son[x]){
			np->fa=p->son[x];
		}else{
			Node *q=p->son[x],*nq=&node[++tot];
			nq->Init();
			*nq=*q;
			nq->step=p->step+1;
			nq->right=nq->Palmx=0;
			np->fa=q->fa=nq;
			while(p && p->son[x]==q){
				p->son[x]=nq;
				p=p->fa;
			}
		}
		fnl=np;
	}
	
	void Topo(){
		memset(C,0,sizeof(C));
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
		for(int i=tot;i>1;i--){
			Node *p=&node[i];
			if(p->fa){
				p->fa->right+=p->right;
				p->fa->Palmx=max(p->fa->Palmx,p->Palmx);
			}
		}
	}
	
	void Run(int x,int i){
		static Node *p=&node[1];
		static int l=0;
		while(p && !p->son[x]){
			p=p->fa;
			l=p->step;
		}
		if(p==NULL){
			p=&node[1];
			l=0;
		}else{
			p=p->son[x];
			l++;
		}
		if(p->Palmx<l+i){
			if(p->Palmx>=i)
				ans=max(ans,(LL)p->right*(p->Palmx-i+1));
			for(Node *q=p->fa;q;q=q->fa){
				if(vis[id(q)])	break;
				int step=q->step;
				if(i<=q->Palmx && q->Palmx<i+step)
					ans=max(ans,(LL)q->right*(q->Palmx-i+1));
				vis[id(q)]=true;
			}
		}
	}
}SAM;

void init(){
#ifdef Judge
	freopen("3676.in","r",stdin);
	freopen("3676.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%s",S+1);
	len=strlen(S+1);
	SAM.Init();
	for(int i=1;i<=len;i++)
		SAM.Add(S[i]-'a');
	SAM.Topo();
	SAM.Calc_Info();
}

void work(){
	for(int i=len;i;i--)
		SAM.Run(S[i]-'a',i);
	printf("%lld\n",ans);
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
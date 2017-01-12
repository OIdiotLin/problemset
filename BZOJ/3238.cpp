/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
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
#define MAXN (500002)
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

char S[MAXN];
int len;
LL Ans;

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[26];
		int step,right;
		bool vis;
		vector<Node*> Fail_son;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=right=vis=0;
		}
	}node[MAXN<<1],*fst,*fnl;
	int tot;
	
	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}
	
	void Add(int x){
		Node *p=fnl,*np=&node[++tot];
		np->step=p->step+1;
		np->right=1;
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
			nq->right=0;
			np->fa=q->fa=nq;
			while(p && p->son[x]==q){
				p->son[x]=nq;
				p=p->fa;
			}
		}
		fnl=np;
	}

	void dfs(Node *p){
		if(!p)	return;
		if(p->fa)
			p->fa->Fail_son.push_back(p);
		p->vis=true;
		for(int x=0;x<26;x++)
			if(p->son[x] && !p->son[x]->vis)
				dfs(p->son[x]);
	}

	void dp(Node *p){
		if(!p)	return;
		for(vector<Node*>::iterator v=p->Fail_son.begin();v!=p->Fail_son.end();++v){
			dp(*v);
			Ans-=(LL)p->step*p->right*(*v)->right<<1;
			p->right+=(*v)->right;
		}
	}
}SAM;

void init(){
#ifdef Judge
	freopen("3238.in","r",stdin);
	freopen("3238.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%s",S);
	len=strlen(S);
	Ans=(LL)(len-1)*len*(len+1)>>1;
	fprintf(stderr,"Ans = %lld\n",Ans);
	SAM.Init();
	for(int i=len-1;~i;i--)
		SAM.Add(S[i]-'a');
}

void work(){
	SAM.dfs(SAM.fst);
	SAM.dp(SAM.fst);
	printf("%lld\n",Ans);
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
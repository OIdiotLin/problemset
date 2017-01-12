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
#define MAXN (250005)
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

char S[MAXN];
int C[MAXN],f[MAXN];
int len;

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[27];
		int step,right;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=right=0;
		}
	}node[MAXN<<1],*fst,*fnl,*tmp[MAXN<<1];
	int tot;
	
	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}
	
	void Topo(){
		for(int i=1;i<=tot;i++)
			C[node[i].step]++;
		for(int i=1;i<=len;i++)
			C[i]+=C[i-1];
		for(int i=1;i<=tot;i++){
			Node *p=&node[i];
			tmp[C[p->step]--]=p;
		}
#ifdef Debug
		printf("points array tmp:\n");
		for(int i=1;i<=tot;i++)
			printf("\t%d",tmp[i]-fst+1);
		printf("\n");
#endif
	}
	
	void Add(int x){
#ifdef Debug
		printf("Adding %c.\n",x+'a');
#endif
		Node *p=fnl,*np=&node[++tot];
		np->Init();
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
			nq->Init();
			*nq=*q;
			nq->right=0;
			nq->step=p->step+1;
			np->fa=q->fa=nq;
			while(p && p->son[x]==q){
				p->son[x]=nq;
				p=p->fa;
			}
		}
		fnl=np;
	}
	
	void Calc_Info(){
		Node *p;
		for(int i=tot;i>1;i--){
			p=tmp[i];
			f[p->step]=max(f[p->step],p->right);
			if(p->fa)	p->fa->right+=p->right;
		}
		for(int i=len-1;i>0;i--)
			f[i]=max(f[i],f[i+1]);
#ifdef Debug
		for(int i=1;i<=tot;i++)
			printf("\t%d",node[i].right);
		puts("");
#endif
	}
	
}SAM;

void init(){
#ifdef Judge
	freopen("8222.in","r",stdin);
	freopen("8222.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%s",S);
	len=strlen(S);
	SAM.Init();
	for(int i=0;i<len;i++)
		SAM.Add(S[i]-'a');
}

void work(){
	SAM.Topo();
	SAM.Calc_Info();
	for(int i=1;i<=len;i++)
		print(f[i]);
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(SAM)+sizeof(f)*2)/1048576<<" MB."<<endl;
#endif
	return 0;
}
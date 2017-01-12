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
#define MAXN (201)
#define MAXL (1000201)
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

int C[MAXL];
int len;
char S[MAXN][MAXL];

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[27];
		int step,right;
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
	
	void Topo(){
		//memset(C,0,sizeof(C));
		for(int i=1;i<=tot;i++)
			C[node[i].step]++;
		for(int i=1;i<=len;i++)
			C[i]+=C[i-1];
		for(int i=1;i<=tot;i++){
			Node *p=&node[i];
			tmp[C[p->step]--]=p;
		}
	}
	
	void Add(int x){
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
		for(int i=tot;i>1;i--){
			Node *p=tmp[i];
			if(p->fa)
				p->fa->right+=p->right;
		}
	}
	
	int Run(int k){
		Node *p=fst;
		int l=strlen(S[k]);
		for(int i=0;i<l;i++){
			p=p->son[S[k][i]-'a'];
			if(p==NULL) return 0;
		}
		return p->right;
	}
	
	/*	Debug Code	*/
	void print_Right(){
		for(int i=2;i<=tot;i++){
			printf("Node %d --- right = %d\n",i,node[i].right);
		}
	}
	
}SAM;

int N;

void init(){
#ifdef Judge
	freopen("3172.in","r",stdin);
	freopen("3172.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&N);
	SAM.Init();
	for(int i=1;i<=N;i++){
		scanf("%s",S[i]);
		int l=strlen(S[i]);
		for(int j=0;j<l;j++)
			SAM.Add(S[i][j]-'a');
		SAM.Add(26);
		len+=l+1;
	}
}

void work(){
	SAM.Topo();
	SAM.Calc_Info();
#ifdef Debug
	SAM.print_Right();
#endif
	for(int i=1;i<=N;i++)
		print(SAM.Run(i));
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(SAM)+sizeof(C)+sizeof(S))/1048576<<" MB."<<endl;
#endif
	return 0;
}
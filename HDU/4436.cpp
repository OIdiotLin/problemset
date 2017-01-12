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
#define MAXN (10005)
#define MAXL (210005)
#define INF ()
const double PI=acos(-1);
const int ZCY=2012;

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
int N,len;

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[12];
		int step,cnt,sum;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=cnt=sum=0;
		}
	}node[MAXL<<1],*fst,*fnl,*tmp[MAXL<<1];
	int tot;
	
	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}
	
	void Clear(){
		for(int i=1;i<=tot;i++)
			node[i].Init();
	}
	
	void Stat(){
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
	
	void Add(int x){
		Node *p=fnl,*np=&node[++tot];
		np->Init();
		np->step=p->step+1;
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
			nq->step=p->step+1;
			np->fa=q->fa=nq;
			while(p && p->son[x]==q){
				p->son[x]=nq;
				p=p->fa;
			}
		}
		fnl=np;
	}
	
	void Run(){
		int res=0;
		fst->cnt=1,fst->sum=0;
		for(int i=1;i<=tot;i++){
			Node *p=tmp[i];
			for(int j=0;j<10;j++){
				if(i==1 && j==0)	continue;
				if(p->son[j]){
					Node *q=p->son[j];
					q->cnt=(q->cnt+p->cnt)%ZCY;
					q->sum=(q->sum+p->sum*10+p->cnt*j)%ZCY;
				}
			}
			res=(res+p->sum)%ZCY;
		}
		printf("%d\n",res);
	}
}SAM;

void init(){
#ifdef Judge
	freopen("4436.in","r",stdin);
	freopen("4436.out","w",stdout);
//	SpeedUp;
#endif
}

void work(){
	SAM.Init();
	len=0;
	for(int i=1;i<=N;i++){
		scanf("%s",S);
		int l=strlen(S);
		for(int j=0;j<l;j++)
			SAM.Add(S[j]-'0');
		
		SAM.Add(10);
		len+=l+1;
#ifdef Debug
		printf("End Adding \"%s\"(len=%d).\n\n",S,l);
#endif
	}
	SAM.Stat();
	SAM.Run();
	SAM.Clear();
}

int main(){
	init();
	while(scanf("%d",&N)!=EOF)
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(SAM))/1048576<<" MB."<<endl;
#endif
	return 0;
}
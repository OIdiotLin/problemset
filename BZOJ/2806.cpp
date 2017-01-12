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
#define MAXN (1000005)
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

int N,M,len;
int d[MAXN],C[MAXN],f[MAXN];
char S[MAXN];

inline bool chk(const char *s,const int &lim){
	int len=strlen(s);
	int k=(len*9+9)/10;
	static int BASE[MAXN];
	static deque<int> Q;
	while(!Q.empty())	Q.pop_back();
	int *f=BASE+1;
	f[-1]=0;
	for(int i=0;i!=len;i++){
		if(i-lim>=-1){
			while(!Q.empty() && f[i-lim]<=f[Q.back()])	Q.pop_back();
			Q.push_back(i-lim);
		}
		while(!Q.empty() && Q.front()<i-d[i])	Q.pop_front();
		f[i]=f[i-1]+1;
		if(!Q.empty())
			f[i]=min(f[i],f[Q.front()]);
	}
	return len-f[len-1]>=k;
}

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[3];
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

	void Calc_Info(){
		for(int i=1;i<=tot;i++)
			C[node[i].step]++;
		for(int i=1;i<=len;i++)
			C[i]=C[i-1]+1;
		for(int i=1;i<=tot;i++){
			Node *p=&node[i];
			tmp[C[p->step]--]=p;
		}
		for(int i=2;i<=tot;i++){
			Node *p=&node[i];
			if(p->fa)
				p->fa->right+=p->right;
		}
	}

	int Run(const char *s){
		int len=strlen(s);
		int k=(len*9+9)/10;
		Node *p=fst;
		for(int i=0,j=0;i!=len;i++){
			while(p!=fst && p->son[s[i]-'0']){
				p=p->fa;
				j=p->step;
			}
			if(p->son[s[i]-'0']){
				p=p->son[s[i]-'0'];
				j++;
			}
			d[i]=j;
		}
		int l=1,r=len+1;
		while(l<r){
			int mid=(l+r)>>1;
			chk(s,mid) ? l=mid+1 : r=mid;
		}
		return l-1;
	}
}SAM;

void init(){
#ifdef Judge
	freopen("2806.in","r",stdin);
	freopen("2806.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	SAM.Init();
	for(int i=1;i<=M;i++){
		scanf("%s",S);
		for(char *c=S;*c;c++)
			SAM.Add(*c-'0');
		SAM.Add(2);
		len+=strlen(S)+1;
	}
}

void work(){
	for(int i=1;i<=N;i++){
		scanf("%s",S);
		int ans=SAM.Run(S);
		print(ans);
		fprintf(stderr,"solved %d/%d,\tAns = %d\n",i,N,ans);
	}
}

int main(){
	init();
	work();

	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(SAM)+3*sizeof(f))/1048576<<" MB."<<endl;
	return 0;
}

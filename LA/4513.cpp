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
// #define Debug
#define MAXN (40005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;
const int X=131;

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
/*
int k,len;
int C[MAXN];
char S[MAXN];
pair<int,int> ans;

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[27];
		int step,right,pos;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=right=pos=0;
		}
	}node[MAXN<<1],*fst,*fnl,*tmp[MAXN<<1];
	int tot;
	
	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}
	
	void Add(int x){
		Node *p=fnl,*np=&node[++tot];
		np->Init();
		np->right=1;
		np->step=p->step+1;
		np->pos=p->step-1;
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
			Node *p=tmp[i];
			if(p->fa)
				p->fa->right+=p->right;	
		}
	}
	
	void Get_ans(){
		pair<int,int> tmp;
		for(int i=2;i<=tot;i++){
			Node *p=&node[i];
			if(p->right>=k){
				tmp=make_pair(p->step,p->pos);
#ifdef Debug
				printf("\tlen = %d , startpos = %d\n", p->step,p->pos);
#endif
				ans=max(ans,tmp);
			}
		}
		if(ans.first==0) goto failed;
		printf("%d %d\n",ans.first,ans.second);
		return;
		failed:;
		puts("none");
	}
}SAM;
*/

char S[MAXN];
int rk[MAXN];
LL H[MAXN],hash[MAXN],base[MAXN];
int len,k;
pair<int,int> ans;

void init(){
#ifdef Judge
	freopen("4513.in","r",stdin);
	freopen("4513.out","w",stdout);
//	SpeedUp;
#endif
}
/*
void work(){
	ans=make_pair(0,0);
	SAM.Init();
	scanf("%s",S);
	len=strlen(S);
	for(int i=0;i<len;i++)
		SAM.Add(S[i]-'a');
	SAM.Topo();
	SAM.Calc_Info();
	SAM.Get_ans();
#ifdef Debug
	puts("----------------------------------");
#endif
}
*/

bool cmp(const int &u,const int &v){
	return hash[u]==hash[v] ? u<v : hash[u]<hash[v];
}

bool chk(int l){
	ans.first=l;
	ans.second=-1;
	int tot=0;
	for(int i=0;i<=len-l;i++){
		rk[i]=i;
		hash[i]=H[i]-H[i+l]*base[l];
	}
	sort(rk,rk+len-l+1,cmp);
	for(int i=0;i<=len-l;i++){
		if(i==0 || hash[rk[i]]!=hash[rk[i-1]])
			tot=0;
		if(++tot>=k)
			ans.second=max(ans.second,rk[i]);
	}
	return ans.second!=-1;
}

void work(){
	scanf("%s",S);
	len=strlen(S);
	H[len]=0;
	for(int i=len-1;i>=0;i--)
		H[i]=H[i+1]*X+(S[i]-'a');
	base[0]=1;
	for(int i=1;i<=len;i++)
		base[i]=base[i-1]*X;
	
	if(chk(1)==0){
		puts("none");
		return;
	}
	int l=1,r=len+1;
	while(l+1<r){
		int mid=l+((r-l)>>1);
		chk(mid) ? l= mid : r=mid;
	}
	chk(l);
	printf("%d %d\n",ans.first,ans.second);
}

int main(){
	init();
	while(scanf("%d",&k)!=EOF && k)
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(SAM)+sizeof(S)+sizeof(C))/1048576<<" MB."<<endl;
#endif
	return 0;
}
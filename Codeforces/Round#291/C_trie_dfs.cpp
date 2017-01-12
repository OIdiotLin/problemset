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
#define MAXN (600005)
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
int N,M;

struct Trie{
	struct Node{
		Node *son[3];
		bool tag;
		void Init(){
			tag=false;
			son[0]=son[1]=son[2]=NULL;
		}
	}node[MAXN],*root;
	int tot;
	
	void Init(){
		root=&node[tot=1];
		root->Init();
	}
	
	void Insert(char str[]){
		int len=strlen(str);
		Node *p=root;
		for(int i=0;i<len;i++){
			int x=str[i]-'a';
			if(p->son[x]==NULL){
				Node *np=&node[++tot];
				np->Init();
				p->son[x]=np;
			}
			p=p->son[x];
		}
		p->tag=true;
	}
	
	bool DFS(Node *p,int cnt,int change){
		int len=strlen(S);
		if(change>1)	return false;
		if(cnt==len)	return p->tag && change==1;
		for(int i=0;i<3;i++)
			if(p->son[i])
				if(DFS(p->son[i],cnt+1,change+(S[cnt]-'a'!=i)))
					return true;
		return false;
	}
}T;

void init(){
#ifdef Judge
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	T.Init();
	for(int i=1;i<=N;i++){
		scanf("%s",S);
		T.Insert(S);
	}
}

void work(){
	for(int i=1;i<=M;i++){
		scanf("%s",S);
		puts(T.DFS(T.root,0,0) ? "YES" : "NO");
	}
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
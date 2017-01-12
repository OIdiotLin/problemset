/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <ctime>
#include <algorithm>
#include <queue>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (1005)
#define MAXM (200000)
#define INF (1<<30)
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

struct Edge{
	int v,next,w;
	Edge(int _v=0,int _n=0,int _w=0):
		v(_v),next(_n),w(_w){}
}E[MAXM];

map<string,int> hash;
int cnt,tot,N;
bool vis[MAXN];
int G[MAXN];

struct Node{
	string Name;
	int dist;
	Node(){dist=INF;Name="Unknown";}
	bool operator < (const Node &t)const{
		return Name<t.Name;
	}
}A[MAXN];

inline int getid(string s){
	if(hash.find(s)!=hash.end()) return hash[s];
	A[++cnt].Name=s;
	return hash[s]=cnt;
}

inline void Ins(int u,int v,int w){
	E[++tot]=Edge(v,G[u],w);	G[u]=tot;
	E[++tot]=Edge(u,G[v],w);	G[v]=tot;
}

void init(){
	string s1,s2,s3;
#ifdef Judge
	freopen("1837.in","r",stdin);
	freopen("1837.out","w",stdout);
//	SpeedUp;
#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>s1>>s2>>s3;
		int a=getid(s1),b=getid(s2),c=getid(s3);
		Ins(a,b,1),Ins(b,c,1),Ins(c,a,1);
	}
}

queue<int> Q;
void SPFA(int S){
	while(!Q.empty())	Q.pop();
	vis[S]=true;
	A[S].dist=0;
	Q.push(S);
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(A[v].dist>A[k].dist+E[u].w){
				A[v].dist=A[k].dist+E[u].w;
				if(!vis[v]){
					vis[v]=true;
					Q.push(v);
				}
			}
		}
		vis[k]=false;
	}
}

bool NoIsenbaev(){
	return hash.find("Isenbaev")==hash.end();
}
void OutNoSolution(){
	sort(A+1,A+cnt+1);
	for(int i=1;i<=cnt;i++)
		cout<<A[i].Name<<" undefined"<<endl;
	exit(0);
}

void work(){
	if(NoIsenbaev()) OutNoSolution();
	int s=getid("Isenbaev");
	SPFA(s);
	sort(A+1,A+cnt+1);
	for(int i=1;i<=cnt;i++){
		cout<<A[i].Name<<" ";
		if(A[i].dist==INF)	cout<<"undefined"<<endl;
		else cout<<A[i].dist<<endl;
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
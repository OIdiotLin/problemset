#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (2005)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

struct Node{
	int x,y;
	void read(){
		cin>>x>>y;
	}
}A[MAXN];
int dist(Node i,Node j){
	return (i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y);
}
struct Edge{
	int x,y,w;
	bool operator < (const Edge&t)const{
		return w<t.w;
	}
}E[MAXN*MAXN];
int N,C,tot,Ans;
int fa[MAXN];
inline void Ins(int x,int y,int d){
	E[++tot]=(Edge){x,y,d};
}
inline int f(int x){
	return fa[x]==x?x:fa[x]=f(fa[x]);
}

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N>>C;
	for(int i=1;i<=N;i++) fa[i]=i;
	for(int i=1;i<=N;i++)
		A[i].read();
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(i!=j)Ins(i,j,dist(A[i],A[j]));
	sort(E+1,E+tot+1);
}

void Kruskal(){
	int cnt=0;
	for(int i=1;i<=tot;i++){
		if(E[i].w<C) continue;
		int fx=f(E[i].x),fy=f(E[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			Ans+=E[i].w;
			cnt++;
		}
	}
	cout<<(cnt<N-1 ? -1 : Ans)<<endl;
}

int main(){
	init();
	Kruskal();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


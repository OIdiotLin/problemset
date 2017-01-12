/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (120)
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
	if(x==0) {putchar('0');return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
}
#define print(x) outputint(x)
#define read(x) x=getint()

vector<int> G[MAXN];
queue<int> Q;
bool color[MAXN];
bool vis[MAXN];
int N;

void init(){
#ifdef Judge
	freopen("1080.in","r",stdin);
	freopen("1080.out","w",stdout);
//	SpeedUp;
#endif
	int x;
	read(N);
	for(int i=1;i<=N;i++)
		while(read(x))
			G[x].push_back(i),G[i].push_back(x);
}

bool BFS(int S){
	Q.push(S);
	vis[S]=true;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(vector<int>::iterator it=G[u].begin();it!=G[u].end();++it){
			if(!vis[*it]){
				color[*it]=color[u]^1;
				Q.push(*it);
				vis[*it]=true;
			}else if(color[*it]==color[u]) return false;
		}
	}
	return true;
}

void work(){
	if(!BFS(1)) {puts("-1"); return;}
	for(int i=1;i<=N;i++)
		print(color[i]);
	puts("");
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
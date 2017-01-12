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
#define MAXN (15)
#define INF ()
const double PI=acos(-1);
const int LHD=1000000007;

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

struct Team{
	int status[MAXN];
	int sz;
	Team(int n=0):
		sz(n){memset(status,0,sizeof(status));}
	void Sort(){
		sort(status+1,status+sz+1);
	}
}T[MAXN];

struct HashList{
	const static int ZCY=19980716;
	int p[ZCY+1],sz;
	
	HashList(int n=0):
		sz(n){memset(p,-1,sizeof(p));}
		
	inline int hash(int k){
		unsigned int res=k;
		for(int i=k;i<=sz;i++)
			res=res*31+T[k].status[i];
		return res%ZCY;
	}
	
	inline void insert(int k,int v){
		p[hash(k)]=v;
	}
	
	inline int find(int k){
		return p[hash(k)];
	}
}Map;
int dfs(int,int);
int DFS(int);
int final[MAXN],N;

void init(){
#ifdef Judge
	freopen("3139.in","r",stdin);
	freopen("3139.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	Map=HashList(N);
	for(int i=0;i<=N;i++)
		T[i]=Team(N);
	for(int i=1;i<=N;i++)
		read(final[i]);
	sort(final+1,final+N+1);
}

int dfs(int home,int away){
	if(away==N+1)	return DFS(home+1);
	int res=0;
	if(T[home].status[home]>=3 && T[home].status[away]<=(N-home-1)*3){
		T[home].status[home]-=3;
		res+=dfs(home,away+1);
		T[home].status[home]+=3;
	}
	if(T[home].status[away]>=3 && T[home].status[home]<=(N-away)*3){
		T[home].status[away]-=3;
		res+=dfs(home,away+1);
		T[home].status[away]+=3;
	}
	if(T[home].status[home] && T[home].status[away] && T[home].status[home]-1<=(N-away)*3 && T[home].status[away]-1<=(N-home-1)*3){
		T[home].status[home]--,T[home].status[away]--;
		res+=dfs(home,away+1);
		T[home].status[home]++,T[home].status[away]++;
	}
	return res;
}

int DFS(int home){
	int res=0;
	if(T[home-1].status[home-1])	return 0;
	if(home==N+1)	return 1;
	T[home]=T[home-1];
	T[home].Sort();
	if((res=Map.find(home))!=-1)
			return res;
	res=dfs(home,home+1);
	Map.insert(home,res);
	return res;
}

void work(){
	for(int i=1;i<=N;i++)
		T[0].status[i]=final[i];
	print(DFS(1));
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
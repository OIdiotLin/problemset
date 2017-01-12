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
#define MAXN (502)
#define MAXM (600005)
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

int tmp[MAXM],id[MAXM],ans[MAXM];
bool tag[MAXM];
int N,M,tot,Max;

struct FenwickTree{
	int s[MAXN][MAXN];
#define lowbit(x)	((x)&-(x))
	FenwickTree(){
		memset(s,0,sizeof(s));
	}
	void Add(int x,int y,int v){
		for(int i=1;i<=N;i+=lowbit(i))
			for(int j=1;j<=N;j+=lowbit(j))
				s[i][j]+=v;
	}
	int Query(int x,int y){
		int res=0;
		for(int i=x;i;i-=lowbit(i))
			for(int j=y;j;j-=lowbit(j))
				res+=s[i][j];
		return res;
	}
}FWT;

struct Query{
	int x1,y1,x2,y2,k;
	Query(){}
	int find(){
		return FWT.Query(x1-1,y1-1)+FWT.Query(x2,y2)-FWT.Query(x1-1,y2)-FWT.Query(x2,y1-1);
	}
	void Read(){
		read(x1),read(y1),read(x2),read(y2),read(k);
	}
}Q[MAXM];

struct Node{
	int x,y,val;
	Node(int _x=0,int _y=0,int _v=0):
		x(_x),y(_y),val(_v){}
	bool operator < (const Node &t) const{
		return val<t.val;
	}
}A[MAXN*MAXN];

void init(){
#ifdef Judge
	freopen("2738.in","r",stdin);
	freopen("2738.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			A[++tot]=Node(i,j,getint());
			Max=max(Max,A[tot].val);
		}
	sort(A+1,A+tot+1);
	for(int i=1;i<=M;i++)
		Q[i].Read(),id[i]=i;
}

void solve(int l,int r,int L,int R){
	static int p=0;
	if(l>r || L==R)	return;
	int mid=(L+R)>>1;
	while(A[p+1].val<=mid && p<tot){
		FWT.Add(A[p+1].x,A[p+1].y,1);
		p++;
	}
	while(A[p].val>mid){
		FWT.Add(A[p].x,A[p].y,-1);
		p--;
	}
	int cnt=0;
	for(int i=l;i<=r;i++)
		if(Q[id[i]].find()>Q[id[i]].k-1){
			tag[i]=true;
			ans[id[i]]=mid;
			cnt++;
		}else tag[i]=false;
	int k1=l,k2=l+cnt;
	for(int i=l;i<=r;i++)
		tmp[(tag[i]?k1:k2)++]=id[i];
	for(int i=l;i<=r;i++)
		id[i]=tmp[i];
	solve(l,k1-1,L,mid);
	solve(k1,k2-1,mid+1,R);
#ifdef Debug
	printf("%d %d %d %d:\n",l,r,L,D);
#endif
}

void work(){
	solve(1,M,0,Max+1);
	for(int i=1;i<=M;i++)
		print(ans[i]);
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
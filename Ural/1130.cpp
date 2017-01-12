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
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

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
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x)	x=getint()
#define sqr(x)	((x)*(x))

const int K[2]={-1,1};

struct Vec{
	int x,y;
	Vec(int _x=0,int _y=0):
		x(_x),y(_y){}
	inline Vec operator + (const Vec&t)const{
		return Vec(x+t.x,y+t.y);
	}
	inline Vec operator * (const int&a)const{
		return Vec(x*a,y*a);
	}
#ifdef Debug
	void Print(){
		printf("x=%d,y=%d\n",x,y);
	}
#endif
}V[MAXN];
int L,N;
int next[MAXN];
bool lambda[MAXN],vis[MAXN];

inline bool check(Vec v){
	return sqr(v.x)+sqr(v.y)<=L;
}

inline void nega(int p){
	if(p==0) return;
	lambda[p]=!lambda[p];
	nega(next[p]);
}

void init(){
#ifdef Judge
	freopen("1130.in","r",stdin);
	freopen("1130.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d%d",&N,&L);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&V[i].x,&V[i].y);
	}
}

void Find(){
	lambda[1]=true;
	for(int i=1;i<=N;i++)	if(!vis[i])
		for(int j=i+1;j<=N;j++)	if(!vis[j])
			for(int k=0;k<2;k++)
				if(check(V[i]+(V[j]*K[k]))){
					lambda[j]=k;
					vis[j]=true;
					next[i]=j;
					V[i]=V[i]+(V[j]*K[k]);
					if(k==0)nega(next[j]);
					return;
				}
}

void work(){
	lambda[1]=true;
	L=sqr(L);
	for(int i=3;i<=N;i++)
		Find();
	L<<=1;
	Find();
	puts("YES");
	for(int i=1;i<=N;i++)
		putchar(lambda[i] ? '+' : '-');
	puts("");
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(V)+sizeof(lambda)+2*sizeof(vis))/1048576<<" MB."<<endl;
#endif
	return 0;
}
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
#define MAXN (500005)
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

struct Node{
	int l,r,id;
	Node(int _l=0,int _r=0,int _id=0):
		l(_l),r(_r),id(_id){}
};
int N;
int A[MAXN];
double f[2][MAXN];
// queue<Node> Q;
Node Q[MAXN];

double h(int l,int r){
	return A[l]+sqrt(abs(r-l))-A[r];
}

void init(){
#ifdef Judge
	freopen("2216.in","r",stdin);
	freopen("2216.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++)
		read(A[i]);
}

int find(Node P,int x){
	int l=P.l,r=P.r;
	while(l<=r){
		int mid=(l+r)>>1;
		h(P.id,mid)>h(x,mid) ? l=mid+1 : r=mid-1;
	}
	return l;
}

void DP(int k){
	int head=1,tail=0;
	for(int i=1;i<=N;i++){
		Q[head].l++;
		if(head<=tail && Q[head].r<Q[head].l)	head++;
		// if(head<=tail && h(i,N)<=h(Q[head].id,N))	continue;
		if(head>tail || h(i,N)>h(Q[tail].id,N)){
			while(head<=tail && h(i,Q[tail].l)>h(Q[tail].id,Q[tail].l))	tail--;
				if(head>tail)
					Q[++tail]=Node(i,N,i);
				else{
					int p=find(Q[tail],i);
					Q[tail].r=p-1;
					Q[++tail]=Node(p,N,i);
				}
		}
		f[k][i]=h(Q[head].id,i);
	}
}

void work(){
	DP(0);
	for(int i=1;i<=N>>1;i++)
		 swap(A[i],A[N-i+1]);
	DP(1);
	for(int i=1;i<=N;i++)
		print((int)ceil(max(f[0][i],f[1][N-i+1])));
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
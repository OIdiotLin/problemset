/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (17005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const int Blk_Sz=619;

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

int N,M,Q;
int sz;
int C[50005],rk[50005];
int f[81][81][MAXN],Sum[81][MAXN];
int vis[50005];

void init(){
#ifdef Judge
	freopen("2906.in","r",stdin);
	freopen("2906.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M),read(Q);
	for(int i=0;i<N;i++)
		read(C[i]);
	memcpy(rk,C,sizeof(rk));
	sz=N/Blk_Sz;
	sort(rk,rk+N);
	M=unique(rk,rk+N)-rk;
	for(int i=0;i<N;++i)
		C[i]=lower_bound(rk,rk+M,C[i])-rk;
}

#define sqr(x) ((x)*(x))

void Blk_Init(){
	for(int i=0;i<=sz;i++){
		for(int j=i*Blk_Sz;j<min((i+1)*Blk_Sz,N+1);j++)
			Sum[i][C[j]]++;
		if(i!=0)
			for(int j=0;j<M;j++)
				Sum[i][j]+=Sum[i-1][j];
	}
	for(int i=0;i<=sz;i++)
		for(int j=i;j<=sz;j++)
			for(int k=0;k<M;k++){
				f[i][j][k]=sqr(Sum[j][k]-Sum[i-1][k]);
				if(k) f[i][j][k]+=f[i][j][k-1];
			}
}

#define InRange(x) (a<=(x) && (x)<=b)

inline int Query(int l,int r,int a,int b){
	int posl=l/Blk_Sz,posr=r/Blk_Sz;
	int ret=0;
	if(posl<posr-1) ret=f[posl+1][posr-1][b]-f[posl+1][posr-1][a-1];
	if(posl==posr){
		for(int i=l;i<=r;i++)
			if(InRange(C[i]))
				ret+=((++vis[C[i]])<<1)-1;
		for(int i=l;i<=r;i++)
			vis[C[i]]=0;
		return ret;
	}
	for(int i=min((posl+1)*Blk_Sz-1,N);i>=l;i--)
		if(InRange(C[i])){
			if(!vis[C[i]])
				vis[C[i]]=Sum[posr-1][C[i]]-Sum[posl][C[i]];
			ret+=((++vis[C[i]])<<1)-1;
		}
	for(int i=posr*Blk_Sz;i<=r;i++)
		if(InRange(C[i])){
			if(!vis[C[i]])
				vis[C[i]]=Sum[posr-1][C[i]]-Sum[posl][C[i]];
			ret+=((++vis[C[i]])<<1)-1;
		}
	for(int i=(posl+1)*Blk_Sz-1;i>=l;i--)
		vis[C[i]]=0;
	for(int i=posr*Blk_Sz;i<=r;i++)
		vis[C[i]]=0;
	return ret;
}

void work(){
	int l,r,a,b;
	int lAns=0;
	while(Q--){
		read(l),read(r),read(a),read(b);
		l^=lAns,r^=lAns,a^=lAns,b^=lAns;
		--l,--r;
		a=lower_bound(rk,rk+M,a)-rk;
		b=upper_bound(rk,rk+M,b)-rk-1;
		print (lAns=Query(l,r,a,b));
	}
}

int main(){
	init();
	Blk_Init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
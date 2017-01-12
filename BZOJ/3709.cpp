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
#define MAXN (100005)
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
	putchar(32);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Monster{
	int dam,reg;
	int id;
}A[MAXN],B[MAXN];
inline bool cmp1(Monster a,Monster b){return a.dam<b.dam;}
inline bool cmp2(Monster a,Monster b){return a.reg>b.reg;}
LL N,Z,tot1,tot2;

void init(){
	int d,a;
#ifdef Judge
	freopen("3709.in","r",stdin);
	freopen("3709.out","w",stdout);
#endif
	read(N),read(Z);
	for(int i=1;i<=N;i++){
		read(d),read(a);
		if(d<=a) A[++tot1]=(Monster){d,a,i};
		else B[++tot2]=(Monster){d,a,i};
	}
}

void work(){
	sort(A+1,A+tot1+1,cmp1);
	for(int i=1;i<=tot1;i++)
		if(Z<=A[i].dam){
			cout<<"NIE"<<endl;
			return;
		}else Z-=(A[i].dam-A[i].reg);
	sort(B+1,B+tot2+1,cmp2);
	for(int i=1;i<=tot2;i++)
		if(Z<=B[i].dam){
			cout<<"NIE"<<endl;
			return;
		}else Z-=(B[i].dam-B[i].reg);
	cout<<"TAK"<<endl;
	for(int i=1;i<=tot1;i++)
		print(A[i].id);
	for(int i=1;i<=tot2;i++)
		print(B[i].id);
	cout<<endl;
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
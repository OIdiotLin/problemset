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
#define MAXN (130)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
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
#define read(x) x=getint()

int FwT[MAXN][MAXN][MAXN];
int N;

inline int lowbit(int x){
	return x&(-x);
}

void init(){
#ifdef Judge
	freopen("1470.in","r",stdin);
	freopen("1470.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
}

inline int Query(int X,int Y,int Z){
	int ret=0;
	int x=X,y=Y,z=Z;
	while(x){
		y=Y;
		while(y){
			z=Z;
			while(z){
				ret+=FwT[x][y][z];
				z-=lowbit(z);
			}
			y-=lowbit(y);
		}
		x-=lowbit(x);
	}
	return ret;
}

inline void Modify(int X,int Y,int Z,int v){
	int x=X,y=Y,z=Z;
	while(x<=N){
		y=Y;
		while(y<=N){
			z=Z;
			while(z<=N){
				FwT[x][y][z]+=v;
				z+=lowbit(z);
			}
			y+=lowbit(y);
		}
		x+=lowbit(x);
	}
}

void work(){
	int CMD,x1,y1,z1,x2,y2,z2,v,Ans;
	while(true){
		read(CMD);
		switch(CMD){
			case 1:	read(x1),read(y1),read(z1),read(v);
					Modify(x1+1,y1+1,z1+1,v);
					break;
			case 2:	read(x1),read(y1),read(z1),read(x2),read(y2),read(z2);
					Ans=Query(x2+1,y2+1,z2+1)
							-Query(x2+1,y2+1,z1)-Query(x2+1,y1,z2+1)-Query(x1,y2+1,z2+1)
							+Query(x1,y1,z2+1)+Query(x1,y2+1,z1)+Query(x2+1,y1,z1)
							-Query(x1,y1,z1);
					print(Ans);
					break;
			case 3:	return;
			default:cout<<"Error"<<endl; return;
		}
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
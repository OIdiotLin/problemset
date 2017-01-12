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
#define MAXN (12)
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

#define sqr(x)	((x)*(x))

int ran_lim=300000;
int N;

inline double Rand(){
	return (double)rand()/RAND_MAX;
}

struct Circle{
	double x,y,r;
	Circle(double _x=0,double _y=0,double _r=0):
		x(_x),y(_y),r(_r){}
	bool cover(double px,double py){
		return sqr(r)>sqr(px-x)+sqr(py-y);
	}
}C[MAXN];

void init(){
	srand(time(NULL));
#ifdef Judge
	freopen("1333.in","r",stdin);
	freopen("1333.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%lf%lf%lf",&C[i].x,&C[i].y,&C[i].r);
}

void work(){
	int cnt=0;
	for(int k=1;k<=ran_lim;k++){
		double x=Rand(),y=Rand();
		for(int i=1;i<=N;i++)
			if(C[i].cover(x,y)){
				cnt++;
				break;
			}
	}
#ifdef Debug
	printf("Rand points algorithm:\t");
#endif
	printf("%lf\n",(double)cnt/ran_lim*100);
#ifdef Debug
	printf("Divide grids algorithm:\t");
	cnt=0;
	for(double x=0;x<1;x+=0.01) for(double y=0;y<1;y+=0.01)
		for(int i=1;i<=N;i++)
		if(C[i].cover(x,y)){
			cnt++;
			break;
		}
	printf("%lf\n",(double)cnt/100);
#endif
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	// cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
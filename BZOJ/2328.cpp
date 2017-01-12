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
#define INF (1<<30)
const double PI=acos(-1);
const int ZCY=1000000007;

const double eps=1e-18;
const double eps2=1e-7;
const double lim=24;

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

inline bool equal(double x,double y){
	return fabs(x-y)<eps;
}

int T,N;
double a,b,vmax,f,curS;
double L[MAXN],k[MAXN];
double fmind[MAXN],fminc[MAXN],fmaxt[MAXN];
double mind,maxd;		// Try

#define sqr(x) ((x)*(x))
inline double c2d(double cost,int i){
	double res=-sqr(L[i])*a/sqr(cost-b*k[i]*L[i]);
	return equal(res,0) ? 0 : res;
}
inline double c2t(double cost,int i){
	double res=sqr(L[i])*a/(cost-b*k[i]*L[i]);
	return equal(res,0) ? 0 : res;
}
inline double c2v(double cost,int i){
	double res=(cost-b*k[i]*L[i])/(a*L[i]);
	return equal(res,0) ? 0 : res;
}
inline double d2c(double d,int i){
	double res=sqrt(-sqr(L[i])*a/d)+b*k[i]*L[i];
	return equal(res,0) ? 0 : res;
}

pair<double,double> calc(double d){
	double t=0,c=0;
	for(int i=1;i<=N;i++){
		if(fmind[i]>=d){
			t+=fmaxt[i];
			c+=fminc[i];
			continue;
		}
		double cost=d2c(d,i);
		if(c2v(cost,i)>=vmax){
			t+=L[i]/vmax;
			c+=L[i]*(a*vmax+b*k[i]);
			continue;
		}
		t+=c2t(cost,i);
		c+=cost;
	}
// #ifdef Debug
	// printf("\tcalc(%lf): x = %lf, y = %lf\n",d,t,c);
// #endif
	return make_pair(t,c);
}

void init(){
#ifdef Judge
	freopen("2328.in","r",stdin);
	freopen("2328.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&T);
}

bool chk_arrv(){
	double sum=0;
	for(int i=1;i<=N;i++)
		if(k[i]>0)
			sum+=b*k[i]*L[i];
	if(sum!=0 && sum>=f-eps2)	return false;
	return true;
}

bool Init(){
	double dx,dy;
	scanf("%lf%lf%lf%lf%d",&a,&b,&vmax,&f,&N);
	for(int i=1;i<=N;i++){
		scanf("%lf%lf",&dx,&dy);
		L[i]=sqrt(sqr(dx)+sqr(dy))/1000;
		k[i]=dy/dx;
	}
	if(!chk_arrv()){
		puts("IMPOSSIBLE");
		return false;
	}
	int tot=0;
	mind=INF,maxd=-INF;
	curS=0;
	for(int i=1;i<=N;i++)
		if(k[i]<0 && (k[i]*b/a)<=-vmax){
			curS+=L[i]/vmax;
		}else{
			L[++tot]=L[i];
			k[tot]=k[i];
		}
	N=tot;
#ifdef Debug
	for(int i=1;i<=tot;i++)
		printf("%lf ",L[i]);
	puts("");
#endif
	double cost;
	for(int i=1;i<=N;i++){
		if(k[i]<0)	cost=0;
		else	cost=L[i]*(a*L[i]/lim+b*k[i]);
		fminc[i]=cost;
		fmaxt[i]=c2t(cost,i);
		fmind[i]=c2d(cost,i);
		mind=min(mind,fmind[i]);
	}
	for(int i=1;i<=N;i++)
		maxd=max(maxd,c2d(f,i));
	return true;
}

void work(){
	if(!Init()) return;
	pair<double,double> p;
	double l=mind,r=maxd;
#ifdef Debug
	printf("curS = %lf\tmind = %lf\tmaxd = %lf\n",curS,l,r);
#endif
	for(int i=1;i<80;i++){
		double mid=(l+r)/2.0;
#ifdef Debug
		printf("\tmid = %lf\n",mid);
#endif
		p=calc(mid);
#ifdef Debug
		printf("\tp->first = %lf\n",p.first);
#endif
		if(p.first>lim)	l=mid;
		else if(p.second>f)	r=mid;
		else if(p.second<f)	l=mid;
	}
	p=calc((l+r)/2);
	p.first+=curS;
	if(p.first>lim||p.second>f+eps2)
		puts("IMPOSSIBLE");
	else
		printf("%.5lf\n",p.first);
}

int main(){
	init();
	while(T--){
		work();
#ifdef Debug
		puts("---------------------------------------------------------");
#endif
	}
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(k)*5)/1048576<<" MB."<<endl;
#endif
	return 0;
}

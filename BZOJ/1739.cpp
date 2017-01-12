/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (400005)
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

struct Brick{
	int h,lim,num;
	Brick(int _h=0,int _lim=0,int _num=0):
		h(_h),lim(_lim),num(_num){}
	bool operator < (const Brick &t)const{
		return lim<t.lim;
	}
};
vector<Brick> A;
int S[MAXN],f[MAXN];
int N;

void init(){
	int h,a,c;
#ifdef Judge
	freopen("1739.in","r",stdin);
	freopen("1739.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		read(h),read(a),read(c);
		A.push_back(Brick(h,a,c));
	}
	sort(A.begin(),A.end());
}

void work(){
	int Ans=0;
	f[0]=1;
	for(vector<Brick>::iterator it=A.begin();it!=A.end();++it){
		memset(S,0,sizeof(S));
		for(int i=it->h;i<=it->lim;i++)
			if(f[i]==0 && f[i-it->h] && S[i-it->h]<it->num){
				f[i]=1;
				S[i]=S[i-it->h]+1;
				Ans=max(Ans,i);
			}
	}
	print(Ans);
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
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
#define MAXN (10)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

const int score[]={3,1,0,0};

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

int N,tot;
int final[MAXN],Sum[MAXN];

void init(){
#ifdef Judge
	freopen("1306.in","r",stdin);
	freopen("1306.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++)
		read(final[i]);
}

void dfs(int home,int away){
	if(Sum[home]>final[home])	return;
	if(Sum[home]+(N-away+1)*3<final[home])	return;
	if(home==N){
		tot++;return;
	}
	if(away==N){
		int delta=final[home]-Sum[home];
		if(delta==2)	return;
		Sum[away]+=score[delta];
		dfs(home+1,home+2);
		Sum[away]-=score[delta];
		return;
	}
	Sum[home]+=3,dfs(home,away+1),Sum[home]-=3;	//Win
	Sum[away]+=3,dfs(home,away+1),Sum[away]-=3;	//Lose
	Sum[home]+=1,Sum[away]+=1,dfs(home,away+1),Sum[home]-=1,Sum[away]-=1;	//Draw
}

void work(){
	dfs(1,2);
	print(tot);
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
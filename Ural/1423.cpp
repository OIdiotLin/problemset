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
#define MAXN (300001)
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

int N;
int nxt[MAXN];
string S,T;

void get_fail(){
	nxt[0]=-1;
	for(int i=0,j=-1;i!=N;){
		if(j==-1 || T[i]==T[j]) nxt[++i]=++j;
		else j=nxt[j];
	}
}

void init(){
#ifdef Judge
	freopen("1423.in","r",stdin);
	freopen("1423.out","w",stdout);
//	SpeedUp;
#endif
	cin>>N>>S>>T;
	S=S+S;
}

int find(){
	get_fail();
	int i,j;
	int N=S.length(),M=T.length();
	for(i=0,j=0;i!=N && j!=M;)
		if(j==-1 || S[i]==T[j]) ++i,++j;
		else j=nxt[j];
	return (j>=M?i-j:-1);
}

void work(){
	int Ans=find();
	switch(Ans){
		case -1	:cout<<-1<<endl;break;
		case 0	:cout<<0<<endl;break;
		default	:cout<<N-Ans<<endl;
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
 
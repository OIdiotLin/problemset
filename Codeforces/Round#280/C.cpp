/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
#define MAXN (300001)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline LL getint(){
	LL x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define min(x,y) ((x)>(y) ? (y) : (x))

int N,R;
LL Sum,Avg;

struct Node{
	int grade,essays;
	LL limit;
	Node(int _g=0,int _e=0):
		grade(_g),essays(_e){limit=R-_g;}
	bool operator < (const Node &t)const{
		return essays<t.essays;
	}
};

vector<Node> A;

void init(){
	int grade,cost;
#ifdef Judge
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(R),read(Avg);
	Avg*=N;
	for(int i=1;i<=N;i++){
		read(grade),read(cost);
		Sum+=grade;
		A.push_back(Node(grade,cost));
	}
}

void work(){
	LL Ans=0;
	if(Sum>=Avg){
		puts("0");
		return;
	}
	sort(A.begin(),A.end());
	for(vector<Node>:: iterator it=A.begin();it!=A.end() && Sum<Avg;++it){
		LL tmp=min(it->limit,Avg-Sum);
		Sum+=tmp;
		Ans+=tmp*(it->essays);
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
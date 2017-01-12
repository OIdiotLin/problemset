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
#include <vector>
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

struct Job{
	int B,J;
	inline bool operator < (const Job&T)const{
		return J>T.J;
	}
	inline void Read(){
		read(B),read(J);
	}
};
int N,cnt;

void init(){
#ifdef Judge
	freopen("11729.in","r",stdin);
	freopen("11729.out","w",stdout);
//	SpeedUp;
#endif
	cnt=0;
}

void work(){
	int Ans=0,s=0;
	vector<Job> A;
	Job t;
	for(int i=1;i<=N;i++)
		t.Read(),A.push_back(t);
	sort(A.begin(),A.end());
	for(int i=0;i<N;i++){
		s+=A[i].B;
		Ans=max(Ans,s+A[i].J);
	}
	cout<<"Case "<<++cnt<<": ";
	print(Ans);
}

int main(){
	init();
	while(read(N))
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
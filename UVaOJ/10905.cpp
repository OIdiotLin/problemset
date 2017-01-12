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

vector<string> S;
int N;

inline bool cmp(const string &a,const string &b){
	if(a.length()==b.length()) return a>b;
	return a+b>b+a;
}

void init(){
	string s;
#ifdef Judge
	freopen("10905.in","r",stdin);
	freopen("10905.out","w",stdout);
//	SpeedUp;
#endif
	while(true){
		S.clear();
		cin>>N;
		if(N==0) return;
		for(int i=1;i<=N;i++){
			cin>>s;
			S.push_back(s);
		}
		sort(S.begin(),S.end(),cmp);
		for(vector<string>::iterator it=S.begin();it!=S.end();++it)
			cout<<*it;
		cout<<endl;
	}
}

int main(){
	init();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
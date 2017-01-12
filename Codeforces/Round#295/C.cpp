/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
#define MAXN (300001)
#define INF ()
const double PI=acos(-1);
const LL ZCY=1000000007;

inline LL getLL(){
	LL x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputLL(LL x){
	char ch[12];
	LL cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define prLL(x) outputLL(x)
#define read(x) x=getLL()

LL N;
map<char,LL>hash;
char data[]={'A','G','C','T'};
string S;

void init(){
#ifdef Judge
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
//	SpeedUp;
#endif
	cin>>N;
	cin>>S;
	long long maxlen=0,sum=0,ans=1;
	for(LL i=0;i<N;i++)hash[S[i]]++;
	for(LL i=0;i<4;i++)
		if(hash[data[i]]>maxlen)maxlen=hash[data[i]],sum=1;
		else if(maxlen==hash[data[i]])sum++;
	for(LL i=0;i<N;i++)
		ans=(ans*sum)%ZCY;
	cout<<ans<<endl;
} 


int main(){
	init();
//	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
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
//#define Judge
//#define Debug
#define MAXN (200005)
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


LL n,m,ny,ans;
char c[MAXN];
LL s[MAXN],jc[MAXN],s1[MAXN],mi[MAXN];

void exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b) {y=0; x=1; return;}
	exgcd(b,a%b,y,x); y-=x*(a/b);
}
LL get(LL x,LL y)
{
	LL ret=s[x]-s[y+1];
	while(ret<0) ret+=ZCY;
	if(y==n) return ret;
	LL dota,osu;
	exgcd(mi[n-y],ZCY,dota,osu);
	while(dota<0) dota+=ZCY;
	ret=(ret*dota)%ZCY;
	return ret;
}
LL C(LL x,LL y)
{
	if(y>x) return 0;
	y=min(y,x-y);
	if(y==0) return 1;
	LL ret=jc[x],dota,lol;
	exgcd(jc[y],ZCY,dota,lol);
	while(dota<0) dota+=ZCY;
	ret=(ret*dota)%ZCY;
	exgcd(jc[x-y],ZCY,dota,lol);
	while(dota<0) dota+=ZCY;
	ret=(ret*dota)%ZCY;
	return ret;
}

void init(){
#ifdef Judge
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	SpeedUp;
#endif
	LL i;cin>>n>>m;getchar();
	for(i=1;i<=n;i++) scanf("%c",&c[i]);
	LL god,now=0;
	exgcd(10,ZCY,ny,god); god=1;
	for(i=n;i>=1;i--)
	{
		s[i]=(s[i+1]+(c[i]-48)*god)%ZCY;
		god=(god*10)%ZCY;
	}
	if(m==0) {cout<<s[1]<<endl; return;}
	for(i=n;i>=1;i--) s1[i]=s1[i+1]+c[i]-48;
	jc[0]=1;
	mi[0]=1;
	for(i=1;i<=n;i++) 
		mi[i]=(mi[i-1]*10)%ZCY;
	for(i=1;i<=n;i++) 
		jc[i]=(jc[i-1]*i)%ZCY;
	for(i=2;i<n;i++) 
		now+=(c[i]-48);
	if(m>1)for(i=1;i<=n-2;i++){
		LL osu=C(n-i-2,m-2);
		ans=(ans+now*osu)%ZCY;
		now=(now*10)%ZCY;
		now-=(get(n-i,n-1)*10)%ZCY;
		now+=s1[i+2]-s1[n];
		while(now<0) now+=ZCY;
	}
	for(i=1;i<=n-m;i++){
		ans=(ans+get(1,i)*C(n-1-i,m-1))%ZCY;
		ans=(ans+get(n-i+1,n)*C(n-1-i,m-1))%ZCY;
	}
	cout<<ans<<endl;
}

int main(){
	init();
}
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (3500)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

string S;
char st[MAXN];
int p[MAXN];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("1297.in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
	int Len=2;
	cin>>S;
	st[0]='@',st[1]='#';
	for(int i=0;i<S.length();i++,Len+=2){
		st[Len]=S[i];st[Len+1]='#';
	}
	st[Len]=0;
}

void Manacher(){
	int Ans=0,mx=0,id;
	int POS=1;
	for(int i=1;st[i];i++){ 
		p[i]=(mx>i ? min(p[2*id-i],mx-i) : 1);
		while(st[i+p[i]]==st[i-p[i]]) p[i]++;
		if(i+p[i]>mx){mx=p[i]+i;id=i;}
		if(p[i]>Ans){
			Ans=p[i];
			POS=i;
		}
	}
	for(int i=POS-Ans+2;i<POS+Ans;i+=2)
		cout<<st[i];
	cout<<endl;
}

int main(){
	init();
	Manacher();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


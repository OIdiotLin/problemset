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
#define MAXN (250005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
	const int key[27]={2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};
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

struct Trie{
	int v[MAXN],ch[MAXN][10];
	int sz;
	inline void Init(){
		sz=1,memset(ch[0],0,sizeof(ch[0]));
	}
	
	Trie(){Init();}
	
	inline int id(char ch){
		return key[ch-'a'];
	}
	
	inline void Ins(string s,int va){
		int x=0,len=s.length();
		for(int i=0;i<len;i++){
			int c=id(s[i]);
			if(!ch[x][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				v[sz]=0;
				ch[x][c]=sz++;
			}
			x=ch[x][c];
		}
		v[x]=va;
	}
}T;

string S;
string words[60];
int pre[105],f[105],cnt[105],ans[105];

void init(){
#ifdef Judge
	freopen("1578.in","r",stdin);
	freopen("1578.out","w",stdout);
	SpeedUp;
#endif
}

void work(){
	int N,len;
	while(cin>>S){
		if(S[0]=='-') return;
		cin>>N;
		len=S.length();
		memset(f,127,sizeof(f));
		f[len]=0;
		T.Init();
		memset(pre,-1,sizeof(pre));
		
		for(int i=1;i<=N;i++){
			cin>>words[i];
			T.Ins(words[i],i);
		}
		
		for(int i=len-1;i>=0;i--){
			int x=0;
			for(int j=i;j!=len;j++){
				int c=S[j]-'0';
				if(!T.ch[x][c]) break;
				x=T.ch[x][c];
				if(T.v[x] && f[i]>f[j+1]+1){
					f[i]=f[j+1]+1;
					pre[i]=j+1;
					cnt[i]=T.v[x];
				}
			}
		}
		if(f[0]==f[len+1]){cout<<"No solution."<<endl; continue;}
		
		int tot=0;
		for(int i=0;pre[i]!=-1;i=pre[i]) ans[tot++]=cnt[i];
		for(int i=0;i!=tot;i++) cout<<words[ans[i]]<<" ";
		cout<<endl;
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

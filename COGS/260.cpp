#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 30005
#define INF (1<<30)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

int fa[MAXN],cnt[MAXN],Set[MAXN];
int N,x,y;
char O;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	#endif
	cin>>N;
	memset(Set,0,sizeof(Set));
//	memset(cnt,1,sizeof(cnt));
	for(int i=0;i<MAXN;i++){
		fa[i]=i;
		cnt[i]=1;
	}
}

int find(int x){
	if(x==fa[x]) return x;
	int t=find(fa[x]);
	Set[x]+=Set[fa[x]];
	fa[x]=t;
	return fa[x];
}

void Merge(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
	Set[x]+=cnt[y];
	cnt[y]+=cnt[x];
}

void work(){
	while(N--){
		cin>>O;
		switch(O){
			case 'M':{
				cin>>x>>y;
				if(fa[x]!=fa[y])			//Different pile
					Merge(x,y);
				break;
			}
			case 'C':{
				cin>>x;
				find(x);
				cout<<Set[x]<<endl; 
				break;
			}
		}
	}
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(fa)*3)/1024/1024<<" MB."<<endl;
	#endif
	return 0;
}



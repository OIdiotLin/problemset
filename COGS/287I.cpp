#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<queue>
using namespace std;
const int SIZEN=100001,INF=0x7fffffff;
vector<pair<int,int> > c[SIZEN];//邻接表
int n,m;
bool visit[SIZEN]={0};
int f[SIZEN]={0};
int limit=0;
int deepest=0,shallowest=INF;
int treeans=0;
bool circle=false;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void DFS(int x,int d){//x的"距离"是d
	if(visit[x]) return;
	visit[x]=true;
	f[x]=d;
	deepest=max(deepest,d);
	shallowest=min(shallowest,d);
	int i,now;
	for(i=0;i<c[x].size();i++){
		now=c[x][i].first;
		if(!visit[now]) DFS(now,d+c[x][i].second);
		else{
			int temp=abs(d+c[x][i].second-f[now]);
			if(temp){
				circle=true;
				limit=gcd(limit,temp);
			}
		}
	}
}
int limited_fac(int x){
	int ans=INF;
	int i;
	int high=(int)sqrt((double)x);
	for(i=1;i<=high;i++){
		if(x%i==0){
			if(i>=3) ans=min(ans,i);
			ans=min(ans,x/i);
		}
	}
	return ans;
}
void traver(void){//遍历整个图
	int i;
	for(i=1;i<=n;i++){
		if(visit[i]) continue;
		deepest=0;
		shallowest=INF;
		DFS(i,0);
		treeans+=(deepest-shallowest+1);
	}
}
void write(void){
	if(!circle){//树结构
		if(treeans<3){//无合法方案
			printf("-1 -1\n");
		}
		else{
			printf("%d ",treeans);
			printf("3\n");
		}
	}
	else{//环结构	
		if(limit<3){//无合法方案
			printf("-1 -1\n");
		}
		else{
			printf("%d ",limit);
			printf("%d\n",limited_fac(limit));
		}
	}
}
void read(void){
	scanf("%d%d",&n,&m);
	int i,a,b;
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);//a可见b
		c[a].push_back(make_pair(b,1));
		c[b].push_back(make_pair(a,-1));
	}
}
int main(){
	freopen("party2008.in","r",stdin);
//	freopen("party2008.out","w",stdout);
	read();
	traver();
	write();
	return 0;
}

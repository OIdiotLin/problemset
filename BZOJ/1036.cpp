#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstdio>
#define MAXN (30010)
#define INF (1<<29)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

#define CLEAR(a) memset(a,0,sizeof(a))

vector<int> G[MAXN];
int N,Q;
int A[MAXN],B[MAXN];

struct SegTree{
	struct Node{
		int l,r;
		int v,Maxv,Sum;
		int lc,rc;
		Node(int l=0,int r=0):l(l),r(r){
			v=Maxv=Sum=-INF;
			lc=rc=0;
		}
	}st[MAXN*3];
	int cnt;
	void init(){
		cnt=0;
	}
	SegTree(){
		init();
	}
	
	void Update(int num){
		st[num].Maxv=-INF;
		if(st[num].lc && st[num].rc){
			st[num].Maxv=max(st[st[num].rc].Maxv,st[st[num].lc].Maxv);
			st[num].Sum=st[st[num].rc].Sum+st[st[num].lc].Sum;
		}else{
			st[num].Maxv=st[num].v;
			st[num].Sum=st[num].v;
		}
	}
	
	void Make(int *x,int l,int r,int num){
		st[num]=Node(l,r);
		if(l==r){
			st[num].v=x[l];
		}else{
			int mid=(l+r)>>1;
			st[num].lc=cnt;
			Make(x,l,mid,cnt++);
			st[num].rc=cnt;
			Make(x,mid+1,r,cnt++);
		}
		Update(num);
	}
	
	int getMaxv(int l,int r,int num){
		if(st[num].l>r || st[num].r<l) return -INF;
		else if(st[num].l>=l && st[num].r<=r) return st[num].Maxv;
		else{
			int ret=-INF;
			ret=max(ret,getMaxv(l,r,st[num].lc));
			ret=max(ret,getMaxv(l,r,st[num].rc));
			return ret;
		}
	}
	
	int getSum(int l,int r,int num){
		if(st[num].l>r || st[num].r<l) return 0;
		else if(st[num].l>=l && st[num].r<=r) return st[num].Sum;
		else{
			int ret=0;
			ret+=getSum(l,r,st[num].lc);
			ret+=getSum(l,r,st[num].rc);
			return ret;
		}
	}
	
	void Change(int tar,int v,int num){			//Change tar to v.
		if(st[num].l==st[num].r) st[num].v=v;
		else{
			int mid=(st[num].l+st[num].r)>>1;
			if(tar<=mid) Change(tar,v,st[num].lc);
			else Change(tar,v,st[num].rc);
		}
		Update(num);
	}
};

struct Heavy_Chain{
	int fa[MAXN],son[MAXN],dep[MAXN],size[MAXN],top[MAXN],hash[MAXN];
	int dfs_time;
	SegTree st;
	void init(){
		st.init();
		dfs_time=1;
		CLEAR(fa);CLEAR(son);CLEAR(dep);
		CLEAR(size);CLEAR(top);CLEAR(hash);
	}
	Heavy_Chain(){
		init();
	}
	
	void dfs1(int u,int f,int deep){
		fa[u]=f,dep[u]=deep,size[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(v!=f){
				dfs1(v,u,deep+1);
				size[u]+=size[v];
			}
		}
	}
	
	void dfs2(int u,int Top){
		top[u]=Top;
		hash[u]=dfs_time++;
		
		int Max_Size=0,Max_HeavySon=0;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(v==fa[u]) continue;
			if(size[v]>Max_Size){
				Max_Size=size[v];
				Max_HeavySon=v;
			}
		}
		
		if(Max_Size){
			dfs2(Max_HeavySon,Top);
			son[u]=Max_HeavySon;
			for(int i=0;i<G[u].size();i++){
				int v=G[u][i];
				if(v==Max_HeavySon || v==fa[u]) continue;
				dfs2(v,v);
			}
		}
	}
	
	int getSum(int u,int v){
		int f1=top[u],f2=top[v],ret=0;
		while(f1!=f2){
			if(dep[f1]<dep[f2])
				swap(f1,f2),swap(u,v);
			ret+=st.getSum(hash[f1],hash[u],0);
			u=fa[f1];
			f1=top[u];
		}
		if(hash[u]>hash[v]) swap(u,v);
		ret+=st.getSum(hash[u],hash[v],0);
		return ret;
	}
	
	int getMax(int u,int v){
		int f1=top[u],f2=top[v],ret=-INF;
		while(f1!=f2){
			if(dep[f1]<dep[f2])
				swap(f1,f2),swap(u,v);
			ret=max(ret,st.getSum(hash[f1],hash[u],0));
			u=fa[f1];
			f1=top[u];
		}
		if(hash[u]>hash[v]) swap(u,v);
		ret=max(ret,st.getMaxv(hash[u],hash[v],0));
		return ret;	
	}
	
	void Change(int u,int k){			//Change u to k
		st.Change(hash[u],k,0);
	}
	
	void Make(int *x){
		st.Make(x,1,size[1],st.cnt++);
	}
}T; 

inline void Add(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

void init(){
	int u,v;
	#ifdef Judge
	SpeedUp;
	freopen("bzoj1036.in","r",stdin);
	freopen("bzoj1036.out","w",stdout);
	#endif	
	cin>>N;
	for(int i=1;i<N;i++){
		cin>>u>>v;
		Add(u,v);
	}
	for(int i=1;i<=N;i++){
		cin>>A[i];
	}
	T.dfs1(1,0,1);T.dfs2(1,1);
	for(int i=1;i<=N;i++){
		B[T.hash[i]]=A[i];
	}
	T.Make(B);
}

void work(){
	cin>>Q;
	string cmd;
	int a,b;
	while(Q--){
		cin>>cmd>>a>>b;
		switch (cmd[1]){
			case 'M':cout<<T.getMax(a,b)<<endl; break;
			case 'S':cout<<T.getSum(a,b)<<endl; break;
			case 'H':T.Change(a,b); break;
		}
	}
}

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;df
	#endif
	return 0;
}


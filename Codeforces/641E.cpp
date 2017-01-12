#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MAXN=1e5+3;
int N;

struct Order{
	int type,time,val,pos;
	void Read(int p){
		cin>>type>>time>>val;
		pos=p;
	}
}orderlist[MAXN];
bool cmpTime(Order X,Order Y){
	return X.time<Y.time;
}
bool cmpPos(Order X,Order Y){
	return X.pos<Y.pos;
}

struct SegTree{
	struct Node{
		int l,r;
		map<int,int>ins,rem;
	};
	Node node[MAXN<<2];
	void build(int root,int l,int r){
		node[root].l=l;
		node[root].r=r;
		if(l==r)	return;
		int mid=(l+r)>>1;
		build(root<<1,l,mid);
		build((root<<1)+1,mid+1,r);
	}
	void insert(int root,int time,int val){
		if(node[root].l==node[root].r && node[root].l==time){
			node[root].ins[val]++;
			return;
		}
		int mid=(node[root].l+node[root].r)>>1;
		if(time<=mid)	insert(root<<1,time,val);
		else	insert((root<<1)+1,time,val);
		node[root].ins[val]++;
	}
	void remove(int root,int time,int val){
		if(node[root].l==node[root].r && node[root].l==time){
			node[root].rem[val]++;
			return;
		}
		int mid=(node[root].l+node[root].r)>>1;
		if(time<=mid)	remove(root<<1,time,val);
		else 	remove((root<<1)+1,time,val);
		node[root].rem[val]++;
	}
	int queryIns(int root,int l,int r,int val){
		if(l<=node[root].l && r>=node[root].r)
			return node[root].ins[val];
		int mid=(node[root].l+node[root].r)>>1;
		if(r<=mid)	return queryIns(root<<1,l,r,val);
		if(l>mid)	return queryIns((root<<1)+1,l,r,val);
		return queryIns(root<<1,l,mid,val)+queryIns((root<<1)+1,mid+1,r,val);
	}
	int queryRem(int root,int l,int r,int val){
		if(l<=node[root].l && r>=node[root].r)
			return node[root].rem[val];
		int mid=(node[root].l+node[root].r)>>1;
		if(r<=mid)	return queryRem(root<<1,l,r,val);
		if(l>mid)	return queryRem((root<<1)+1,l,r,val);
		return queryRem(root<<1,l,mid,val)+queryRem((root<<1)+1,mid+1,r,val);
	}
};

SegTree T;

int main(){
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;i++)
		orderlist[i].Read(i);
	sort(orderlist+1,orderlist+N+1,cmpTime);
	for(int i=1;i<=N;i++)
		orderlist[i].time=i;
	sort(orderlist+1,orderlist+N+1,cmpPos);
	T.build(1,1,N);
	for(int i=1;i<=N;i++){
		switch(orderlist[i].type){
			case 1:T.insert(1,orderlist[i].time,orderlist[i].val);break;
			case 2:T.remove(1,orderlist[i].time,orderlist[i].val);break;
			case 3:cout<<T.queryIns(1,1,orderlist[i].time,orderlist[i].val)-T.queryRem(1,1,orderlist[i].time,orderlist[i].val)<<endl;break;
		}
	}
	return 0;
}

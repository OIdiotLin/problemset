#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 1000005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;
typedef long long LL;

struct SegTree{
	int L,R,mid;
	int Max;
}SegTree[MAXN*3];

int N,Q;

void Make(int l,int r,int num){
	SegTree[num].L=l;
	SegTree[num].R=r;
	SegTree[num].mid=(l+r)>>1;
	if(SegTree[num].L==SegTree[num].R){
		cin>>SegTree[num].Max;
		#ifdef Debug
		cout<<"Read "<<SegTree[num].L<<" : "<<SegTree[num].Max<<endl;
		#endif
		return;
	}
	Make(l,SegTree[num].mid,num<<1);
	Make(SegTree[num].mid+1,r,(num<<1)+1);
	SegTree[num].Max=max(SegTree[num<<1].Max,SegTree[(num<<1)+1].Max);
}

int Query(int l,int r,int num){
	#ifdef Debug
	cout<<"l="<<l<<"\tr="<<r<<endl;
	#endif
	if(SegTree[num].L==l && SegTree[num].R==r){
		return SegTree[num].Max;
	}
	if(r<=SegTree[num].mid){
		return Query(l,r,num<<1);
	}
	else if(l>SegTree[num].mid){
		return Query(l,r,(num<<1)+1);
	}
	else return max(Query(l,SegTree[num].mid,num<<1),Query(SegTree[num].mid+1,r,(num<<1)+1));
}

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("climb.in","r",stdin);
	freopen("climb.out","w",stdout);
	#endif
	cin>>N;
	Make(0,N,1);
	#ifdef Debug
	cout<<"Make END"<<endl;
	for(int i=1;i<3*N;i++){
		cout<<"Node "<<i<<" : "<<"L="<<SegTree[i].L<<"\tR="<<SegTree[i].R
			<<" \tMax="<<SegTree[i].Max<<endl;
	}
	for(int i=0;i<=N;i++){
		for(int j=i;j<=N;j++)
			cout<<"Max between "<<i<<" and "<<j<<" is "<<Query(i,j,1)<<endl;
	}
	#endif
}

void work(){
	int l,r;
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>l>>r;
		cout<<Query(l,r,1)<<endl;
	}
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(SegTree))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 15005
#define MAXL 32005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

struct SegNode{
	int L,R,mid;
	int V;
}SegTree[MAXL*3];

struct Point{
	int x,y;
	bool operator < (const Point &b)const{
		if(x==b.x) return y<b.y;
		return x<b.x;
	}
}A[MAXN];

int N;
int Ans[MAXN];

void Make(int l,int r,int num){
	SegTree[num].L=l;
	SegTree[num].R=r;
	SegTree[num].mid=((l+r)>>1);
	SegTree[num].V=0;
	if(l!=r){
		Make(l,SegTree[num].mid,num<<1);
		Make(SegTree[num].mid+1,r,(num<<1)+1);
	}
}

void Ins(int l,int r,int num){
	if(SegTree[num].L==l && SegTree[num].R==r){
		SegTree[num].V++;
		return;
	}
	if(SegTree[num].L==SegTree[num].R) return;
	if(r<=SegTree[num].mid){
		Ins(l,SegTree[num].mid,num<<1);
	}
	else if(l>SegTree[num].mid){
		Ins(SegTree[num].mid,r,(num<<1)+1);
	}
	else{
		Ins(l,SegTree[num].mid,num<<1);
		Ins(SegTree[num].mid+1,r,(num<<1)+1);
	}
}

int Calc(int x,int num){
	if(SegTree[num].L==SegTree[num].R){
		return SegTree[num].V;
	}
	int ret=SegTree[num].V;
	if(x<=SegTree[num].mid) ret+=Calc(x,num<<1);
	else ret+=Calc(x,(num<<1)+1);
	return ret;
}

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("1066.in","r",stdin);
//	freopen("1066.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i].x>>A[i].y;
		Ans[i]=0;
	}
	sort(A+1,A+N+1);
	Make(1,MAXL,1);
	#ifdef Debug
	for(int i=1;i<=N;i++)
		cout<<"x="<<A[i].x<<"\ty="<<A[i].y<<endl;
	#endif
}

void work(){
	for(int i=1;i<=N;i++){
		Ans[Calc(A[i].y,1)]++;
		Ins(A[i].y,MAXL,1);
	}
	for(int i=0;i<N;i++){
		cout<<Ans[i]<<endl;
	}
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(SegTree)+sizeof(A))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


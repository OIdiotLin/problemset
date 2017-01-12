#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 100005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;
typedef long long LL;

struct SegNode{
	int L,R,mid;
	int V;
}SegTree[MAXN*3];

void Make(int l,int r,int num){
	SegTree[num].L=l;
	SegTree[num].R=r;
	SegTree[num].mid=(l+r)>>1;
	if(l==r){
		cin>>SegTree[num].V;
		#ifdef Debug
		cout<<"Read : "<<SegTree[num].V<<endl;
		#endif
		return;
	}
	Make(l,SegTree[num].mid,num<<1);
	Make(SegTree[num].mid+1,r,(num<<1)+1);
	SegTree[num].V=SegTree[num<<1].V+SegTree[(num<<1)+1].V;
}

void Add(int k,int c,int num){
	if(SegTree[num].L==SegTree[num].R){
		SegTree[num].V+=k;
		return;
	}
	if(k<=SegTree[num].mid){
		Add(k,c,num<<1);
	}
	else if(k>SegTree[num].mid){
		Add(k,c,num<<1|1);
	}
}

int Sum(int r1,int r2,int L,int R,int num){
	if(SegTree[num].L==L && SegTree[num].R==R){
		return SegTree[num].V;
	}
	if(R<=SegTree[num].mid){
		return Sum(r1,r2,L,R,num<<1);
	}
	if(L>SegTree[num].mid){
		return Sum(r1,r2,L,R,num<<1|1);
	}
	return Sum(r1,r2,L,R,num<<1)+Sum(r1,r2,L,R,(num<<1)+1);
}

int N,Q;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("shulie.in","r",stdin);
//	freopen("shulie.out","w",stdout);
	#endif
	cin>>N;
	Make(1,N,1);
	#ifdef Debug
	cout<<"SegTree Built END"<<endl;
	#endif
	cin>>Q;
}

void work(){
	int r1,r2;
	string O;
	while(Q--){
		cin>>O>>r1>>r2;
		if(O=="SUM"){
			cout<<Sum(r1,r2,1,N,1)<<endl;
		}
		else{
			Add(r1,r2,1);
		}
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


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;
const int SIZEN=32767+10,INF=0x7fffffff;
class NODE{
public:
	int data;
	int last,next;
	int opos;//原先位置
	void assign(int x,int y){data=x,opos=y;}
	NODE(){last=next=0;}
};
bool operator < (NODE a,NODE b){return a.data<b.data;}
NODE btlis[SIZEN];//双向链表
void dirnext(int a,int b){btlis[a].next=b;}
void dirlast(int a,int b){btlis[a].last=b;}
void lisdel(int x){//删除元素
	dirnext(btlis[x].last,btlis[x].next);
	dirlast(btlis[x].next,btlis[x].last);
}
int minflu(int x){
	int l=abs(btlis[x].data-btlis[btlis[x].last].data);
	int r=abs(btlis[x].data-btlis[btlis[x].next].data);
	return min(l,r);
}
int a[SIZEN]={0},b[SIZEN]={0};
int N;
//0是哨兵
int ans=0;
void work(void){
	int x;
	for(int i=N;i>=2;i--){
		x=b[i];
		ans+=minflu(x);
		lisdel(x);
	}
	ans+=a[1];
	printf("%d\n",ans);
}
void makelist(void){
	for(int i=1;i<=N;i++) btlis[i].assign(a[i],i);
	sort(btlis+1,btlis+1+N);
	for(int i=1;i<=N;i++) b[btlis[i].opos]=i;
	for(int i=1;i<N;i++) dirnext(i,i+1);
	for(int i=2;i<=N;i++) dirlast(i,i-1);
	btlis[0].data=INF;
}
void read(void){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
	a[0]=a[1],a[N+1]=INF;
}
int main(){
	freopen("turnover.in","r",stdin);
	freopen("turnover.out","w",stdout);
	read();
	makelist();
	work();
	return 0;
}

/*
	Machine: lenovo E440
	System: Ubuntu Kylin 14.04
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
#define MAXN (2003)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

const int DirX[]={1,0,-1,0};
const int DirY[]={0,1,0,-1};
const char Ou1[]={'^','<','v','>'};
const char Ou2[]={'v','>','^','<'};

int N,M;

struct Node{
	int x,y;
	Node(int _x=0,int _y=0):
		x(_x),y(_y){}
	Node next(int k){
		return Node(x+DirX[k],y+DirY[k]);
	}
	bool InRange(){
		return x>=0 && x<N && y>=0 && y<M;
	}
};
char G[MAXN][MAXN];
int d[MAXN][MAXN];
queue<Node> Q;

int CalcDegree(Node p){
	if(G[p.x][p.y]=='*')	return 0;
	int res=0;
	for(int i=0;i<4;i++){
		Node np=p.next(i);
		res+=(np.InRange() && G[np.x][np.y]!='*');
	}
	return res;
}

void init(){
#ifdef Judge
	FILE *fin=freopen("D.in","r",stdin);
	FILE *fou=freopen("D.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	for(int i=0;i<N;i++)
		scanf("%s",G[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			Node cur=Node(i,j);
			d[i][j]=CalcDegree(cur);
			if(d[i][j]==1)	Q.push(cur);
		}
}

void work(){
	while(!Q.empty()){
		Node cur=Q.front();
		Q.pop();
		d[cur.x][cur.y]=0;
		for(int k=0;k<4;k++){
			Node np=cur.next(k);
			if(np.InRange() && d[np.x][np.y]){
				d[np.x][np.y]=0;
				G[cur.x][cur.y]=Ou1[k];
				G[np.x][np.y]=Ou2[k];
				for(int k=0;k<4;k++){
					Node nnp=np.next(k);
					if(nnp.InRange() && d[nnp.x][nnp.y])
						if(--d[nnp.x][nnp.y]==1)
							Q.push(nnp);
				}
				break;
			}
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(G[i][j]=='.'){
				puts("Not unique");
				return;
			}
	for(int i=0;i<N;i++)
		puts(G[i]);
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

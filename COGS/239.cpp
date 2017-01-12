#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#define MAXN 301
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

const int X[]={0,0,0,-1,1};
const int Y[]={0,1,-1,0,0};

struct Point{
	int x,y;
}Heap[MAXN*MAXN];

int N,M,Ans;
bool Fill[MAXN][MAXN];
int HeapN;
int G[MAXN][MAXN];

void Ins(int x,int y){
	int i;
	for(i=++HeapN;G[x][y]<G[Heap[i>>1].x][Heap[i>>1].y];i>>=1)
		Heap[i]=Heap[i>>1];
	Heap[i]=(Point){x,y};
}

Point PopMin(){							//Delete and return the min.
	Point p=Heap[1],M=Heap[HeapN--];
	int i,cnt;
	for(i=1;(i<<1)<=HeapN;i=cnt){
		cnt=(i<<1);
		if(cnt!=HeapN && G[Heap[cnt+1].x][Heap[cnt+1].y]<G[Heap[cnt].x][Heap[cnt].y])
			cnt++;
		if(G[M.x][M.y]>G[Heap[cnt].x][Heap[cnt].y])
			Heap[i]=Heap[cnt];
		else break;
	}
	Heap[i]=M;
	return p;
}

inline bool check(Point A){
	return (A.x>=1 && A.y>=1 && A.x<=N && A.y<=M);
}

void FloodFill(Point A,int H){			//On Floor H, FloodFill the Point A;
	Point B;						//B is in the neighborhood of A,where the water could spread. 
	Fill[A.x][A.y]=true;
	if(G[A.x][A.y]>=H){				//Maintain the height. 
		Ins(A.x,A.y);
		return;
	}
	Ans+=H-G[A.x][A.y];
	for(int i=1;i<=4;i++){
		B=(Point){A.x+X[i],A.y+Y[i]};
		if(check(B) && !Fill[B.x][B.y])	//recursive filling 
			FloodFill(B,H);
	}
}

void init(){
	
	#ifdef FILE
	SpeedUp;
	freopen("wod.in","r",stdin);
	freopen("wod.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>G[i][j];
	G[0][0]=-INF;
	Heap[HeapN=0]=(Point){0,0};
}

void work(){
	Point A,B;
	for(int i=1;i<=N;i++){			//Boundary initialization
		Ins(i,1);
		Ins(i,M);
		Fill[i][1]=Fill[i][M]=true;
	}
	for(int i=2;i<M;i++){
		Ins(1,i);
		Ins(N,i);
		Fill[1][i]=Fill[N][i]=true;
	}
	while(HeapN){
		A=PopMin();
		for(int i=1;i<=4;i++){
			B=(Point){A.x+X[i],A.y+Y[i]};
			if(check(B) && !Fill[B.x][B.y])
				FloodFill(B,G[A.x][A.y]);
		}
	}
	cout<<Ans<<endl;
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


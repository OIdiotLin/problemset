#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN 301
#define MAXM 50003
#define INF (1<<30)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;
typedef long long LL;

const int X[]={0,0,-1,1,0};
const int Y[]={-1,1,0,0,0};
struct Point{
	int x,y;
	int t;
	void read(){
		cin>>x>>y>>t;
	}
	bool operator < (const Point &b)const{
		return t<=b.t;
	}
}Star[MAXM];
bool vis[MAXN+1][MAXN+1],des[MAXN+1][MAXN+1],G[MAXN+1][MAXN+1];
int M,cnt;

inline bool Inrange(int x,int y){
	return (x>=0&&y>=0&&x<=MAXN&&y<=MAXN);
}
void init()
{
	cnt=0;
	int tx,ty;
	#ifdef FILE
	SpeedUp;
	freopen("meteor.in","r",stdin);
	freopen("meteor.out","w",stdout);
	#endif
	memset(vis,true,sizeof(vis));
	cin>>M;
	for(int i=0;i<M;i++){
		Star[i].read();
		for(int j=0;j<=4;j++){
			tx=Star[i].x+X[j];
			ty=Star[i].y+Y[j];
			if(Inrange(tx,ty))
				G[tx][ty]=true;
		}
	}
	if(G[0][0]==false){
		cout<<0<<endl;
		exit(0);
	}
	sort(Star,Star+M);
	Star[M].t=INF;
	#ifdef Debug
	for(int i=0;i<=M;i++){
		cout<<Star[i].x<<" "<<Star[i].y<<" "<<Star[i].t<<endl;
	}
	#endif
	while(!Star[cnt].t){			//如果有初始就毁灭的点 
		#ifdef Debug
		cout<<"Init S"<<endl;
		#endif
		for(int i=0;i<=4;i++){
			tx=Star[cnt].x+X[i];
			ty=Star[cnt].y+Y[i];
			if(Inrange(tx,ty))
				des[tx][ty]=true;
		}
		cnt++;
	}
	/*
	#ifdef Debug
	cout<<"des:"<<endl;
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++)
			cout<<des[i][j];
		cout<<endl;
	}
	#endif
	*/
	if(des[0][0]){
		cout<<-1<<endl;
		exit(0);
	}
}

int Qx[MAXN*MAXN]={0},Qy[MAXN*MAXN]={0},Qt[MAXN*MAXN]={0};
void work2(){
	int tx,ty;
	int tail=0,head=0;
	while(tail<=head){
		while(Qt[tail]+1==Star[cnt].t){
			for(int i=0;i<=4;i++){
				tx=Star[cnt].x+X[i];
				ty=Star[cnt].y+Y[i];
				if(Inrange(tx,ty))
					des[tx][ty]=true;
			}
			cnt++;
		}
		for(int i=0;i<4;i++){
			tx=Star[cnt].x+X[i];
			ty=Star[cnt].y+Y[i];
			if(Inrange(tx,ty) && !des[tx][ty] && !vis[tx][ty]){
				head++;
				Qx[head]=tx,Qy[head]=ty;
				Qt[head]=Qt[tail]+1;
				vis[tx][ty]=true;
				if(!G[tx][ty]){
					cout<<Qt[head]<<endl;
					return;
				}
			}
		}
		tail++;
	}
	cout<<"-1"<<endl;
}

queue<Point> Q;
void work(){
	int tx,ty;
	int LHD=0;
	Q.push((Point){0,0,0});
	while(1){
		LHD++;
		while(Q.front().t+1==Star[cnt].t){
			for(int i=0;i<=4;i++){			//FloodFill *4 
				tx=Star[cnt].x+X[i];
				ty=Star[cnt].y+Y[i];
				if(Inrange(tx,ty))
					des[tx][ty]=true;
			}
			cnt++;
		}
		for(int i=0;i<4;i++){
			tx=Q.front().x+X[i];
			ty=Q.front().y+Y[i];
			if(Inrange(tx,ty) && !des[tx][ty] && !vis[tx][ty]){
				Point t=(Point){tx,ty,Q.front().t+1};			//Time Limit
				Q.push(t);
				#ifdef Debug
				cout<<"Push: "<<t.x<<" "<<t.y<<" "<<t.t<<endl;
				#endif
				vis[tx][ty]=true;
				if(!G[tx][ty]){
					cout<<Q.back().t<<endl;
					return;
				}
			}
		}
		Q.pop();
		if(Q.empty()){
			#ifdef Debug
			cout<<"End at "<<LHD<<endl;
			#endif
			break;
		}
	}
	#ifdef Debug
	cout<<"Q "<<LHD<<endl;
	#endif
	cout<<-1<<endl;
}


int main()
{
	init();
	work2();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(G)*3+sizeof(Q)+sizeof(Star))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


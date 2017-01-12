/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (105)
#define MAXM (100005)
#define INF (1<<28)
const double PI=acos(-1);
const int ZCY=1000000007;

const int DirX[]={0,1,0,-1};
const int DirY[]={1,0,-1,0};

inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

const int Lim_Step	=	1000000;
const int Max_Num	=	100000;
const int Min_Num	=	-100000;
int N;
int Input[MAXM];

struct Befunge{
	int H,W;
	string Code[MAXN];
	int Reg[30];
	int cur,curNum,cntStep,dir;
	
	struct Pointer{
		int x,y;
		void Init(){
			x=y=0;
		}
		void Move(int k){
			x+=DirX[k],y+=DirY[k];
		}
	}ptr;
	
	bool chk_ptr(){
			return 0<=ptr.x&&ptr.x<H && 0<=ptr.y&&ptr.y<W;
	}
	void Init(){
		cur=dir=curNum=cntStep=0;
		ptr.Init();
		memset(Reg,0,sizeof(Reg));
	}
	Befunge(int _H=0,int _W=0):H(_H),W(_W){Init();}
	
	inline bool chk_run(){
		if(cur>Max_Num || cur<Min_Num){
			cout<<"OVERFLOW ERROR"<<endl;
			return false;
		}
		if(++cntStep>=Lim_Step){
			cout<<"TIME LIMIT EXCEEDED"<<endl;
			return false;
		}
		ptr.Move(dir);
		if(!chk_ptr()){
			cout<<"RUNTIME ERROR"<<endl;
			return false;
		}
		if(curNum>=N) curNum=N-1;
		return true;
	}

	void Run(){
		while(true){
			char CMD=Code[ptr.x][ptr.y];
			switch(CMD){
				case '>':dir=0;	break;
				case 'v':dir=1;	break;
				case '<':dir=2;	break;
				case '^':dir=3;	break;
				case '+':cur++;	break;
				case '-':cur--;	break;
				case '.':break;
				case '?':cur=Input[curNum++];	break;
				case '!':cout<<cur<<endl;	cur=0;	break;
				case '@':dir=(cur ? (dir+1)%4 : (dir+3)%4);	break;
				case '#':return;
				default	:	if(isupper(CMD)) swap(cur,Reg[CMD-'A']);
							else {cout<<"Error Code"<<endl; return;}
			}
			if(!chk_run()) return;
		}
	}
	
	void Read(){
		for(int i=0;i<H;i++)
			cin>>Code[i];
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>Input[i];
	}
	
}Prog;

void init(){
	int H,W;
	SpeedUp;
#ifdef Judge
	freopen("2027.in","r",stdin);
	freopen("2027.out","w",stdout);
#endif
	cin>>H>>W;
	Prog=Befunge(H,W);
	Prog.Read();
}

void work(){
	Prog.Run();
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

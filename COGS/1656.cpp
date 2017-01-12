#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

int N;
struct Point{
	int x,y;
	LL operator *(Point B)const {		//叉积的数值 
		return x*B.y-B.x*y;
	}
	Point operator -(Point B)const {	//终点-始点=向量 
		return (Point){x-B.x,y-B.y};
	}
};
typedef Point Vector;

bool SameSide(Vector e,Vector o,Vector a){
	return ((e*o)*(e*a)>0);
}

bool Judge(Point A,Point B,Point C)
{
	Point O=(Point){0,0};
	Vector AO=O-A,BO=O-B,CO=O-C;
	Vector AB=B-A,CA=A-C,BC=C-B; 
	Vector BA=A-B,AC=C-A,CB=B-C;
	if(SameSide(AB,AO,AC)&&SameSide(BC,BO,BA)&&SameSide(CA,CO,CB))
		return true;
	return false;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("trioxorz.in","r",stdin);
	freopen("trioxorz.out","w",stdout);
	#endif
}

void work(){
	Point A,B,C;
	int cnt=0;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
		if(Judge(A,B,C)){
			#ifdef Debug
			cout<<"("<<A.x<<","<<A.y<<") ("<<B.x<<","<<B.y<<") ("<<C.x<<","<<C.y<<")"<<endl;
			#endif
			cnt++;
		}
	}
	cout<<cnt<<endl;
}

int main()
{
	init();
	work();
//	cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
	return 0;
}


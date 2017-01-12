#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 10010
#define INF (1e12)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

int L[4],C[4];	//Length & Price
int N,A,B;		//Number of stations, StartPoint, destination
LL Dist[MAXN],f[MAXN],d[3][MAXN];
LL t;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("rail.in","r",stdin);
	freopen("rail.out","w",stdout);
	#endif
	cin>>L[1]>>L[2]>>L[3]>>C[1]>>C[2]>>C[3];
	cin>>N>>A>>B;
	if(A>B) swap(A,B);
	A--,B--;	//WHAT THE FUCKING ORDER!!!!!!
	d[0][A]=d[1][A]=d[2][A]=A;
	for(int i=1;i<=N;i++)
		cin>>Dist[i];
	f[0]=INF;f[A]=0;
}

void Buy(int i,int o){
	t=-1;
	if(Dist[i-1]+L[o] >= Dist[i]){
		t=d[o-1][i-1];
		while(Dist[i]-Dist[t]>L[o])	//Find the Longest Length.
			t++;
	}
	if(i>t)		//The longest length can't reach Station i.
		d[o-1][i]=t;
}

void Refresh(int i,int o){
	if(d[o-1][i]!=-1 && (f[i]>f[d[o-1][i]]+C[o] || !f[i]))
		f[i]=f[d[o-1][i]]+C[o];
}

void Dp()
{
	for(int i=A+1;i<=B;i++){
		#ifdef Debug
		cout<<"Dist["<<i<<"] = "<<Dist[i]<<endl;
		#endif
		Buy(i,1);
		Buy(i,2);
		Buy(i,3);
	}
	for(int i=A+1;i<=B;i++){
		f[i]=INF;
		Refresh(i,1);
		Refresh(i,2);
		Refresh(i,3);
		#ifdef Debug
		cout<<"The Status on "<<i<<" is "<<f[i]<<endl;
		#endif
	}
}

int main()
{
	init();
	Dp();
	cout<<f[B]<<endl;
	return 0;
}

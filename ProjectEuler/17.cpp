#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 1010
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
//#define Debug
using namespace std;

int H[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	H[0]=0;
	H[1]=3,H[2]=3,H[3]=5,H[4]=4,H[5]=4,H[6]=3,H[7]=5,H[8]=5,H[9]=4,H[10]=3;
	H[11]=6,H[12]=6,H[13]=8,H[14]=8,H[15]=7,H[16]=7,H[17]=9,H[18]=8,H[19]=8;
	H[20]=6,H[30]=6,H[40]=5,H[50]=5,H[60]=5,H[70]=7,H[80]=6,H[90]=6;
		/*twenty,thirty,forty,fifty,sixty,seventy,eighty,ninety*/
	for(int i=100;i<=900;i+=100) H[i]=H[i/100]+7;
}

int Calc(int x){
	int ret=0,r1,r2,r3;
	r1=x/100;
	r2=(x-r1*100)/10;
	r3=x%10;
	if(r1 && (r2 || r3)) ret+=3;
	if(r2==1)ret+=H[r1*100]+H[r2*10+r3];
	if(r2!=1)ret+=H[r1*100]+H[r2*10]+H[r3];
	#ifdef Debug
	cout<<r1<<r2<<r3<<"\t";
	cout<<ret<<endl;
	#endif
	return ret;
}

void work()
{
	int Sum=0;
	for(int i=1;i<=999;i++){
		Sum+=Calc(i);
	}
	Sum+=11;
	cout<<Sum<<endl;
}
int main()
{
	init();
	work();
	#ifdef Debug
	while(1){
		int N;
		cin>>N;
		cout<<Calc(N)<<endl;
	}
	#endif
	return 0;
}


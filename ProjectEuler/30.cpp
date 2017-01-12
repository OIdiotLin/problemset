#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

typedef long long LL;

int Pow(int x,int r){
	if(r==0)	return 1;
	return (int)pow(x,r);
}
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

bool Judge(LL x)
{
	int Digit[12];
	int Len;
	for(int i=1;;i++){
		if(x/Pow(10,i-1)>0)
			Len=i;
		else break;
	}
	LL t=0;
	for(int i=1;i<=Len;i++){
		Digit[i]=(x%Pow(10,i)-t)/Pow(10,i-1);
		t+=Digit[i]*Pow(10,i-1);
	}
	LL S=0;
	for(int i=1;i<=Len;i++){
		S+=Pow(Digit[i],5);
	}
	return S==x;
}

int main()
{
	LL S=0;
	for(int i=2;i<=1000000;i++){
		if(Judge(i))
		{S+=i;cout<<i<<"\t S = "<<S<<endl;}
	}
	cout<<S<<endl;
	return 0;
}


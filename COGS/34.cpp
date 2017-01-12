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

const int Fa[]={1,1,2,6,24,120,720,5040,40320,362880};
inline int Pow(int x,int r){
	if(r==0)	return 1;
	return (int)pow(x,r);
}

int f(int x){
	return Fa[x];
}

bool Judge(LL x){
	int Digit[20];
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
		S+=f(Digit[i]);
	}
	return S==x;
}

int main()
{
	LL S=0;
	for(LL i=3;i<=1000000;i++){
		if(Judge(i)){
			S+=i;
			cout<<i<<"\t S = "<<S<<endl;	
		}
		if(i%500000==0)cout<<i<<endl;
	}
	cout<<S<<endl;
	return 0;
}


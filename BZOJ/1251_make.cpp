#include <cstdio>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;

inline double Rand(){
	return (double)rand()/RAND_MAX;
}
inline int Rand(int lim){
	return Rand()*(lim+1);
}
inline int Rand(int l,int r){
	return Rand(r-l)+l;
}

int main(){
	srand(time(NULL));
	freopen("1251.in","w",stdout);
	int N=Rand(2000)+1000;
	int M=Rand(100)+100;
	cout<<N<<" "<<M<<endl;
	while(M--){
		int CMD=(rand()%3)+1;
		int l=Rand(2,N-5),r=Rand(3,N-4);
		if(l>r) swap(l,r);
		int v=Rand(-50,100);
		printf("%d %d %d",CMD,l,r);
		if(CMD==1) printf(" %d",v);
		printf("\n");
	}
}
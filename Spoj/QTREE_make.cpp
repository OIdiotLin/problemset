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

inline int Rand(int lim){
	return rand()%lim+1;
}
inline int Rand(int l,int r){
	return l+Rand(r-l);
}

void init(){
	srand(time(NULL));
	freopen(".in","w",stdout);
	int N=Rand(1000,2000);
	for(int i=1;i<N;i++){
		
}

int main(){
	init();
	return 0;
}
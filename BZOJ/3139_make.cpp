#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

inline int Rand(int l,int r){
	return l+((double)rand()/RAND_MAX)*(r-l);
}

int main(){
	srand(time(NULL));
	while(rand()%5!=0);
	freopen("3139.in","w",stdout);
	int N=Rand(1,10);
	cout<<N<<endl;
	for(int i=1;i<=N;i++)
		cout<<Rand(2,12)<<" ";
	cout<<endl;
}
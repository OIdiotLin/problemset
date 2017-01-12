#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;

inline char Rand(char l,char r){
	return l+rand()%(r-l);
}

int main(){
	srand(time(NULL));
	rand();
	freopen("3676.in","w",stdout);
	int len=10+(double)rand()/RAND_MAX*10;
	while(len--){
		putchar(Rand('a','d'));
	}
	puts("");
	return 0;
}
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
#define Debug
using namespace std;
typedef long long LL;

string K,C;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("vignere.in","r",stdin);
	freopen("vignere.out","w",stdout);
	#endif
	cin>>K;
	cin>>C;
	#ifdef Debug
	cout<<endl<<"The Key is : "<<K<<endl;
	cout<<"The Code is : "<<C<<endl<<endl;
	#endif
}

char Change(char Key,char Code){
	if(islower(Code))Key=tolower(Key);
	else Key=toupper(Key);
	if(Key==Code){
		return 'a';
	}
	if(Key>Code){
		return 'Z'-Key-Code+1;
	}
}

string Trans(string Key,string Code){
	string ret;
	for(int i=0;i<Code.length();i++){
		char c=Code[i],k=Key[i%Key.length()];
		ret=ret+Change(k,c);
	}
	return ret;
}

int main()
{
	init();
	cout<<Trans(K,C)<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(K)+sizeof(C))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


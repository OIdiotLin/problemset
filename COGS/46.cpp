/*
	System: Windows7 32bit
	Machine: Class4_B2
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <string>
#define MAXN ()
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

string S;
char CMD,a1,a2;

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	#endif
	getline(cin,S);
	cin>>CMD>>a1;
	if(CMD!='D') cin>>a2;
}

void Delete(){
	int p=S.find(a1);
	S.erase(p,1);
	cout<<S<<endl;
}
void Insert(){
	int p=S.find_last_of(a1);
	string t=S.substr(p);
	S.erase(p);
	S=S+a2+t;
	cout<<S<<endl;
}
void Replace(){
	int Len=S.length(),k=0;
	for(int i=0;i<Len;i++){
		if(S[i]==a1){
			k=1;
			S[i]=a2;
		}
	}
	if(k==0) cout<<"error"<<endl;
	else cout<<S<<endl;
}

void work(){
	switch(CMD){
		case 'D':Delete();break;
		case 'I':Insert();break;
		case 'R':Replace();break;
	}
}

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


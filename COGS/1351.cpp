#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 2002
#define MOD 19971212
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

struct Lrc{
	int Time;
	string S;
	void Out(){
		cout<<Time<<" seconds : "<<S<<endl;
	}
	bool operator < (Lrc x)const {
		if(Time<x.Time) return true;
		if(Time>x.Time) return false;
		if(S.length()<x.S.length()) return true;
		if(S.length()>x.S.length()) return false;
		if(S<x.S) return true;
		if(S>x.S) return false;
	}
}A[MAXN];

inline int C(char c){
	return (int)(c-'0');
}

int N;

void init()
{
	string s;
	SpeedUp;
	#ifdef FILE
	freopen("lyric.in","r",stdin);
	freopen("lyric.out","w",stdout);
	#endif
	N=0;
	while(getline(cin,s,'\n')){
		if(s[1]=='n'){
			cout<<"        ";
			for(int i=6;i<s.length();i++)
				cout<<s[i];
			cout<<endl;
			continue;
		}
		A[++N].Time=C(s[1])*10*60+C(s[2])*60+C(s[4])*10+C(s[5]);
		for(int i=7;i<s.length();i++)
			A[N].S+=s[i];
	}
}

void work(){
	sort(A+1,A+N+1);
	#ifdef Debug
	cout<<"After Sort"<<endl;
	for(int i=1;i<=N;i++){
		A[i].Out();
	}
	#endif
	for(int i=1;i<=N;i++){
		cout<<A[i].S<<endl;
	}
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(A))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


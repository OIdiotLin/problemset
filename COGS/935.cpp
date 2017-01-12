#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 10005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

struct Apl{
	int Time,Last;
	string Name;
	bool operator < (Apl b)const {
		if(Time < b.Time) return true;
		if(Name < b.Name) return true;
		return false;
	}
}Data[MAXN];

int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("hey.in","r",stdin);
	freopen("hey.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>Data[i].Time>>Data[i].Name>>Data[i].Last;
	}
	sort(Data+1,Data+N+1);
}

void work(){
	int cnt=Data[i].Time;
	for(int i=1;i<=N;i++){
		cout<<Data[i].Name<<" went out at time ";
		if(cnt<=Data[i].Last)
		
	}
}

int main()
{
	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


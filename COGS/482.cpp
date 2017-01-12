#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#define MAXN 51
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

struct Team{
	int Year;
	char Name[MAXN];
};

bool cmp(Team a,Team b){
	return a.Year>b.Year;
}

int N;
Team T[MAXN];

void init()
{
	//SpeedUp;
	#ifdef FILE
	freopen("nba.in","r",stdin);
	freopen("nba.out","w",stdout);
	#endif
	scanf("%d\n",&N);
	for(int i=1;i<=N;i++)
	{
		/*
		string Data;
		getline(cin,Data);
		#ifdef Debug
		cout<<"Data #"<<i<<": "<<Data<<endl;
		#endif
		int cn=0,cy=0;
		char Y[MAXN];
		for(int j=0;j<Data.length();j++)
		{
			if(isalpha(Data[j]) || Data[j]==' ')
			{
				#ifdef Debug
				cout<<Data[j]<<endl;
				#endif
				T[i].Name[cn++]=Data[j];
			}
			if(isdigit(Data[j]))
				Y[cy++]=Data[j];
		}
		T[i].Year=atoi(Y);*/
		scanf("%[^0-9]%d\n",&T[i].Name,&T[i].Year);
	}
	/*
	#ifdef Debug
	cout<<"Reading END"<<endl;
	for(int i=1;i<=N;i++)
	{
		cout<<"T["<<i<<"]: "<<T[i].Name<<"\t"<<T[i].Year<<endl;
	}
	#endif
	*/
	sort(T+1,T+N+1,cmp);
}

void work()
{
	for(int i=N;i>=1;i--)
	{
		if(i==1 || T[i].Year!=T[i-1].Year)
			cout<<T[i].Year<<" "<<T[i].Name<<endl;
	}
}

int main()
{
	init();
	work();
	return 0;
}


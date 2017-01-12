#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 55
#define MAX true
#define MIN false
#define INF 1<<16
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int N,M;
int Max,Min;
int f[MAXN];
int Last[MAXN][MAXN],Now[MAXN][MAXN];

inline int total(int i,int j){
	return (i<=j) ? (f[j]-f[i-1]) : (f[N]-f[i-1]+f[j]);
}

void init()
{
	int r;
	SpeedUp;
	#ifdef FILE
	freopen("numgame.in","r",stdin);
	freopen("numgame.out","w",stdout);
	#endif
	cin>>N>>M;
	memset(f,0,sizeof(f));
	for(int i=1;i<=N;i++)
	{
		cin>>r;
		f[i]=f[i-1]+r;
	}
}

int Dp(bool LHD,int &Ans)
{
	Ans=((LHD) ? 0 : INF);			
	int dis,t1,t2,extre;
	dis=(LHD ? -1 : INF);
	#ifdef Debug
	cout<<"dis = "<<dis<<endl
		<<"Ans = "<<Ans<<endl;
	#endif
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			Last[i][j]=((i==j) ? 1 : dis);
		}
	
	#ifdef Debug
	cout<<"Last init:"<<endl;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			cout<<Last[i][j]<<"\t";
		cout<<endl;
	}
	#endif
	for(int L=1;L<=M-1;L++)
	{
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				Now[i][j]=dis;
		for(int i=1;i<=N;i++)
			for(int j=i+L-1;j<=N+i-1;j++)
			{
				t1=(j-1)%N+1;
				for(int k=i+L-1;k<=j;k++)
				{
					t2=(k-1)%N+1;
					if(Last[i][t2]==-1 || Last[i][t2]==INF)
						continue;
					extre=total(t2,t1);
					extre=Last[i][t2]*((10+extre%10)%10);
					#ifdef Debug
					cout<<"-----Extre is "<<extre<<endl;
					#endif
					if(!LHD)
						if(extre<Now[i][t1])
							Now[i][t1]=extre;
					if(LHD)
						if(extre>Now[i][t1])
							Now[i][t1]=extre;
				}
			}
		#ifdef Debug
		cout<<"Last:"<<endl;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++)
				cout<<Last[i][j]<<"\t";
			cout<<endl;
		}
		cout<<"Now:"<<endl;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++)
				cout<<Now[i][j]<<"\t";
			cout<<endl;
		}
		#endif
		memcpy(Last,Now,N);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				Last[i][j]=Now[i][j];
		#ifdef Debug
		cout<<"Last = Now = :"<<endl;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++)
				cout<<Last[i][j]<<"\t";
			cout<<endl;
		}
		#endif
	}
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(i!=j && Now[i][j]!=INF && Now[i][j]!=-1)
			{
				extre=total(j%N+1,(i+N-2)%N+1);
				extre=Now[i][j]*((10+extre%10)%10);
				if(LHD)
					if(extre>Ans)
						Ans=extre;
				if(!LHD)
					if(extre<Ans)
						Ans=extre;
			}
	return Ans;
}

void work()
{
	int Ans;
	#ifdef Debug
	cout<<"Min Dp:"<<endl;
	#endif
	cout<<Dp(MIN,Ans)<<endl;
	
	//Min=Ans;
	#ifdef Debug
	cout<<"--------------------"<<endl
		<<"Max Dp:"<<endl;
	#endif
	cout<<Dp(MAX,Ans)<<endl;
	//Max=Ans;
}

int main()
{
	init();
	work();
	return 0;
}


#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#define MAXN 10010
#define INF 10000
#define SpeedUp ios::sync_with_stdio(false)
//#define Debug
//#define FILE
using namespace std;

int zero;
int Original_N,cnt;
int Divided[MAXN],Ans[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("maxmul.in","r",stdin);
	freopen("maxmul.out","w",stdout);
	#endif
	cnt=0;
	cin>>Original_N;
	for(int i=0;i<Original_N;i++)
		Ans[i]=1;
	for(int i=2;i<Original_N;i++,cnt++)
	{
		Divided[cnt]=i;
		Original_N-=i;
	}
	if(Original_N==Divided[cnt-1])
	{
		for(int i=0;i<cnt;i++)
			Divided[cnt]++;
		Divided[cnt-1]++;
	}
	else
		for(int i=cnt-1,j=0;j<Original_N;i--,j++)
			Divided[i]++;
}

void work()
{
	#ifdef Debug
	cout<<"Mul :"<<endl;
	#endif
	for(int i=0;i<cnt;i++)
	{
		#ifdef Debug
		cout<<"Round #"<<i<<endl;
		#endif
		for(int j=0;j<Original_N;j++)
		{
			if(Ans[j]!=0)
				Ans[j]*=Divided[i];
			#ifdef Debug
			cout<<"\tj = "<<j
				<<"\tAns["<<j<<"]\t"<<Ans[j]<<endl;
			#endif
		}
		for(int j=0;j<Original_N;j++)
		{
			if(Ans[j]!=0)
				while(Ans[j]>=INF)
				{
					int t=Ans[j]/INF;
					Ans[j+1]+=t;
					Ans[j]%=INF;
				}
		}
	}
	for(int i=Original_N-1;i>=0;i--)
	{
		if(Ans[i]!=0)
		{
			zero=i;
			break;
		}
	}
}

void Output()
{
	for(int i=0;i<cnt;i++)
		cout<<Divided[i]<<" ";
	cout<<endl;
	cout<<Ans[zero];
	#ifdef Debug
	cout<<"Array Ans = "<<endl<<"\t";
	for(int i=Original_N;i>=0;i--)
		cout<<Ans[i]<<endl;
	#endif
	for(int i=zero-1;i>=0;i--)
		cout<<Ans[i];
}

int main()
{
	init();
	work();
	Output();
	return 0;
}

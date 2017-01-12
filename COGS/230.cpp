#include<iostream>
#include<cstdio>
#define FILE

using namespace std;
int N,leng[201][201]={0};
bool flag;

void init()
{
	#ifdef FILE
	freopen("sie.in","r",stdin);
	freopen("sie.out","w",stdout);
	#endif
	
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>leng[i][j];
		}
	}
}

void work()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			flag=true;
			for(int k=1;k<=N;k++)
			{
				if(k==i||k==j)
					continue;
				if(leng[i][k]+leng[k][j]==leng[i][j])
					flag=false;
			}
			if(flag)
			{
				cout<<i<<" "<<j<<endl;
			}
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}

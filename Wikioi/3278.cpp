#include <iostream>
using namespace std;
int n,m,i,tmp,maxN=0;
int f[1010][1010];
int a[1010];

void init()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
    f[0][1]=0;
    for(int i=1;i<=n;i++)
	{
        f[i][1]=f[i-1][1]+a[i];
    }
}

void work()
{
	for(int j=2;j<=m;j++)
	{
        for(int i=j;i<=n;i++)
		{
			tmp=1000000;
            for(int k=1;k<i;k++)
			{
                maxN=max(f[i][1]-f[k][1],f[k][j-1]);
                if(tmp>maxN)
					tmp=maxN;
            }
			f[i][j]=tmp;
        }
    }
}

int main()
{
    init();
    work();
	cout<<f[n][m]<<endl;
	return 0;
}

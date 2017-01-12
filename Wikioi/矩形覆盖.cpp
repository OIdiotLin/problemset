#include<iostream>
#define max(a,b) a>b ? a : b
#define min(a,b) a>b ? b : a 
#define Max 1000000
using namespace std;
int n,m,ans=Max,x[52],y[52],f[52][52][5]={0};

int High(int i,int j)
{
	int maxh=0,minh=1000,temp=i;
	while(temp<=j)
		maxh=max(maxh,y[temp++]);
	temp=i;
	while(temp<=j)
		minh=min(minh,y[temp++]);
	return maxh-minh;
}
void Dp()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=2;k<=m;++k)
				f[i][j][k]=Max;
	
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			f[i][j][1]=(x[j]-x[i])*High(i,j);
	for(int i=1;i<=n;++i)
		for(int k=1;k<=m;++k)
			f[i][i][k]=0;
	
	for(int k=2;k<=m;++k)
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int l=i+1;l<=j;++l)
					f[i][j][k]=min(f[i][j][k],f[i][l-1][k-1]+(x[j]-x[l])*High(l,j));
	
	ans=min(ans,f[1][n][m]);
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			if(x[i]>x[j]) 
			{
				swap(x[i],x[j]);
				swap(y[i],y[j]);
			}
			else if(x[i]==x[j]&&y[i]>=y[j])
				swap(y[i],y[j]);
		}
	Dp();
	for(int i=1;i<=n;++i)
		swap(x[i],y[i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(x[i]>x[j])
			{
				swap(x[i],x[j]);
				swap(y[i],y[j]);
			}
			else if(x[i]==x[j]&&y[i]>=y[j])
				swap(y[i],y[j]);
	Dp();
	cout<<ans<<endl;
	return 0;
}

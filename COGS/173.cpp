#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
 
int len[10010],F[10010];
string a[10010];

int main()
{
	freopen("link.in","r",stdin);
	freopen("link.out","w",stdout);
	int i,j,n,MaxNUM=0;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		len[i]=a[i].length();
	}
	for (i=1;i<=n;i++)
	{
		F[i]=1;
		for (j=i-1;j>=1;j--)
			if (len[i]>len[j])
				if (F[i]<F[j]+1)
					if (a[i].substr(0,len[j])==a[j])
						F[i]=F[j]+1;
		MaxNUM=max(MaxNUM,F[i]);
	}
	cout<<MaxNUM<<endl;
	return(0);
}

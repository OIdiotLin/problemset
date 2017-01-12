#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int n,t;
double star,end,a;
double c[3005];
int main()
{
	cin>>t;
	while(t--)
	{
		memset(c,0,sizeof(c));
		cin>>n;
		cin>>star>>end;
		for(int i=1;i<=n;i++)
			cin>>c[i];
			
		a=(end+n*star);
		for(int i=1;i<=n;i++)
		{
			a-=2*c[i]*(n+1-i);
		}
		
		a/=n+1;
		
		
		cout<<setiosflags(ios::fixed);//¸¡µã¿ØÖÆ 
		cout.precision(2);
		cout<<a<<endl;
		
		if(t)
			cout<<endl;
	}
	return 0;
}

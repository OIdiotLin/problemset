#include <iostream>
#define N 100
using namespace std;

int main()
{
	int n,s=0,a[N];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++)
		for(int j=a[i];j<=a[i]*a[i+1];j++)
			if(j%a[i]==0 && j%a[i+1]==0)
			{
				s=j;
				a[i+1]=s;
				break;
			}
	cout<<s<<endl;
	return 0;
}

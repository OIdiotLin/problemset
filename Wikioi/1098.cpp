#include <iostream>
using namespace std;
int main()
{
    int sum=0,n;
    cin>>n;
    int *a=new int[n];
    for (int i=0; i<n; ++i)
	{
		cin>>a[i];
	    sum+=a[i];
	}
	int average=sum/n,operate=0;
	for (int i=0; i<n; ++i)
	{
	    a[i]-=average;
	    if (a[i]!=0)
	    {
	        a[i+1]+=a[i];
	        ++operate;
	    }
	}
	cout<<operate;
	delete []a;
	return 0;
}

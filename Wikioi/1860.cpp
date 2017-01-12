#include<iostream>
#include<cstdio>
#include<algorithm>
int i,n;

using namespace std;

string a[21];

int cmp(string a,string b)
{
	return a+b<b+a;
}

int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(i=n;i>=1;i--)
		cout<<a[i];
		
	return 0;
}

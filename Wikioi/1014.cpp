#include <iostream>
#include <string>

using namespace std;

int box_V,n,item;
int V[20010];

int Max(int a,int b)
{
	return a>b ? a : b;
}

int main()
{
	cin>>box_V>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>item;
		for(int j=box_V;j>=item;j--)
			V[j]=Max(V[j],V[j-item]+item);
	}
	cout<<box_V-V[box_V]<<endl;
	return 0;
}

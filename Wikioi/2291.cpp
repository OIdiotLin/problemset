#include <iostream>
#include <string>
using namespace std;
int sugar[1000010]={0};
int L,R,m,n,amount;

void ask(int left,int right)
{
	int i,sum=0;
	for(i=left;i<=right;i++)
	{
		sum+=sugar[i];
	}
	cout<<sum<<endl;
}

void work()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>sugar[i];
	for(i=1;i<=m;i++)
	{
		cin>>L>>R;
		ask(L,R);
	}
}

int main()
{
	work();
	return 0;
}

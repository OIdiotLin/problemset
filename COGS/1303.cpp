#include <iostream>
#include <cstring>
#define MAXN 10
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int N;

bool is_Bin(int A)
{

	char st[MAXN];
	sprintf(st,"%d",A);
	for(int i=1;i<=MAXN;i++)
	{
		if(st[i]!='0' || st[i]!='1')
			return false;	cout<<"is_Bin"<<endl;
		cout<<i<< " is "<<st[i];
	}
	return true;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("torch.in","r",stdin);
	freopen("torch.out","w",stdout);
	#endif
	cin>>N;
}

void work()
{
	for(int i=1;i<=30000;i++)
	{
		if(is_Bin(i*N))
		{
			cout<<i<<endl;
			return ;
		}
		
	}
		
	cout<<"NO"<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


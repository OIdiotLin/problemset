#include<iostream>
#include<cmath>
using namespace std;
int t,x;

int hs(int num)
{
    if(num==2 || num==1 || num==0)
		return 0;
    for(int i=2;i<=sqrt(num);i++)
        if(num%i==0)
			return 1;
    return 0;
}

int cow()
{
    int i;
    for(i=2;i<=sqrt(x);i++)
        if(x%i==0)
			if(hs(i)==1 && hs(x/i)==1)
				return 1;
    return 0;
}

void init()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
		cin>>x;
		if(cow()==1)
			cout<<"cow"<<endl;
		else
			cout<<"no"<<endl;
    }
}

int main()
{
    init();
    return 0;
}

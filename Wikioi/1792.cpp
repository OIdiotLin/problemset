#include <iostream>

using namespace std;

bool prime(int n)
{
    if(n==2)
		return true; 
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
			return false;
     return true;
}

int main()
{
    int n,i=2;
    cin>>n;
    printf("%d=",n);
    while(n!=1)
	{ 
        if(n%i==0 && prime(i)==1)
		{
			n/=i;
			if(n!=1)
				cout<<i<<"*";
			else
				cout<<i;
		}
        else i++;
    }
    cout<<endl;
    return 0;
}

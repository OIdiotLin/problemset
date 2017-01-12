#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double n;
	while (cin>>n && n>=0)
	{
		if(n<=1)
			cout<<"0%"<<endl;
		else
			cout<<fixed<<setprecision(0)<<(25*n)<<"%"<<endl;
	}
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;  
int main()
{
	int x,y,n;
	cin>>n;
	while(n--)
	{  
		cin>>x>>y;
		cout<<(int)(sqrt(y-x)*2-1e-9)<<endl;
	}
	return 0;
}

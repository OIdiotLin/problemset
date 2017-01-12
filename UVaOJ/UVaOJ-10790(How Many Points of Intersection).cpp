#include <iostream>
using namespace std;

int main()
{
	long long a,b,leap=0;
	while(cin>>a>>b&&(a||b))
	{
		leap++;
		cout<<"Case "<<leap<<": "<<a*(a-1)*b*(b-1)/4<<endl;
	}
	return 0;
}


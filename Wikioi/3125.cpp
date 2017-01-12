#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int m,n,i,j;
	cin>>n>>m;
	for(i=0;i<n;++i)
	{
        for(j=0;j<m;)
			cout<<(char)('A'+abs(i-j++));
        cout<<endl;
    }
	return 0;
}

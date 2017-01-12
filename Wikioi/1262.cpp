#include <iostream>

using namespace std;

int Arrange(int n)
{
	return (n-3)*(n-2)*(n-1)/6;
}

int main()
{
	int N;
	cin>>N;
	cout<<Arrange(N)<<endl;
	return 0;
}

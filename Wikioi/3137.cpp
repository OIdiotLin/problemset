#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int N,order;

void operate()
{
	cin>>order;
	if(order==1)
	{
		int e;
		cin>>e;
		s.push(e);
	}
	else if(order==2)
	{
		s.pop();
	}
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		operate();
	}
	if(s.empty())
		cout<<"impossible!"<<endl;
	else
		cout<<s.top();
	return 0;
}

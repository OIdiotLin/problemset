#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int N,order;
bool flag;
void operate()
{
	cin>>order;
	if(order==1)
	{
		int e;
		cin>>e;
		s.push(e);
		flag=true;
	}
	else if(order==2)
	{
		if(!s.empty())
			s.pop();
		else 
			flag=false;
	}
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		operate();
		if(!flag)
			break;
	}
	if(!flag)
		cout<<"impossible!"<<endl;
	else
		cout<<s.top();
	return 0;
}

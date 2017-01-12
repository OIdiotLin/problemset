#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
void operate()
{
	int order;
	cin>>order;
	if(order==1)
	{
		int e;
		cin>>e;
		q.push(e);
	}
	else if(order==2)
	{
		if(!q.empty())
			q.pop(); 
	}
	else if(order==3)
		cout<<q.front()<<endl;
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		operate();
	}
	return 0;
}

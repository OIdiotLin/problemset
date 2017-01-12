#include <iostream>
#include <queue>

using namespace std;
bool flag=true;
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
		else
			flag=false;
	}
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		operate();
		if(!flag)
			break;
	}
	if(q.empty() || !flag)
		cout<<"impossible!"<<endl;
	else
		cout<<q.front()<<endl;
	return 0;
}

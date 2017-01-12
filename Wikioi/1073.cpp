#include <iostream>
#include <cstring>

using namespace std;

const int MAXN=4050;
int Relation[MAXN];

int Root(int x)
{
	if (!Relation[x])
		return x;
	return (Relation[x]=Root(Relation[x]));
}

bool Find(int a,int b)
{
	if (Root(a)==Root(b))					
		return true;
	return false;
}

void Union(int a,int b)
{
	if (!Find(a,b))
		Relation[Root(a)]=Root(b);			//合并同族 
}

int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		Union(x,y);
	}
	for (int i=1;i<=p;i++)
	{
		int a,b;
		cin>>a>>b;
		if (Find(a,b))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

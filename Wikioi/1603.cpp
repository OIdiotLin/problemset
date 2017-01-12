#include <iostream>

using namespace std;

struct pipe{
	int Length;
	int Radius;
	int Code;
};

pipe source[1010];

void Read(pipe *P)
{
	cin>>P->Length>>P->Radius>>P->Code;
}

int Rank(pipe p[],int n)
{
	int MaxL=0,MinR=99999999,MaxC=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].Length>=MaxL && p[i].Radius<=MinR && p[i].Code>=MaxC)
		{
			MaxL=p[i].Length;
			MinR=p[i].Radius;
			MaxC=p[i].Code;
		} 
		else 
			continue;
	}
	return MaxC;
}

int main()
{
	freopen("1603.in","r",stdin);
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		Read(&source[i]);
	cout<<Rank(source,N)<<endl;
	return 0;
}

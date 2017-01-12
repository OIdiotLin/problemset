#include <iostream>
#include <cstdio>
#define MAXN 100010
using namespace std;

int N,Pic[MAXN];

int search(int array[],int N,int x)
{
    int L,R,mid;
    L=0,R=N;
    while (L<R-1)
    {
        mid=(L+R)/2;
		if(x>=array[mid])
			L=mid;
		else
			R=mid-1;
	}
    return R;
}
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>Pic[i];
	int Q;
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		int H;
		cin>>H;
		cout<<search(Pic,N,H)<<" ";
	}
	cout<<endl;
	return 0;
}

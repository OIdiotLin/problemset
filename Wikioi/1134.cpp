#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
struct p
{
    int a,b,g,k;
}map[10001];

int cover(int x,int y,int n)
{
    for(int i=n-1;i>=0;i--)
	{
        if(x>=map[i].a&&y>=map[i].b
           &&x<=map[i].a+map[i].g&&y<=map[i].b+map[i].k)
            return i+1;
    }
    return -1;
}
int main()
{
    int n;
    int a,b,g,k;
    int x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        scanf("%d%d%d%d",&map[i].a,&map[i].b,&map[i].g,&map[i].k);
    }
    scanf("%d%d",&x,&y);
    printf("%d\n",cover(x,y,n));
}

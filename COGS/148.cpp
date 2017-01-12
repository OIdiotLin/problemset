#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define MAXN  20010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int H[MAXN];
int h;
int N;

inline int cmp(const void *a,const void *b){return *(int *)b-*(int *)a;}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("shelf.in","r",stdin);
	freopen("shelf.out","w",stdout);
	#endif
	cin>>N>>h;
	for(int i=1;i<=N;i++)
		cin>>H[i];
	qsort(H+1,N,sizeof(H[1]),cmp);
	/*for(int i=1;i<=N;i++)
		cout<<H[i]<<" ";*/
	
}

int Greedy(int H[],int h)
{
	int s=0;
	for(int i=1;i<=N;i++)
	{
		s+=H[i];
		if(s>=h)
			return i;
	}
	return -1;
}

int main()
{
	init();
	cout<<Greedy(H,h)<<endl;
	return 0;
}


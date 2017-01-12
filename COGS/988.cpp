#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define MAXN 30010
#define MAXM 5010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

struct Require{
	int L,R;
	int T;
}H[MAXM];

inline int cmp(const void *a,const void *b){return (*(Require*)a).R - (*(Require*)b).R;}

bool Tree[MAXN];
int N,M;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("trees.in","r",stdin);
//	freopen("trees.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=M;i++)
		cin>>H[i].L>>H[i].R>>H[i].T;
	qsort(H,M+1,sizeof(Require),cmp);		//Sort the Requirements by the right.
	#ifdef Debug
	for(int i=1;i<=M;i++)
		cout<<i<<". L="<<H[i].L<<" ; R="<<H[i].R<<" ; T="<<H[i].T<<endl;
	#endif
	memset(Tree,false,sizeof(Tree));
}

void Greedy()
{
	for(int i=1;i<=M;i++)
	{
		int s=0;
		for(int j=H[i].L;j<=H[i].R;j++)
			if(Tree[j])
				s++;					//How many trees have already been planted in Area--H[i].
		if(s<H[i].T)				//If the number of planted trees is less than expected, Plant new trees from the right side.
			for(int j=H[i].R;j>=H[i].R-H[i].T+s+1;j--)
			{
				//if(Tree[j]==false)
				if(Tree[j])
				{
					
				}
				Tree[j]=true;		//Planted!
			
				#ifdef Debug
				cout<<"Tree ["<<j<<"] has been planted!"<<endl;
				#endif
			}
	}
}

void work()
{
	init();
	Greedy();
	int Ans=0;
	for(int i=1;i<=N;i++)		//print the min number of planted trees.
		if(Tree[i])
			Ans++;
	cout<<Ans<<endl;
	#ifdef Debug				//print the solution.
	for(int i=1;i<=N;i++)
		if(Tree[i])
			cout<<i<<" ";
	cout<<endl;
	#endif 
}

int main()
{
	work();
	return 0;
}

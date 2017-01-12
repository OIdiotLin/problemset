#include <iostream>
#include <cstring>
#define MAXN 25
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int N,M;
int Square[MAXN][MAXN][2],F[MAXN][MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	cin>>M>>N;
	memset(F,0,sizeof(F));
	memset(Square,0,sizeof(Square));
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin>>Square[i][j];
	
}

void DP()
{
	F[0][0]
	for()
}

int main()
{
	
	return 0;
}


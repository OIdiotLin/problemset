#include <iostream>
#include <iomanip>
#define MAXN 3000

using namespace std;

double F[MAXN][MAXN];

void dp(int n)
{
	F[0][0]=1;		//±ß½ç 
	for(int i=1;i<=2*n;i++)
		F[i][0]=F[i-1][0]/2;
	
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=n;j++)
			if(j==n)
				F[i][j]=F[i-1][j]+F[i-1][j-1]/2;
			else
				F[i][j]=(F[i-1][j]+F[i-1][j-1])/2;
}

int main()
{
	int N;
	cin>>N;
	dp(N/2);
	cout<<fixed<<setprecision(4)<<F[N-2][N/2]*2<<endl;
}

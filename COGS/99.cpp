#include<cstdio>
#define FILE
using namespace std;
int dp[1024][2];
int main()
{
    #ifdef FILE
	freopen("chashu.in","r",stdin);
    freopen("chashu.out","w",stdout);
    #endif
    int n;
    dp[1][0]=1;
	dp[1][1]=8;
    dp[2][0]=17;
	dp[2][1]=73;
	scanf("%d",&n);
	
    for(int i=3;i<=n;i++)
	{
        dp[i][1]=(dp[i-1][1]*9+dp[i-1][0])%12345;
        dp[i][0]=(dp[i-1][1]+dp[i-1][0]*9)%12345;
    }
    
    printf("%d\n",dp[n][1]);
    return 0;

}

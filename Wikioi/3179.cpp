#include<cstdio>
#include<cstring>

long long num[21][21],f[21][21];
int root[21][21];
void dfs(int r,int k)
{
    if(!k)
		return;
    dfs(root[r][k],k-1);
    printf("%lld ",num[root[r][k]+1][r]);
}

void solve()
{
    int i,j,k;
    char s[21];
    scanf("%s",s);
    int n=strlen(s),div;
    scanf("%d",&div);
    for(i=1;i<=n;++i)
    	for(j=1;j<=div;++j)
        	f[i][j]=-1;
    memset(num,0,sizeof(num));
    for(i=1;i<=n;++i)
    {
        num[i][i]=s[i-1]-'0';
        for(j=i+1;j<=n;++j)
			num[i][j]=10*num[i][j-1]+s[j-1]-'0';
    }
    for(i=1;i<=n;++i)
		f[i][1]=num[1][i];
    for(k=2;k<=div;++k)
    {
        for(i=k;i<=n;++i)
	        for(j=k-1;j<i;++j)
	        {
	            if (f[i][k]<f[j][k-1]*num[j+1][i])
	            {
	                f[i][k]=f[j][k-1]*num[j+1][i];
	                root[i][k]=j;
	            }  
	        }
    }
    printf("%lld\n",f[n][div]);
    dfs(n,div);
    putchar('\n');
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
		solve();
    return 0;
}

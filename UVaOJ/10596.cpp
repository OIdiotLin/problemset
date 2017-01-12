#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int flag,n,m;
int num[210],s[210][10010];
void dfs(int site)
{
    flag++;
    num[site]=0;
    for(int i=0; i<n; i++)
        if(s[site][i]&&num[i]) dfs(i);
}
int main()
{
    //freopen("a.txt","r",stdin);
    int x,y,count;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        flag=0;
        memset(s,0,sizeof(s));
        memset(num,0,sizeof(num));
        for(count=0; count<m; count++)
        {
            scanf("%d%d",&x,&y);
            s[x][y]++;
            s[y][x]++;
            num[x]++;
            num[y]++;
        }
        for(int i=0; i<n; i++)
            if((num[i]%2))
            {
                flag=1;
                break;
            }
        if(flag)
        {
            printf("Not Possible\n");
            continue;
        }
        dfs(x);
        if(flag!=n) printf("Not Possible\n");
        else printf("Possible\n");
    }
    return 0;
}

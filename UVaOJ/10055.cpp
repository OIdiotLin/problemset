#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100008
using namespace std;
int n,h[N],f[N],g[N],l,last,flag,cnt1,cnt2;
int main()
{
    //freopen("flower.in","r",stdin);
    //freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) scanf("%d",&h[i]);
    l = 1; flag = 0;
    while (l <= n){
        int r = 0;
        if (!flag){
            for (r = l;r <= n;r++) if (h[r] > h[r+1]) break;
            cnt1++;
            l = r;
            flag = 1; 
            if (l == n) break;
        }
        else{
            for (r = l;r <= n;r++) if (h[r] < h[r+1]) break;
            cnt1++;
            l = r;
            flag = 0;
            if (l == n) break;
        }
    }
    l = 1; flag = 1;
    while (l <= n)
	{
        int r = 0;
        if (!flag)
		{
            for (r = l;r <= n;r++) if (h[r] > h[r+1]) break;
            cnt2++;
            l = r;
            flag = 1; 
            if (l == n) break;
        }
        else
		{
            for (r = l;r <= n;r++) if (h[r] < h[r+1]) break;
            cnt2++;
            l = r;
            flag = 0; 
            if (l == n) break;
        }
    }
    cnt1 = max(cnt1,cnt2);
    printf("%d\n",cnt1);
    return 0;
}

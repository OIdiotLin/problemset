#include <cstdio>
using namespace std;
#define maxn 1000010
int a[maxn],b[maxn],d[maxn],f[maxn];
long long c[maxn];
int main()
{
	int n; scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&d[i]);
	int all=1;
	while (scanf("%d%d%lld",&a[all],&b[all],&c[all])!=-1)
		all++;
	all--;
	f[all-1]=-a[all];
	for (int i=all-1; i>1; i--)
	{
		long long left=(long long)(f[i]+1)*d[f[i]]*d[f[i]]+(long long)f[i]*d[f[i]]+1;
		long long right=(long long)a[i]*(f[i]+1)*d[f[i]]*d[f[i]]+(long long)(b[i]+1)*f[i]*d[f[i]]+c[i]+f[i];
		f[i-1]=-right/left;
	}
	for (int i=1; i<all; i++)
		printf("%d\n",f[i]);
	return 0;
}

#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n=1;
double a[1000000];
int main()
{
	freopen("1001.in","r",stdin);
int i;
while(scanf("%lf",&a[n])!=EOF) n++;
for(i=n-1;i>=1;i--) printf("%0.4lf\n",sqrt(a[i]));
return 0;
}

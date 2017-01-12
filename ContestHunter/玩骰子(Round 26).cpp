#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,s1,s2;
int a[10],C[10][10],f[60];
void dfs(int x,int y,int z) {
	int i,j,k;
	if (x>n) {
		memset(f,0,sizeof(f));
		f[0]=1;
		For(i,1,n) for (j=m-a[i];j>=0;j--) f[j+a[i]]|=f[j];
		if (f[m]) {
			k=1;
			for (i=1;i<=n;i=j) {
				for (j=i;a[j]==a[i];j++);
				k*=C[n-i+1][j-i];
			}
			s1+=k;
		}
		return;
	}
	For(i,y,6) a[x]=i,dfs(x+1,i,z+i);
}
int main() {
	scanf("%d%d",&n,&m);
	s2=1; For(i,1,n) s2*=6;
	For(i,0,n) {
		C[i][0]=1;
		For(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	dfs(1,1,0);
	//printf("%d\n",s1);
	if (!s1) printf("0\n");
	else if (s1==s2) printf("1\n");
	else k=__gcd(s1,s2),printf("%d/%d\n",s1/k,s2/k);
	return 0;
}

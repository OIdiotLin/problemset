#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<iomanip>
#include<queue>
#include<set>
#include<map>
using namespace std;
const int SIZEN=1010;
double P[SIZEN]={0};
double f[SIZEN]={0};
int main(){
	freopen("tribbles.in","r",stdin);
	freopen("tribbles.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		int n,k,m;
		scanf("%d%d%d",&n,&k,&m);
		int i,j;
		for(i=0;i<n;i++) scanf("%lf",&P[i]);
		f[0]=0,f[1]=P[0];
		for(i=2;i<=m;i++){
			f[i]=0;
			for(j=0;j<n;j++) f[i]+=P[j]*pow(f[i-1],j);
		}
		printf("Case #%d: %.7lf\n",kase,pow(f[m],k));
	}
	return 0;
}

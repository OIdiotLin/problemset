#include<cstdio>
#include<cstdlib>
using namespace std;
int ans,n,m,total,t,now;
int dfn[2000],low[2000],next[1100000],head[2000],z[2000],dot[2000],pos[2000],u[1100000],v[1100000],id[2000];
void make(int x,int y)
{
	u[++m]=x; v[m]=y; next[m]=head[x]; head[x]=m;
}
int min(int x,int y)
{ return x<y?x:y;}
void tarjan(int x)
{
	int i;
	t++; dfn[x]=t; low[x]=t; now++; z[now]=x; dot[x]=1;
	for(i=head[x];i;i=next[i]) if(dot[v[i]]==0) {tarjan(v[i]); low[x]=min(low[x],low[v[i]]);} else if(dot[v[i]]==1) {low[x]=min(low[x],dfn[v[i]]);}
	if(low[x]==dfn[x]) 
	{
		total++;
		while(z[now+1]!=x)
		{
			dot[z[now]]=2;
			pos[z[now]]=total;
			now--;
		}
	}
}
int main()
{
	freopen("virus.in","r",stdin);
	freopen("virus.out","w",stdout);
	int i,j,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) 
	{
		scanf("%d",&r);
		if(r==1) make(i,j);
	}
	for(i=1;i<=n;i++) if(dot[i]==0) tarjan(i);
	n=total; total=m; m=0;
	for(i=1;i<=total;i++) if(pos[u[i]]!=pos[v[i]]) id[pos[v[i]]]++;
	for(i=1;i<=n;i++) if(id[i]==0) ans++;
	printf("%d\n",ans);
	return 0;
}

#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAX=100000;
struct Trie
{
	int ch[MAX+1][26];
	int val[MAX+1];
	int sz;
	Trie(){sz=1;memset(ch[0],0,sizeof(ch[0]));}
	int idx(char c){return c-'a';}
}Trie;
char t[MAX*10+1];
int n,m,u,v,r,c,i,j;
int f[MAX*10+1],last[MAX*10+1];
bool find[MAX*10+1];
queue<int>q;
vector<int>g[MAX*10+1];
void make(int x,int p)
{
	if(p)
	{
		g[x-Trie.val[p]+1].push_back(Trie.val[p]);
		make(x,last[p]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	while (n--)
	{
		scanf("%s",t);
		u=0;v=strlen(t);
		for (i=0;i<v;i++)
		{
			c=Trie.idx(t[i]);
			if (!Trie.ch[u][c])
			{
				memset(Trie.ch[Trie.sz],0,sizeof(Trie.ch[Trie.sz]));
				Trie.val[Trie.sz]=0;
				Trie.ch[u][c]=Trie.sz++;
			}
			u=Trie.ch[u][c];
		}
		Trie.val[u]=v;
	}
	f[0]=0;
	for (c=0;c<26;c++)
	{
		u=Trie.ch[0][c];
		if (u)
		{
			f[u]=0;
			q.push(u);
			last[u]=0;
		}
	}
	while (!q.empty())
	{
		r=q.front();q.pop();
		for (c=0;c<26;c++)
		{
			u=Trie.ch[r][c];
			if (!u)
			{
				Trie.ch[r][c]=Trie.ch[f[r]][c];
				continue;
			}
			q.push(u);
			v=f[r];
			while (v&&!Trie.ch[v][c])v=f[v];
			f[u]=Trie.ch[v][c];
			last[u]=Trie.val[f[u]]?f[u]:last[f[u]];
		}
	}
	while (m--)
	{
		scanf("%s",t);
		n=strlen(t);j=0;
		memset(find,0,sizeof(find));
		for (i=0;i<n;i++)g[i].clear();
		for (i=0;i<n;i++)
		{
			c=Trie.idx(t[i]);
			j=Trie.ch[j][c];
			if (Trie.val[j])make(i,j);
			else if(last[j])make(i,last[j]);
		}
		for (i=0;i<n;i++)
		{
			if (i!=0&&!find[i-1])continue;
			for (j=0;j<g[i].size();j++)
			find[i+g[i][j]-1]=1;
		}
		for (i=n;i>0;i--)if (find[i])break;
		if (i==0)printf("0\n");
		else printf("%d\n",i+1);
	}
}

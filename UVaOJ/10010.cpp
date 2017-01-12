#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000

char map[MAXN][MAXN];
char word[MAXN][MAXN];

bool find(int x, int y, char word[], int m, int n)
{
	int i, j, k;
	int len;
	int flag;
	len=strlen(word);
	if (len+y<n)
	{
		flag=1;
		for (i=0; i<len; ++i) 
			if (word[i] != map[x][y+i])
			{
				flag=0;
				break;
			} 
		if (flag)
			return true;
	}
	if (y-len>=0)
	{
		flag=1;
		for (i=0; i<len; ++i)
			if (word[i] != map[x][y-i])
			{
				flag=0;
				break;
			}
		if (flag)
			return true;
	}
	if (x-len>=0)
	{	
		flag=1;
		for (i=0; i<len; ++i)
			if (word[i] != map[x-i][y])
			{
				flag=0;
				break;
			}
		if (flag)
			return true;
	}

	if (x+len<m)
	{		
		flag=1;
		for (i=0;i<len;++i)
			if (word[i] != map[x+i][y])
			{
				flag=0;
				break;
			}
		if (flag)
			return true;
	}

	if (y-len+1>=0 && x-len+1>=0)
	{
		flag=1;
		for (i=0; i<len; ++i)
			if (word[i] != map[x-i][y-i])
			{
				flag=0;
				break;
			}
		if (flag)
			return true;
	}

	if (y+len-1<n && x-len+1>=0)
	{
		flag=1;
		for (i=0; i<len; ++i)
			if (word[i] != map[x-i][y+i])
			{
				flag=0;
				break;
			}
		if (flag)
			return true;
	}

	if (x+len-1<m && y-len+1>=0)
	{
		flag=1;
		for (i=0; i<len; ++i)
			if (word[i] != map[x+i][y-i])
			{
				flag=0;
				break;
			}
		if (flag)
			return true;
	}

	if (x+len-1<m && y+len-1<n)
	{
		flag=1;
		for (i=0; i<len; ++i)
			if (word[i]!=map[x+i][y+i])
			{
				flag=0;
				break;
			}
		if (flag)
			return true;		
	}
	return false;
}
int main()
{
	//freopen("10010.in","r",stdin);
	//freopen("10010.out","w",stdout);
	int count, nword;
	int m,n;
	int i,j,k;
	int flag;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d",&m,&n);	
		for (i=0;i<m;++i)
			scanf("%s",map[i]);
		
		scanf("%d",&nword);
		for (i=0;i<nword;++i)
			scanf("%s",word[i]);
		
		for (i=0;i<m;++i)
			for (j=0;j<n;++j)
				if (isupper(map[i][j]))
					map[i][j]+=32;
		
		for (i=0;i<nword;++i)
			for (j=0;j<strlen(word[i]);++j)
				if (isupper(word[i][j]))
					word[i][j]+=32;
		for (k=0; k<nword; ++k)
		{
			flag=0;
			for (i=0; i<m; ++i)
			{
				for (j=0; j<n; ++j)
				{
					if (map[i][j]==word[k][0]) 
						flag=find(i, j, word[k], m, n);
					if (flag)s
					{
						printf("%d %d\n",i+1,j+1);
						break;
					}
					else
						continue;
				}
				if(flag) break;
			}
		}
	}
	return 0;
}

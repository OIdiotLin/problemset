/*
	Name: Excuse,Excuse!!
	Copyright: UVaOJ-409
	Author: LHD
	Date: 17/11/13 08:48
	Description: 给你一系列的关键单词，然后给你几个借口，要你找出含有关键单词最多借口，如果有多个，可以按任意顺序输出。
				 做法比较简单，挨个比较就好。 
*/

#include <stdio.h>
#include <string.h>
char word[102][102];
int n,m;
int num(char *str)
{
	
	int nn,i,j,count,number,k;
	char s[102];
	nn=strlen(str);
	count=0;
	j=0;
	number=0;
	for(i=0;i<nn;i++)
	{
		if(!(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'))
		{
			s[j]='\0';
			for(k=0;k<n;k++)
			{
				if(strcmp(s,word[k])==0)
					number++;
			}
			j=0;
			continue;
		}
		s[j]=str[i];
		j++;
	}
	return number;
}
int main()
{
	freopen("409.in","r",stdin);
	int max,i,j,length;
	int numb[100];
	char str[100][100];
	char str1[100][100];
	int count=0;
	while(scanf("%d%d%*c",&n,&m)!=EOF)
	{
		count++;
		for(i=0;i<n;i++)
		{
			gets(word[i]);
			length=strlen(word[i]);
			for(j=0;j<length;j++)
			{
				if(word[i][j]>='A'&&word[i][j]<='Z')
					word[i][j]=word[i][j]+'a'-'A';
			}
		}
		for(i=0;i<m;i++)
		{
			gets(str1[i]);
			length=strlen(str1[i]);
			for(j=0;j<length;j++)
				str[i][j]=str1[i][j];
			str[i][j]='\0';
			for(j=0;j<length;j++)
			{
				if(str[i][j]>='A'&&str[i][j]<='Z')
					str[i][j]=str[i][j]+'a'-'A';
			}
			numb[i]=num(str[i]);
		}
		printf("Excuse Set #%d\n",count);
		max=0;
		for(i=0;i<m;i++)
		{
			if(numb[i]>=max)
				max=numb[i];
		}
		for(i=0;i<n;i++)
		{
			if(numb[i]==max)
			{
				puts(str1[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

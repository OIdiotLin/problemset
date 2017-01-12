#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;
typedef char str[20000];
double testN;

bool AnsComp(double a,double b)
{
	int x,y;
	double r;
	x=(int)log10(a)+1;
	y=(int)log10(b)+1;
	if(x!=y) 
		return true;
	r=pow(10,x-12);
	if(fabs(a-b)>r)
		return 1;
	return 0;
}

long Operator(char c)
{
	switch(c)
	{
	case '+' : return 0;
	case '-' : return 0;
	case '*' : return 1;
	case '/' : return 1;
	case '^' : return 2;
	}
	return -1;
}

double work(str s)
{
	long l=strlen(s),i,T=0,k=-1,Min=999999;
	if(l==1 && s[0]=='a' )
		return testN;
	for(i=l-1;i>=0;i--)
	{
		if(s[i]==')')
			T++;
		if(s[i]=='(')
			T--;
		if(!T && Operator(s[i])>=0)
		Min=(Operator(s[i])<Min) ? (k=i,Operator(s[i])) : Min;
	}
	if (k!=-1)
	{
		str s1={0},s2={0};
		strncpy(s1,s,k);
		strncpy(s2,s+k+1,l-k);
		
		switch(s[k])
		{
			case '+':return work(s1)+work(s2);
			case '-':return work(s1)-work(s2);
			case '*':return work(s1)*work(s2);
			case '/':return work(s1)/work(s2);
			default:return pow(work(s1),work(s2));
		}
	}
	if ( s[0]=='(' )
	{
		str s1={0};
		strncpy(s1,s+1,l-2);
		return work(s1);
	}
	double x=0;
	sscanf(s,"%lf",&x);
	return x;
}

double GetNum(str s)
{
	long l=strlen(s),i,L=0,R=0;
	for(i=0;i<l;i++)
		if(s[i]==' ')
		{
			str s1={0},s2={0};
			strncpy(s2,s+i+1,l-i);
			s[i]=0;
			strcat(s,s2);
			i--;
		}
	else if(s[i]=='(') 
		L++;
	else if(s[i]==')')
		R++;
	long t=L-R;
	if(t>0)
		while(t--)
			s[ strlen(s) ]=')';
	if(t<0)
		while(t++)
		{
			str s1={0};
			strcpy(s1,s);
			s[0]='(';
			s[1]=0;
			strcat(s,s1);
		}
	return work(s);
}

int main()
{
	str S={0},s={0};
	gets(S);
	double Ans;
	long N,i;
	scanf("%ld ",&N);
	for (i=0;i<N;i++)
	{
		int b=0;
		gets(s);
		
		testN=0.7;
		double x=GetNum(s);
		Ans=GetNum(S);
		if(!AnsComp(x,Ans))
			b=1;
		else
			b=0;
			
		testN=1.25;
		x=GetNum(s);
		Ans=GetNum(S);
		if(b && !AnsComp(x,Ans))
			b=1;
		else
			b=0;
		if(b)
			printf("%c",i+'A');
	}
	printf("\n");
	return 0;
}

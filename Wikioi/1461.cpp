#include <string.h>
#include <stdio.h>
int main()
{
	int sum=0;
	char buf[1000];
	gets(buf);
	for (int i=0;i<strlen(buf);i++)
	{
			if(buf[i]=='a' || buf[i]=='d' || buf[i]=='g' || buf[i]=='j' || buf[i]=='m' || buf[i]=='p' || buf[i]=='t' || buf[i]=='w' || buf[i]==' ')
				{sum+=1;continue;}
			if(buf[i]=='b' || buf[i]=='e' || buf[i]=='h' || buf[i]=='k' || buf[i]=='n' || buf[i]=='q' || buf[i]=='u' || buf[i]=='x')
				{sum+=2;continue;}
			if(buf[i]=='c' || buf[i]=='f' || buf[i]=='i' || buf[i]=='l' || buf[i]=='o' || buf[i]=='r' || buf[i]=='v' || buf[i]=='y')
				{sum+=3;continue;}
			if(buf[i]=='s' || buf[i]=='z')
				{sum+=4;continue;}
	}
	printf("%d",sum);
	return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
	char number[15];
	gets(number);
	bool leap=false;
	if(number[0]=='-')
	{
		printf("-");
		leap=true;
	}
	if(number[0]=='0')
	{
		printf("0");
		return 0;
	}
    int pos=strlen(number);
	for (int i=strlen(number);i>0;i--)
	{
		if(number[i]=='0')
			pos--;
        else break;
	}
    for (int i=pos-1;i>=(leap ? 1 : 0);i--)
	{
		printf("%c",number[i]);
	}
	return 0;
}

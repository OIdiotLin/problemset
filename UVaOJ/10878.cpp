#include <stdio.h>
int main()
{
	freopen("10878.in","r",stdin);
	//freopen("10878.out","w",stdout);
	int i,j;
	int len,decode;
	char tape[20],s[200];	
	while (fgets(tape,20,stdin))
	{
		decode=0;
		if (tape[0]=='_')
			continue;
		for (i = 1; i < 10; ++i)
		{
			if(tape[i]==' ')
				decode*=2;
			else if (tape[i]=='o')
				decode=decode*2+1;
		}
		if (decode!=2) 		
			putchar(decode);
	}
	return 0;
}

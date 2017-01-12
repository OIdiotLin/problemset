/*
	Name: Palindromes
	Copyright: UVaOJ-401
	Author: LHD
	Date: 17/11/13 09:59
	Description: 字符串处理
				 可以编写两个函数：Mirror(判断是否为镜像)  Pal(判断是否为回文) 
*/
#include <stdio.h>
#include <string.h>
#define MAXN 2000
bool Pal(char a[MAXN])
{
    int i,lengtha;
    lengtha=strlen(a)-1;
    for(i=0;i<=lengtha;i++)
        if(a[i]!=a[lengtha-i]) return false;
    return true;
}
bool Mirror(char a[MAXN])
{
    int i,lengtha;
    lengtha=strlen(a)-1;
    for(i=0;i<=lengtha;i++)
	if(a[i]!='A' && a[i]!='3' && a[i]!='H' && a[i]!='I' && a[i]!='L' && a[i]!='J' && a[i]!='M' && a[i]!='O' && a[i]!='2' && a[i]!='T' && a[i]!='U' && a[i]!='V' && a[i]!='W' && a[i]!='X' && a[i]!='Y' && a[i]!='5' && a[i]!='1' && a[i]!='S' && a[i]!='E' && a[i]!='Z' && a[i]!='8')
        return false;
    for(i=0;i<=lengtha;i++)
		if(a[i]=='E'||a[i]=='J'||a[i]=='L'||a[i]=='S'||a[i]=='Z'||a[i]=='2'||a[i]=='3'||a[i]=='5'||a[i]!=a[lengtha-i])
		{
	        switch(a[i])
			{
				case 'E':if(a[lengtha-i]!='3') return false;break;
				case 'J':if(a[lengtha-i]!='L') return false;break;
		        case 'L':if(a[lengtha-i]!='J') return false;break;
		        case 'S':if(a[lengtha-i]!='2') return false;break;
				case 'Z':if(a[lengtha-i]!='5') return false;break;
				case '2':if(a[lengtha-i]!='S') return false;break;
				case '3':if(a[lengtha-i]!='E') return false;break;
				case '5':if(a[lengtha-i]!='Z') return false;break;
				default:return false;
	        }
	    }
    return true;
}
int main()
{
	char a[MAXN]="0";
    int i;
    while(scanf("%s",a)!=NULL)
	{
        for(i=0;i<strlen(a);i++)		//把'0'转换成'O' 
			if(a[i]=='0')
				a[i]='O';
        if(Pal(a))
            {
	            if(Mirror(a))
					printf("%s -- is a mirrored palindrome.\n",a);
	            else
					printf("%s -- is a regular palindrome.\n",a);
			}
        else if(Mirror(a))
				printf("%s -- is a mirrored string.\n",a);
            else printf("%s -- is not a palindrome.\n",a);
        printf("\n");
	}
        return 0;
}

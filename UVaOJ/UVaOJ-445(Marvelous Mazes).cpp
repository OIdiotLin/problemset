/*
	Name: Marvelous Mazes
	Copyright: UVaOJ-445
	Author: LHD
	Date: 21/11/13 13:29
	Description: 输入一连串字符，如果出现大写字母，则按照它前面的数字之和输出；读入的b代表空格，！和回车代表换行。
	Analysis: 用scanf一个一个判定就好。 
*/
#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;   
    int coefficient=0,i=0;
    while(scanf("%c",&c)!=EOF)
    {
		if(isdigit(c))
        {
			coefficient+=(c-48);
            printf("%d",coefficient);
        }
        else if(isupper(c)||c=='b'||c=='*')       
        {
            for(i=0;i<coefficient;i++)
            {
                if(c=='b')
                    printf(" ");
                else
                    printf("%c",c);
            }
            coefficient=0;
        }
        else if(c=='\n'||c=='!')
            printf("\n");
    }
    return 0;
}

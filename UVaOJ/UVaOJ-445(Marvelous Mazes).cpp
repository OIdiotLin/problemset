/*
	Name: Marvelous Mazes
	Copyright: UVaOJ-445
	Author: LHD
	Date: 21/11/13 13:29
	Description: ����һ�����ַ���������ִ�д��ĸ��������ǰ�������֮������������b����ո񣬣��ͻس������С�
	Analysis: ��scanfһ��һ���ж��ͺá� 
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

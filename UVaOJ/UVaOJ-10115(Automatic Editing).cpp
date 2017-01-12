/*
	Name: Automatic Editing
	Copyright: UVaOJ-10115
	Author: LHD
	Date: 20/11/13 15:27
	Description:完成一项自动编辑工作。
				该工作要求按一些规则完成替换工作。
				对于每个规则，要求不停地在字符串中找到关键词进行替换，
				直到关键词不再出现于字符串中为止。
				要求完成所有规则的替换工作，输出最终字符串。
				主要依靠几个string函数:
				strlen():获取长度 
				strcmp():比较字符串，在判定替换时很有用 
				strcpy()&memcpy():复制
				strcat():字符串连接 
				strstr():字符串查找  
				另外就是二维字符串的运用，需要多加练习以熟练之。 
*/
#include<stdio.h>
#include<string.h>
char keyWords[50][100],input[50][100],replaced[300],temp[1000];
int main()
{
	freopen("autoedit.in","r",stdin);
	//freopen("autoedit.out","w",stdout); 
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        getchar();
        int i;
        for(i=0;i<n;i++)
        {
            gets(keyWords[i]);
            gets(input[i]);
        }
        gets(replaced);
        for(i=0;i<n;i++)
        {
            char *p,*q;
            while(p=strstr(replaced,keyWords[i]),p!=NULL)	//字符串查找，找到关键字串的时候返回指针p 
            {
                q=p+strlen(keyWords[i]);
                strcpy(temp,input[i]);
                strcat(temp,q);								//字符串连接函数。 
                strcpy(p,temp);
            }
        }
        puts(replaced);
    }
    return 0;
}

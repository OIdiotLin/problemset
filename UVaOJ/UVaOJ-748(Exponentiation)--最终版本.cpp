/*
	Name: Exponentiation
	Copyright: UVaOJ-748
	Author: LHD
	Date: 22/11/13 19:59
	Description: 高精度输出R^n。由于这里的R是个浮点数，所以要注意对小数点的处理:
				 先在输入时把小数点提取出来并记录位置，用普通乘法计算出结果后从后向前计算位置添加小数点。
				 循环变量有点伤，略多。 
*/
#include <stdio.h>
#include <string.h>
#define MAXN 100000
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
char part1[MAXN],part2[MAXN],ans[MAXN],temps[MAXN];
void put(char s[])
{
    int maxLength=max(strlen(s),strlen(ans));
    int minLength=min(strlen(s),strlen(ans));
    int i;
    int c=0;
    for(i=0;i<minLength;++i)
    {
        int a=s[i]-'0'+ans[i]-'0'+c;
        ans[i]=a%10+'0';
        c=a/10;
    }
    for(i=minLength;i<maxLength;++i)
    {
        int a=s[i]+ans[i]-'0'+c;
        ans[i]=a%10+'0';
        c=a/10;
    }
    if(c!=0)
        ans[i]=c+'0';
}
void multi(char part1[],int x,int n)
{
    memset(temps,0,sizeof(temps));
    int c=0;
    int i;
    int len=strlen(part1);
    for(i=0;i<len;++i)
    {
        int a=(part1[i]-'0')*x+c;
        temps[i]=a%10+'0';
        c=a/10;
    }
    if(c!=0)
        temps[len++]=c+'0';
    for(i=len-1;i>=0;--i)
        temps[i+n]=temps[i];
    for(i=0;i<n;++i)
        temps[i]='0';
    put(temps);
}
void judge(char s[])
{
    int i=0;
    int j=strlen(s)-1;
    for(;i<j;++i,--j)
    {
        char c=s[i];
        *(s+i)=s[j];
        *(s+j)=c;
    }
}
int main()
{
    char num1[100];
    int n;
    int point;
    while(scanf("%s %d",num1,&n)!=EOF)
    {
        memset(ans,0,sizeof(ans));			//初始化数组 
        memset(part1,0,sizeof(part1));
        memset(part2,0,sizeof(part2));
        int i,j;
        point=0;
        for(i=strlen(num1)-1;i>=0;--i)
        {
            if(num1[i]=='.')
                break;
            point++;
        }
        if(i<0)
            point=0;
        bool flag=false;
        for(i=0;num1[i]!=0;++i)
        {
            if(num1[i]!='.')
                part1[i-flag]=num1[i];
            else
                flag=true;
        }
        part1[i]=0;
        judge(part1);
        strcpy(part2,part1);
        strcpy(ans,part1);
        for(j=1;j<n;++j)
        {
            memset(part1,0,sizeof(part1));
            strcpy(part1,ans);
            memset(ans,0,sizeof(ans));
            for(i=0;i<(int)strlen(part2);++i)
                multi(part1,part2[i]-'0',i);
        }
        for(i=MAXN-1;i>=0&&(ans[i]==0||ans[i]=='0');--i)
            ans[i]=0;
        point=point*n;
        if(strlen(ans)<=point)
        {
            printf(".");
            for(i=point-1;i>strlen(ans)-1;--i)
                printf("0");
            for(;i>=0;--i)
                printf("%c",ans[i]);
            printf("\n");
        }
        else
        {
            for(i=strlen(ans)-1;i>point-1;--i)
                printf("%c",ans[i]);
            flag=true;
            for(j=0;j<=i;++j)
            {
                if(ans[j]!='0')
                {
                    flag=false;
                    break;
                }
            }
            if(j>i)
                printf("\n");
            else
            {
                printf(".");
                for(;i>=j;--i)
                    printf("%c",ans[i]);
                printf("\n");
            }
        }
    }
    return 0;
}

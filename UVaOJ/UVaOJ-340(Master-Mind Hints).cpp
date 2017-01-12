/*
	Name: Master-Mind Hints
	Copyright: UVaOJ-340
	Author: LHD
	Date: 17/11/13 09:47
	Description:  
				4
				1 3 5 5         a
				
				1 1 2 3         b         (1,1)
				4 3 3 5         c         (2,0)
				6 5 5 1         d         (1,2)
				6 1 3 5         e         (1,2)
				1 3 5 5         f         (1,2)
				0 0 0 0
				
				 题意： a行是设计者出的密码 ，下面几行都是破译者给出的猜想，将下面每次猜想的那行密码一次与a行代码比较，先比较所有strong的，
				 也就是两行不但值一样，且位置都一样，发现一个就加一，得到的数就是括号里第一个数字，注意，每行猜想的密码与a行代码比较时，
				 每个位置的数字只能使用一次，所以最好用两个标记数组来记录一下密码的使用状况，接着就算weak的值，也就是两行值一样，但位置却
				 不同且每个位置都还没标记过的，发现一个就加一，值就是括号里第二个的大小。
				 
				i   0	1	2	3
				a	1	3	5	5
				b	1	1	2	3
				c	4	3	5	5

				
				b行的strong和weak值分别就是括号里的两个数，strong的那个1是(a.0) (b.0),weak是 (a.1)(b.3)
				
				c行strong值有两个，一个是 （a,1）（c,1）,另一个是 （a.3）（c.3）没有符合weak要求的
*/
#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b) ? a : b

int buf[1005],set[1005];  
int a[15],b[15],c[15];
int main()  
{
	freopen("340.in","r",stdin);
    int count=0, n;  
    while (scanf("%d", &n), n)  
    {  
        memset(c,0,sizeof(c));  
        for (int i=0;i<n;i++)  
        {
            scanf("%d", &buf[i]);  
            c[buf[i]]++;  
        }  
        printf("Game %d:\n", ++count);
        //printf("Game %d:\n", count++);
        while (1)
        {
            memcpy(a,c,sizeof(c));
        	memset(b,0,sizeof(b));
            for (int i=0;i<n;i++)
            {
                scanf("%d",&set[i]);
                b[set[i]]++;
            }
            if (!set[0])
				break;
            int x=0,y=0;
            for (int i=0;i<n;i++)
                if (buf[i]==set[i])
                {
                    a[buf[i]]--;
                    b[buf[i]]--;
                    x++;
                    //printf("%d ",a[buf[i]]);
                }
            for (int i=1;i<=9;i++)
                y+=min(a[i],b[i]);
            printf("    (%d,%d)\n",x,y);
        } 
    } 
    return 0;
}

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
				
				 ���⣺ a��������߳������� �����漸�ж��������߸����Ĳ��룬������ÿ�β������������һ����a�д���Ƚϣ��ȱȽ�����strong�ģ�
				 Ҳ�������в���ֵһ������λ�ö�һ��������һ���ͼ�һ���õ����������������һ�����֣�ע�⣬ÿ�в����������a�д���Ƚ�ʱ��
				 ÿ��λ�õ�����ֻ��ʹ��һ�Σ�������������������������¼һ�������ʹ��״�������ž���weak��ֵ��Ҳ��������ֵһ������λ��ȴ
				 ��ͬ��ÿ��λ�ö���û��ǹ��ģ�����һ���ͼ�һ��ֵ����������ڶ����Ĵ�С��
				 
				i   0	1	2	3
				a	1	3	5	5
				b	1	1	2	3
				c	4	3	5	5

				
				b�е�strong��weakֵ�ֱ�������������������strong���Ǹ�1��(a.0) (b.0),weak�� (a.1)(b.3)
				
				c��strongֵ��������һ���� ��a,1����c,1��,��һ���� ��a.3����c.3��û�з���weakҪ���
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

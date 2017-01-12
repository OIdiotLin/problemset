/*
	Name: Integer Inquiry
	Copyright: UVaOJ-424
	Author: LHD
	Date: 23/11/13 08:36
	Description: 多个大整数相加，和大数阶乘的思想差不多。 
*/

#include <stdio.h>
#include <string.h>
int i,j,n,m,t,s,X=0,Y,x,max=0,k,Z;
char addend[1000];
int a[100][100]={-1},b[100000];
int length;
void output()
{
	printf("%d",b[k]);
    for(j=k-1;j>=0;j--)
    {
        if(b[j]>999); 
		else if(b[j]>99)
			printf("0");
		else if(b[j]>9)
            printf("00");
		else
            printf("000");
        printf("%d",b[j]);
    }
}
void set()
{
	while(scanf("%s",addend)!=EOF)
	{
		s=0;
	    length=strlen(addend);
	    if(length==1&&addend[0]=='0')			//一位数或0就直接算好了。 
	    	break;
	    Y=0;
	    for(i=length-1;i>=0;i-=4)
	    {
	        t=1;
	        s=0;
	        for(j=1;j<=4&&i-j+1>=0;j++)
	        {
	            s+=(addend[i-j+1]-'0')*t;
	            t*=10;
	        }
	        a[X][Y]=s;
	        Y+=1;
	    }
	    if(Y>=max)
	    	max=Y;
	    X+=1;
	}
}
void add()
{
	x=0;
    int p=0;
    for(i=0;i<=99;i++)
    {
        b[i]=0;
    }
    Z=0;
    for(i=0;i<=max-1;i++)
    {
        s=0;
        for(j=0;j<=X-1;j++)
        {
            if(a[j][i]!=-1)
            {
                s+=a[j][i];
            }
        }
        for(j=x;j<=x;j++)
        {
            s=s+p;
			p=0;
			if(s>9999)
            {
                b[j]+=s%10000;
                p=s/10000;
                s=0;
                x+=1;
            }
			else
				b[j]+=s;
        }
        Z+=1;
        if(i==max-1)
        {
            k=x;
        }
        x=Z;
    }
}
int main()
{
	set();
    add();
    output();
    printf("\n");
    return 0;
}


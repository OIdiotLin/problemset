#include <stdio.h>
#include <math.h>
int main()
{
    double sum, t;
    int year, i;
    while(scanf("%d",&year)==1, year!=0)
    {
        t=1<<((year-1960)/10+2);
        sum=i=0;
        while(++i)
        {
			sum+=log(i)/log(2);  //ÐèÒª»»µ×
            if(sum>t)
            {
				printf("%d\n",i-1);
    			break;
            }
        }
    }
    return 0;
}

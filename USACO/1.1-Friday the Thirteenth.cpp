/*
ID: MagicLin
PROG: friday
LANG: C
*/
#include <stdio.h>
int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int s,i,j,k,day;
    int times[8]={0};
    scanf("%d",&s);
    day=7;
    for (i=1900;i<=1900+s-1;i++)
    for (j=1;j<=12;j++)
    for (k=1;k<=31;k++)
    {
        day=day+1;
        if (day==8) day=1;
        if (k==13) times[day]++; 
        if ((j==4 || j==6 || j==9 || j==11) && k==30) break;
        if (j==2 && ((i%4==0 && i%100!=0) || (i%400==0)) && k==29) break;
        if (j==2 && k==28 && (i%4!=0 || (i%4==0 && i%100==0 && i%400!=0))) break;
    }
	printf("%d %d %d %d %d %d %d\n",times[6],times[7],times[1],times[2],times[3],times[4],times[5]);
    return 0;
}

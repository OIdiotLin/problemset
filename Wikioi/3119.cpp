#include <stdio.h>
#include <string.h>

int l;
int work(int o,char *O,int i)
{
    char c, *D=O ;
    if(o>0)
    {
        for(l=0;D[l];D[l++]-=10)
        {
            D[l++]-=120;
            D[l]-=110;
            while(!work(0,O,l))
                D[l]+=20;
            putchar((D[l]+1032)/20);
        }
        putchar(10);
    }
    else
    {
        c=o+(D[i]+82)%10-(i>l/2)*(D[i-l+i]+72)/10-9;
        D[i]+=i<0 ? 0 : !(o=work(c/10,O,i-1))*((c+999)%10-(D[i]+92)%10);
    }
    return o;
}

int main()
{
    char s[1200];s[0]='0';
    scanf("%s",s+1);
    if(strlen(s)%2 == 1)
        work(2,s+1,0);
    else
        work(2,s,0);
    return 0;
}

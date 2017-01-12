#include<stdio.h>
#include<string.h>
char c,buf[6][100];
int n,j,v;
void input()
{
	scanf("%d",&n);
    getchar();
}
void work()
{
	for(int i=0;i<n;i++)
    {
        j=1;v=0;
        memset(buf,'\0',sizeof(buf));
        while((c=getchar())!='\n')
        {
            if(c=='<' || c=='>')
			{
				j++;
				v=0;
				continue;
			}
            buf[j][v]=c;
            v++;
        }
        fgets(buf[0],sizeof(buf[0]),stdin);
        buf[0][strlen(buf[0])-1]='\0';
        buf[0][strlen(buf[0])-1]='\0';
        buf[0][strlen(buf[0])-1]='\0';
        buf[0][strlen(buf[0])-1]='\0';
        printf("%s%s%s%s%s\n",buf[1],buf[2],buf[3],buf[4],buf[5]);
        printf("%s%s%s%s%s\n",buf[0],buf[4],buf[3],buf[2],buf[5]);
    }
}
int main()
{
    input();
    work();
    return 0;
}

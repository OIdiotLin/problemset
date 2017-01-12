#include<stdio.h>
#include<string.h>
int main()
{
    long i=0,j=0,k=0,t,m;
    char ISBN[200],ch;

    scanf("%s",ISBN);
    for(i = 0;i < strlen(ISBN)-1;i ++)
    {
        if(ISBN[i]!= '-') 
        {
           j ++; 
           k += j * (ISBN[i] - 48 );
        }
    }
    if(ISBN[i] == 'X') t = 10;
    else t = ISBN[i] - 48;
    if(k % 11 == t ) 
    {
      printf("Right");
      return 0;
    }
    for(j = 0;j < strlen(ISBN)-1;j ++)  printf("%c",ISBN[j]);
    if(k % 11 != 10)
      printf("%c",k%11+48);
    else printf("X");
    return 0;
}


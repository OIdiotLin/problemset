#include <cstring>
#include <iostream>
#define LEN 150
using namespace std;
char s[200];
int result[LEN];
int a[LEN],b[LEN],c[LEN],aa[LEN];
int i,j,k,temp,num,n;
bool flag=true;

void multiply(int a[], int b[], int b1, int c[],int c1) 
{
	for(i=0;i<c1;i++)
		c[i]=0;
	if(b1>c1)
		b1=c1;
 
    for(i=0; i<b1; i++)
	{
		if(b[i])
    	{
        	for(j=0; j<c1-i; j++)
        	{
        		c[i+j]=a[j]*b[i]+c[i+j];
        		c[i+j+1]=c[i+j+1]+c[j+i]/10;
        		c[i+j]=c[i+j]%10;
          }
       }
    }
}

void init()
{
	cin>>s>>k;
    n=strlen(s);
    for(i=0;i<n;i++) 
        a[n-i-1]=s[i]-'0';
	for (i=0;i<k;i++)
	  	aa[i]=a[i];
    result[0]=1;
}

void work()
{
	for(i=0;i<k;i++)
	{
		for(j=0;j<=i;j++) b[j]=aa[j];         
			temp=b[i];
		num=0;
		do
		{
			multiply(a, b, i+1, c, i+1);
			num++;
			for(n=0; n<k; n++)  b[n]=c[n];
		}while (num<10 && b[i]!=temp);
		
		if(b[i]!=temp) 
        { 
        	cout<<-1<<endl;
        	flag=false;
			return;
        }
        for(j=0;j<k;j++)            
            b[j]=a[j];
        for(j=0;j<num-1;j++)
        {
			multiply(a,b,k,c,k);
            for(n=0;n<LEN;n++)
				a[n]=c[n];
        }
		multiply(result,&num,1,c,LEN);
        for(n=0; n<LEN; n++)
			result[n]=c[n];
    }
}

void print()
{
	for(i=LEN-1;result[i]==0;i--);
    for(;i>=0;i--)
        cout<<result[i];
}

int main()
{
	init();
	work();
	if(flag)
    {
    	for(i=LEN-1;result[i]==0;i--);
    	for(;i>=0;i--)
        	cout<<result[i];
    }
    return 0;
}  

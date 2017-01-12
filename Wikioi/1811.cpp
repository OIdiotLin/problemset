#include <stdio.h>
#include <string.h> 
const int LEN=1000000; 

void add(char *a,char *b,char *result)
{
      int temp[LEN]={0};
      int i,j,carry=0,len_t=0,len_c=0;
      int len_a=strlen(a);
      int len_b=strlen(b); 
      for(i=len_a-1,j=len_b-1;i>=0&&j>=0;i--,j--)
      {
          temp[len_t++]=(a[i]-'0'+b[j]-'0'+carry)%10;
          carry=(a[i]-'0'+b[j]-'0'+carry)/10; 
      }
      while(i>=0)                          
      {
          temp[len_t++]=(a[i]-'0'+carry)%10;
          carry=(a[i--]-'0'+carry)/10; 
      }
      while(j>=0)                              
      {
          temp[len_t++]=(b[j]-'0'+carry)%10;
          carry=(b[j--]-'0'+carry)/10; 
      }
      if(carry>0)                               
      {
          temp[len_t++]=1; 
      }
      len_t--; 
      while(len_t>=0)                            
      {
          result[len_c++]=temp[len_t--]+'0';
      }     
}

void minus(char *a,char *b,char *result)
{
      int temp[LEN]={0};
      int i,j,borrow=0,len_t=0,len_c=0,flag;
      int len_a=strlen(a);
      int len_b=strlen(b);
      if((len_a>len_b)||((len_a==len_b)&&strcmp(a,b)>=0))
      {
          flag=0;         
      }
      else  
      {
          flag=1;        
          char *t=a;
          a=b;
          b=t; 
      }
      len_a=strlen(a);
      len_b=strlen(b);
      for(i=len_a-1,j=len_b-1;i>=0&&j>=0;i--,j--)
      {
          temp[len_t++]=(a[i]-b[j]-borrow+10)%10;
          if(a[i]-b[j]-borrow<0)
          {
              borrow=1; 	
          }
          else
          {
              borrow=0; 
          } 
      }
      while(i>=0)        
      {
          temp[len_t++]=(a[i]-'0'-borrow+10)%10;
          if(a[i]-'0'-borrow<0)
          {
              borrow=1; 
          }
          else
          {
              borrow=0; 
          }
          i--; 
      } 
      len_t--;
      if(flag==1)           
      {
          result[len_c++]='-'; 
      }
      while(temp[len_t]==0&&len_t>0)       
      {
          len_t--; 
      } 
      while(len_t>=0)                  
      {
          result[len_c++]=temp[len_t--]+'0';
      }     
}

void intadd(char *a,char *b,char *result)
{
     if(a[0]=='-'&&b[0]!='-')             
     {
         minus(b,&a[1],result);  
     }
     else if(a[0]!='-'&&b[0]=='-')           
     {
         minus(a,&b[1],result); 
     }
     else if(a[0]!='-'&&b[0]!='-')     
     {
         add(a,b,result);
     }
     else                                   
     {
         add(&a[1],&b[1],result);
         int lens=strlen(result);
         for(int k=lens-1;k>=0;k--)
         {
            result[k+1]=result[k]; 
         }
         result[0]='-'; 
     }
}

int main()
{
    char a[LEN-1],b[LEN-1],result[LEN];
    while(scanf("%s%s",a,b)!=EOF)
    {
        memset(result,0,sizeof(result));          
        intadd(a,b,result);                        
        printf("%s",result);                      
    }
    return 0; 
}

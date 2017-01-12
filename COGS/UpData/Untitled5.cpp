#include<stdio.h>
#include<string.h>
char a[5050][20];int b[5050];
int find(int x){
    if(b[x]==x)return x;
    else return b[x]=find(b[x]);
}
int main(){
    int m,n,p,i,j,kk,qq;
    char k[20],q[20];
    scanf("%d%d%d\n",&n,&m,&p);
    for(i=1;i<n+1;i++){
       scanf("%s\n",a[i]);
       }
    for(i=1;i<n+1;i++)b[i]=i;
    for(i=1;i<m+1;i++){
       scanf("%s%s\n",k,q);
       for(j=1;j<n+1;j++){
          if(strcmp(a[j],k)==0)kk=j;
          if(strcmp(a[j],q)==0)qq=j;
          }
       int x=find(kk);
       int y=find(qq);
       if(x!=y)b[x]=y;
    }
    for(i=1;i<p+1;i++){
       scanf("%s%s\n",k,q);
       for(j=1;j<n+1;j++){
          if(strcmp(a[j],k)==0)kk=j;
          if(strcmp(a[j],q)==0)qq=j;
          }
       int x=find(kk);
       int y=find(qq);
       if(x==y)printf("safe\n");
       else printf("cc cry\n");
       }
    return 0;
}

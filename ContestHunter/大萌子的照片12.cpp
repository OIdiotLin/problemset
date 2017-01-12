#include <stdio.h>
#include <string.h>
#include <algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;
typedef struct{double x1,y1,x2,y2;}Node;
Node T[10001];
int n;
double a,b,c,d,ans;
bool cmp(Node a,Node b){
     if(a.y2!=b.y2) return a.y2<b.y2;
     if(a.x2!=b.x2) return a.x2<b.x2;
     return a.x1>b.x1;
}
void Cover(double x1,double y1,double x2,double y2,int k,int c)
{
    while(k<n && (x1>=T[k].x2||x2<=T[k].x1||y1>=T[k].y2||y2<=T[k].y1) )
		k++;//???? 
    if(k>=n){ans+=(x2-x1)*(y2-y1); return;}//????
    if(x1<T[k].x1){Cover(x1,y1,T[k].x1,y2,k+1,c);x1=T[k].x1;}
    if(x2>T[k].x2){Cover(T[k].x2,y1,x2,y2,k+1,c);x2=T[k].x2;}
    if(y1<T[k].y1){Cover(x1,y1,x2,T[k].y1,k+1,c);y1=T[k].y1;}
    if(y2>T[k].y2){Cover(x1,T[k].y2,x2,y2,k+1,c);y2=T[k].y2;}
}
int main()
{
	scanf("%d",&n);
    for(int i=0;i<n;i++){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    T[i]=(Node){a,b,c,d};
    }
    ans=0;
    sort(T,T+n,cmp);
    for(int i=n-1;i>=0;i--)
    Cover(T[i].x1,T[i].y1,T[i].x2,T[i].y2,i+1,i);
    printf("%.1lf\n",ans);
    return 0;
}

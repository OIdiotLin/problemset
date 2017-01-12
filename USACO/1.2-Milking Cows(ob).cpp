//????????C++???????????????
/*
ID: 
PROG: milk2
LANG: C++
*/
 
#include<iostream>       
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
 
int n;
const int maxn=5001;
 
int f[maxn];
 
struct node
{
    int begin;
    int end;
    bool operator <(node b)const
    {
        return begin<b.begin;
    }
}a[maxn];
 
 
int main()
{
     //while(~scanf("%d",&n))
    // {
        ofstream fout("milk2.out");
	    ifstream fin("milk2.in");
         fin>>n;
         for(int i=0; i<n; ++i)
         {
           //  scanf("%d%d",&a[i].begin,&a[i].end);
           fin>>a[i].begin>>a[i].end;
         }
         sort(a,a+n);
 
         int last_start,longest_idle_time;
         int longest_continuous_time;
          last_start=a[0].begin;
          f[0]=a[0].end;
          longest_idle_time=0;
          longest_continuous_time=a[0].end-a[0].begin;
        for(int i=1;i<n;++i)
        {
             if(a[i].begin<=f[i-1])
             f[i]=max(f[i-1],a[i].end);
             if(a[i].begin>f[i-1])
             {
                 last_start=a[i].begin;
                 longest_idle_time=max(longest_idle_time,a[i].begin-f[i-1]);
                 f[i]=a[i].end;
             }
             longest_continuous_time=max(longest_continuous_time,f[i]-last_start);
        }
       // printf("%d %d\n",longest_continuous_time,longest_idle_time);
       fout<<longest_continuous_time<<" "<<longest_idle_time<<endl;
 
   //  }
     return 0;
}

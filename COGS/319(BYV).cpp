#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
const int MAXN=1501,MAXM=1001,INF=0x7FFFFFFF;
using namespace std;
struct edge
{
    edge *next;
    int t,w;
}ES[MAXN*2],*V[MAXN];
struct node
{
    node *child[2];
    int size,w[2],c;
}P[MAXN];
int N,M,EC;
int F[MAXN][MAXM];
double As;
inline void addedge(int a,int b,int w)
{
    ES[++EC].next=V[a];
    V[a]=ES+EC; V[a]->t=b; V[a]->w=w;
}
void build(node &p,int f)
{
    int i=&p-P,j;
    p.c=0;
    p.size=1;
    for (edge *e=V[i];e;e=e->next)
    {
        j=e->t;
        if (j==f) continue;
        p.w[p.c]=e->w;
        build(P[j],i);
        p.child[p.c]=P+j;
        p.size += p.child[p.c]->size;
        p.c++;
    }
}
void init()
{
    int i,a,b,c;
    freopen("hole.in","r",stdin);
    freopen("hole.out","w",stdout);
    scanf("%d%d",&N,&M);
    for (i=1;i<=N-1;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c);
        addedge(b,a,c);
    }
    build(P[1],0);
    memset(F,-1,sizeof(F));
}
int dp(int i,int a)
{
    if (F[i][a]==-1)
    {
        int rs,j,k;
        if (a==0)
            rs=0;
        else
        {
            if (P[i].c==0)
            {
                if (a==1)
                    rs=0;
                else
                    rs=INF;
            }
            else if (P[i].c==1)
            {
                rs=(a-1)*(M-(a-1))*P[i].w[0];
                j=P[i].child[0] - P;
                rs+=dp(j,a-1);
            }
            else
            {
                int b=0,ra;
                j=P[i].child[0] - P; k=P[i].child[1] - P;
                if (a - 1 - P[k].size >b)
                    b=a - 1 - P[k].size;
                for (rs=INF;b<=a-1 && b<=P[j].size;b++)
                {
                    ra = dp(j,b) + dp(k,a-1-b);
                    ra += b*(M-b) * P[i].w[0];
                    ra += (a-1-b)*(M-(a-1-b)) * P[i].w[1];
                    if (ra<rs)
                        rs=ra;
                }
            }
        }
        F[i][a]=rs;
    }
    return F[i][a];
}
void solve()
{
    int Ans=dp(1,M);
    double sum=(double)M*(M-1)/2.0;
    As=Ans / sum;
}
int main()
{
    init();
    solve();
    printf("%.2lf\n",As);
    return 0;
}

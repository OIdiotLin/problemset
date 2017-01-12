/*
    Machine: Class4_B2
    System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
#define MAXN (1005)
#define MAXM (500005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
 
inline int getint(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
inline void outputint(int x){
    char ch[12];
    int cnt=0;
    if(x==0) {putchar('0'); putchar(10);return;}
    while(x) ch[++cnt]=x%10,x/=10;
    while(cnt) putchar(ch[cnt--]+48);
    putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
 
double Ans;
double x[MAXN];
int N,M;
int C[MAXN];
 
struct Edge{
    int u,v;
    double w;
    Edge(int _u=0,int _v=0):
        u(_u),v(_v){w=0;}
    void Set_W(int u,int v){
        w=x[u]/double(C[u])+x[v]/double(C[v]);
    }
    bool operator < (const Edge &t)const{
        return w<t.w;
    }
}E[MAXM];
 
struct Matrix{
    double a[MAXN][MAXN];
    int n;
    /*
    void Init_Zero(){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=0;
    }
    */
    Matrix(int _n=0):n(_n){memset(a,0,sizeof(a));}
     
    void Modify(int u,int v){
        a[u][v]=-1.0/C[v];
        a[v][u]=-1.0/C[u];
    }
     
    void Prepare(){ 
        for(int i=1;i<n;i++)
            a[i][i]=1,a[i][n]=0;
        a[n][n]=0,a[1][n]=1;
    }
     
    void Gauss_Elmt(int now){
        /* Working on the now Diagonal Element */
        if(now==n) return;
        /* find the maximum element */
        int PivotR=now;
        for(int i=now+1;i<n;i++)
            if(fabs(a[i][now])>fabs(a[PivotR][now]))
                PivotR=i;
        /* make the maximum element pivot */
        for(int i=now;i<=n;i++)
            swap(a[PivotR][i],a[now][i]);
        /* Eliminating */
        for(int i=now+1;i<n;i++)
            for(int j=n;j>=now;j--)
                a[i][j]-=a[now][j]*a[i][now]/a[now][now];
        Gauss_Elmt(now+1);
        for(int i=now+1;i<n;i++)
            a[now][n]-=a[now][i]*x[i];
        x[now]=a[now][n]/a[now][now];
    }
}A;
 
void init(){
    int u,v;
#ifdef Judge
    freopen("3143.in","r",stdin);
    freopen("3143.out","w",stdout);
//  SpeedUp;
#endif
    read(N),read(M);
    A=Matrix(N);
    for(int i=1;i<=M;i++){
        read(u),read(v);
        C[u]++,C[v]++;
        E[i]=Edge(u,v);
    }
    for(int i=1;i<=M;i++)
        A.Modify(E[i].u,E[i].v);
    A.Prepare();
}
 
void work(){
    double Ans=0.0;
    A.Gauss_Elmt(1);
    for(int i=1;i<=M;i++)
        E[i].Set_W(E[i].u,E[i].v);
    sort(E+1,E+M+1);
    for(int i=1;i<=M;i++)
        Ans+=E[i].w*(M-i+1);
    cout<<fixed<<setprecision(3)<<Ans<<endl;
}
 
int main(){
    init();
    work();
#ifdef Debug
    cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
    cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
    return 0;
}
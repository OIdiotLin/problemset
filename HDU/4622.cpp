/*
    Machine: Class4_B2
    System: Windows7 SP1 32bit
*/
#include <cstdio>
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
#define MAXN (5005)
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

struct Suffix_Automaton{
    struct Node{
        Node *fa,*son[28];
        int step;
        void Init(){
            memset(son,NULL,sizeof(son));
            fa=NULL,step=0;
        }
        Node(){Init();}
        int Calc(){
            return fa ? step-fa->step : 0;
        }
    }a[MAXN<<1],*fst,*fnl;
    int tot,ans;
    
    void Init(){
        fst=fnl=&a[tot=1];
        fst->Init();
        ans=0;
    }
    
    void Add(int x){
        Node *p=fnl,*np=&a[++tot];
        np->Init();
        np->step=p->step+1;
        while(p && !p->son[x]){
            p->son[x]=np;
            p=p->fa;
        }
        if(p==NULL){
            np->fa=fst;
            ans+=np->Calc();
        }
        else if(p->step+1==p->son[x]->step){
            np->fa=p->son[x];
            ans+=np->Calc();
        }
        else{
            Node *q=p->son[x],*nq=&a[++tot];
            nq->Init();
            *nq=*q;
            ans-=p->Calc()+q->Calc();
            nq->step=p->step+1;
            np->fa=q->fa=nq;
            ans+=p->Calc()+q->Calc()+np->Calc()+nq->Calc();
            while(p && p->son[x]==q){
                p->son[x]=nq;
                p=p->fa;
            }
        }
        fnl=np;
    }
}SAM;

int T,Q;
char st[MAXN];
int G[MAXN][MAXN];

void init(){
#ifdef Judge
    freopen("4622.in","r",stdin);
    freopen("4622.out","w",stdout);
//    SpeedUp;
#endif
    scanf("%d",&T);
}

void work(){
    scanf("%s",st+1);
    int len=strlen(st+1),l,r;
    for(int i=1;i<=len;i++){
        SAM.Init();
        for(int j=i;j<=len;j++){
            SAM.Add(st[j]-'a');
            G[i][j]=SAM.ans;
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",G[l][r]);
    }
}

int main(){
    init();
    while(T--)
        work();
#ifdef Debug
    cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
    cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
    return 0;
}
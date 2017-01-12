/*
	Work on OIdiot's PC
	System: Ubuntu 14.04 Kylin
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define Up ios::sync_with_stdio(false)
//#define Judge
//#define Debug
#define MAXN (200002)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
 
int N,K;
int L[MAXN>>1],R[MAXN>>1];
char buff[MAXN];
 
struct Suffix_Automaton{
    struct Node{
        Node *fa,*son[28];
        int step,val,times,last;
        bool vis;
    }a[MAXN<<1],*fst,*fnl;
    int tot;
    Suffix_Automaton(){tot=1,fst=fnl=&a[tot];}
    void Add(int x){
        Node *p=fnl,*np=&a[++tot];
        np->step=p->step+1;
        while(p&&!p->son[x]){ p->son[x]=np; p=p->fa;}
        if(!p) np->fa=fst;
        else if(p->step+1==p->son[x]->step) np->fa=p->son[x];
        else{
            Node *q=p->son[x],*nq=&a[++tot];
            *nq=*q;
            nq->step=p->step+1;
            np->fa=q->fa=nq;
            while(p&&p->son[x]==q){p->son[x]=nq;p=p->fa;}
        }
        fnl=np;
    }
    void Update(Node *t,int x){
        while(t){
            if(t->last==x) return;
            t->times++;
            t->last=x;
            t=t->fa;
        }
    }
    int Calc(Node *t,int x){
        if(t->vis) return t->val;
        if(t->fa) t->val=Calc(t->fa,x);
        if(t->times>=K) {
            int pre=(t->fa?t->fa->step:0);
            t->val+=min(t->step,x)-pre;
        }
        t->vis=true;
        return t->val;
    }
    void work(){
        for(int i=1;i<=N;i++){
            Node *now=fst;
            for(int j=L[i];j<R[i];j++){
                now=now->son[buff[j]-'a'];
                Update(now,i);
            }
        }
        for(int i=1;i<=N;i++){
            int Ans=0;
            Node *now=fst;
            for(int j=L[i];j<R[i];j++){
                now=now->son[buff[j]-'a'];
                Ans+=Calc(now,j-L[i]+1);
            }
            printf("%d ",Ans);
        }
        printf("\n");
    }
 
}Sam;
 
void init(){
#ifdef Judge
    freopen("3277.in","r",stdin);
    freopen("3277.out","w",stdout);
//  SpeedUp;
#endif
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++){
        L[i]=R[i-1]+1;
        scanf("%s",buff+L[i]);
        R[i]=L[i]+strlen(buff+L[i]);
    }
    for(int i=1;i<=N;i++){
        for(int j=L[i];j<R[i];j++)
            Sam.Add(buff[j]-'a');
        Sam.Add(26);
    }
}
 
int main(){
    init();
    Sam.work();
#ifdef Debug
    cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
    cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
    return 0;
}
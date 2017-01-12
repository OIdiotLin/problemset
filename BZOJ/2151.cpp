/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (200005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void outputint(int x){
    char ch[12];
    int cnt=0;
    if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0) {putchar('-'); x=-x;}
    while(x) ch[++cnt]=x%10,x/=10;
    while(cnt) putchar(ch[cnt--]+48);
    putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Node{
    int val;
    bool p;
    Node *pre,*next;
    Node(int _v=0):
        val(_v){p=false;pre=next=NULL;}
    bool operator < (const Node &t)const{
        return val>t.val;
    }
}A[MAXN];

int N,M,Ans;

inline void Con(int u,int v){
    A[u].next=&A[v];
    A[v].pre=&A[u];
}
inline void Del(Node *x){
    x->p=true;
    x->pre->next=x->next;
    x->next->pre=x->pre;
    x->pre=x->next=NULL;
}
struct cmp{
    bool operator ()(int &a,int &b){
        return A[b]<A[a];
    }
};

priority_queue<int,vector<int>,cmp> Q;

void init(){
    int r;
#ifdef Judge
    freopen("2151.in","r",stdin);
    freopen("2151.out","w",stdout);
//  SpeedUp;
#endif
    read(N),read(M);
    if(N<(M<<1)){
        puts("Error!");
        exit(0);
    }
    for(int i=1;i<=N;i++){
        read(r);
        A[i]=Node(r);
    }
    for(int i=1;i<N;i++)
        Con(i,i+1);
    Con(N,1);
#ifdef Debug
    for(int i=1;i<=N;i++)
        print(A[i].val);
#endif
    for(int i=1;i<=N;i++)
        Q.push(i);
}

void work(){
    while(M--){
        while(A[Q.top()].p) Q.pop();
        int k=Q.top();
        Ans+=A[k].val;
        Q.pop();
        A[k].val=A[k].pre->val+A[k].next->val-A[k].val;
        Del(A[k].pre),Del(A[k].next);
        Q.push(k);
    }
    print(Ans);
}

int main(){
    init();
    work();
#ifdef Debug
    cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
    cout<<"Memory Used : "<<(double)(sizeof(A))/1048576<<" MB."<<endl;
#endif
    return 0;
}
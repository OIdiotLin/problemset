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
#define Judge
//#define Debug
#define MAXN (100005)
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

string A,B;
struct Suffix_Automaton{
    struct Node{
        Node *fa,*son[28];
        int step;
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
            memcpy(nq->son,q->son,sizeof(q->son));
            nq->step=p->step+1;
            nq->fa=q->fa;
			np->fa=nq;
			q->fa=nq;
            while(p&&p->son[x]==q){p->son[x]=nq;p=p->fa;}
        }
        fnl=np;
    }
	
	int Solve(string S){
		unsigned int N=S.size();
		int len=0,ret=0;
		Node *cur=fst;
		for(unsigned int i=0;i<N;i++){
			int ch=S[i]-'a';
			if(cur->son[ch])
				++len,cur=cur->son[ch];
			else{
				while(cur && !cur->son[ch]) cur=cur->fa;
				if(!cur) len=0,cur=fst;
				else len=cur->step+1,cur=cur->son[ch];
			}
			ret=max(ret,len);
		}
		return ret;
	}
}Sam;

void init(){
#ifdef Judge
	freopen("longlongmessage.in","r",stdin);
	freopen("longlongmessage.out","w",stdout);
//	SpeedUp;
#endif
	cin>>A;
	for(unsigned int i=0;i<A.size();i++)
		Sam.Add(A[i]-'a');
}

void work(){
	cin>>B;
	cout<<Sam.Solve(B)<<endl;
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
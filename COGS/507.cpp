#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 3000
#define MAXM 8000
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
//#define Debug
using namespace std;

inline int MAX(int a,int b){return (a>b)?a:b;}

struct Str{
	int s[MAXN];
	int len;
};
Str x,S;
int a[MAXM],b[MAXM];
int N; 

void Add(Str A,Str B,Str *c)
{
	int Max;
	Str t;
	memset(t.s,0,sizeof(t.s));
	Max=MAX(A.len,B.len);
	t.len=Max;
	for(int i=1;i<=Max;i++)
		t.s[i]=A.s[i]+B.s[i];
	for(int i=1;i<=Max;i++)
	{
		t.s[i+1]+=t.s[i]/10;
		t.s[i]%=10;
	}
	if(t.s[Max+1])
		t.len++;
	*c=t;
	#ifdef Debug
	cout<<"The S.len = "<<c->len<<endl;
	for(int i=1;i<=c->len;i++)
		cout<<c->s[i]<<" ";
	cout<<endl;
	#endif
}

void Mul(Str A,Str *c)
{
	Str t;
	memset(t.s,0,sizeof(t.s));
	for(int i=1;i<=A.len;i++)
		t.s[i]+=A.s[i]*2;
	t.len=A.len+1;
	for(int i=1;i<=A.len+1;i++)
	{
		t.s[i+1]+=t.s[i]/10;
		t.s[i]%=10;
	}
	while(!t.s[t.len])
		t.len--;
	*c=t;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("savey.in","r",stdin);
//	freopen("savey.out","w",stdout);
	#endif
	cin>>N;
	for(int i=N;i>=1;i--)
		cin>>a[i];
	b[1]=a[1];
	for(int i=2;i<=N;i++)
		b[i]=a[i]^b[i-1];
	S.len=x.len=1;
	S.s[1]=0;x.s[1]=1;
}

void work()
{
	init();
	for(int i=N;i;i--)
	{
		if(b[i]==1)
			Add(x,S,&S);
		Mul(x,&x);
	}
	for(int i=S.len;i;i--)
		cout<<S.s[i];
	cout<<endl;
}

int main()
{
	work();
	return 0;
}


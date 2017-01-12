#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
const int maxn=100005;
struct Node{
       int a,b;
       bool lazy;
};

Node Tree[maxn*4];
int N,M;
void in(int &x)
{
	char t=getchar();
	while(t<'0'||'9'<t) t=getchar();
	for(x=t-'0',t=getchar();'0'<=t&&t<='9';x=x*10+t-'0',t=getchar());
}

void BuiltTree(int id,int l,int r)   //建树，确立区间端点 
{
	int mid=(l+r)>>1;
	Tree[id].a=l;Tree[id].b=r;
	if(l<r)
	{
		BuiltTree((id<<1),l,mid);
		BuiltTree((id<<1)+1,mid+1,r);
	}
}

void change(int id,int l,int r)
{
	int mid=(Tree[id].a+Tree[id].b)>>1;
    if((l<=Tree[id].a&&Tree[id].b<=r)||Tree[id].a==Tree[id].b)
    {
        Tree[id].lazy=(!Tree[id].lazy);
        return;
    }
    if(Tree[id].lazy)       //lazy下放 
    {
        Tree[id].lazy=false;
        Tree[(id<<1)].lazy=(!Tree[(id<<1)].lazy);
        Tree[(id<<1)+1].lazy=(!Tree[(id<<1)+1].lazy);
    }
    if(!(r<Tree[(id<<1)].a||Tree[(id<<1)].b<l)) //递归处理左右儿子 
	    change((id<<1),l,r);
    if(!(r<Tree[(id<<1)+1].a||Tree[(id<<1)+1].b<l)) 
	    change((id<<1)+1,l,r);
}

int getans(int id,int i)
{
    int t=0;
    while(Tree[id].a)   //迭代，从根节点走到叶子节点 
    {
        if(Tree[id].lazy) 
		    t++;
		if(i<=Tree[(id<<1)].b)   //去左儿子 
		    id<<=1;
		else                     //去右儿子 
		    id=(id<<1)+1;
    }
    return t&1;
}

void init()
{
	in(N);in(M);
    BuiltTree(1,1,N);
}

void out(int x)
{
	x?putchar('1'):putchar('0');
	putchar('\n');
}

void solve()
{
    for(int i=1;i<=M;i++)
    {
    	int p,l,r;
    	in(p);
        if(p==1)
        {
        	in(l);in(r);
            change(1,l,r);
        }
        else 
        {
        	in(l);
        	out(getans(1,l));
        }
    }
}
int main()
{	
    init();
    solve();
    return 0;
}

#include <iostream>

using namespace std;

int n,e,x,y,z,num,sum,st,en;
int head[105],tail[105],value[105],next[105],ans[105];
int q[105],pp[105],in[105],out[105],node[105],flag[105],u[105];

void make(int a,int b,int c)
{
    num++;
    head[num]=a;
    tail[num]=b;
    value[num]=c;
    next[num]=pp[a];
    pp[a]=num;
    in[b]++;
    out[a]++;
}

void topological()				//拓扑排序 
{
    int taill=0,head=0;
    for(int i=1;i<=n;i++)
        if(!in[i])			//提取出没有入度的节点 
        {
            q[++taill]=i;
        }
    while(head<taill)
    {
        int k=q[++head];
        int p=pp[k];
        while(p>0)
        {
            int kk=tail[p];
            in[kk]--;
            node[kk]+=value[p]*node[k];
            if(!in[kk])
            {
                q[++taill]=kk;
                node[kk]-=u[kk];
                if(node[kk]<0)
                    node[kk]=0;
            }
            p=next[p];
        }
    }
}

int main()
{
	cin>>n>>e;
	for(int i=1;i<=n;i++)
		cin>>node[i]>>u[i];
	for(int i=1;i<=e;i++)
	{
		cin>>x>>y>>z;
		make(x,y,z);
	}
	for(int i=1;i<=n;i++)
	{
		if(out[i]==0)
			ans[i]=i;
	}
	
    topological();
    
    int count=0;
    for(int i=1;i<=n;i++)
    {
		if(ans[i]!=0)
        {
            if(node[i]>0)
            {
                count++;
                cout<<i<<" "<<node[i]<<endl;
            }
        }
    }
    if(count==0)
		cout<<"NULL"<<endl;
    return 0;
}

#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 705
#define LHD 100		//The width is below 100
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

int N,M,C;
int Ans;
int G[MAXN][MAXN];

struct Queue{
	int s[MAXN*2];			//queue;
	int ex[MAXN];
	int head,tail;
	bool non_empty()const{
		return head<=tail;
	}
	void push(int a,bool k){
		while(non_empty() && (!k ? ex[s[tail]]>ex[a] : ex[s[tail]]<ex[a]))
			tail--;
		s[++tail]=a;
	}
}Max,Min;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("land.in","r",stdin);
	freopen("land.out","w",stdout);
	#endif
	cin>>N>>M>>C;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++){
			cin>>G[i][j];
		}
	Ans=0;
}

void work(){
	for(int i=0;i<N;i++){		//enumerate the row 
		for(int j=0;j<M;j++)
			Min.ex[j]=Max.ex[j]=G[j][i];
		for(int j=i+1;j<N && j-i<LHD;j++){
			for(int k=0;k<M;k++){
				Min.ex[k]=min(Min.ex[k],G[k][j]);
				Max.ex[k]=max(Max.ex[k],G[k][j]);
			}
			Min.head=Max.head=0;
			Min.tail=Max.tail=-1;
			int wd=j-i+1;
			for(int t=0,h=0;t<M&&(M-h)*wd>Ans;t++){
				#ifdef Debug
				cout<<"Min Heap: ";
				#endif
				Min.push(t,0);
				Max.push(t,1);
				while(h<=t && Min.non_empty() && Max.non_empty() && Max.ex[Max.s[Max.head]]-Min.ex[Min.s[Min.head]]>C){
					h++;
					while(Max.non_empty() && Max.s[Max.head]<h)
						Max.head++;
					while(Min.non_empty() && Min.s[Min.head]<h)
						Min.head++;
				}
				Ans=max(Ans,wd*(t-h+1));
			}
		}
	}
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


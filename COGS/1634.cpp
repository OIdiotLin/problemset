#include <iostream>
#include <cstring>
#include <ctime>
#include <stack>
#include <algorithm>
#include <cstdio>
#define MAXN 10005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;
typedef long long LL;

struct Point{
	double x,y;
};

struct StrLine {
	int k,b;
	int P;
	bool operator < (const StrLine &r)const{
		if(k<r.k) return true;
		if(k==r.k) return b>r.b;
		return false;
	}
	bool operator == (const StrLine &r)const{
		return k==r.k && b==r.b;
	}
	double Calc(const double x)const {
		return k*x+b;
	}
	Point Cross(const StrLine &r)const{
		double x=(double)(r.b-b)/(double)(k-r.k);
		return (Point){x,Calc(x)};
	}
}L[MAXN];

int N;

void init()
{

	#ifdef FILE
	SpeedUp;
	freopen("race1.in","r",stdin);
	freopen("race1.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>L[i].b;
	for(int i=1;i<=N;i++)
		cin>>L[i].k;
	for(int i=1;i<=N;i++)
		L[i].P=i;

	sort(L+1,L+N+1);
	#ifdef Debug
	cout<<"After Ranking: "<<endl;
	for(int i=1;i<=N;i++){
		cout<<"Car "<<i<<": v="<<L[i].k<<" b="<<L[i].b<<endl;
	}
	#endif
}

stack<int> S;
bool check(Point p){
	int t=S.top();
	S.pop();
	bool flag=L[S.top()].Calc(p.x)>p.y;
	S.push(t);
	return flag;
}
int D[MAXN],Ans[MAXN];
void work(){
	for(int i=1;i<=N;i++){
		if(!S.empty() && L[S.top()].k==L[i].k) continue;
		while(!S.empty()){
			Point p=L[i].Cross(L[S.top()]);
			if(p.x<0)
				S.pop();
			else if(S.size()>1 && check(p))
				S.pop();
			else break;
		}
		S.push(i);
	}
	
	int M=S.size();
	for(int i=1;i<=M;i++){
		D[M-i+1]=S.top();
		S.pop();
	}
	int cnt=0;
	for(int i=1;i<=M;i++){
		for(int j=D[i];j<=N && L[j]==L[D[i]];j++)
			Ans[++cnt]=L[j].P;
	}
	cout<<cnt<<endl;
	sort(Ans+1,Ans+cnt+1);
	/*
	for(int i=1;i<=cnt;i++)
		cout<<Ans[i]<<" ";
	cout<<endl;
	*/
	for(int i=1;i<cnt;i++)
		cout<<Ans[i]<<" ";
	cout<<Ans[cnt]<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(L))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


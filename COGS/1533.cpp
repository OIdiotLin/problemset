#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN ((1<<15)+5)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

struct TNode{
	int Val;
	int Origin,Last,Next;
	TNode(){
		Last=Next=0;
	}
	bool operator < (TNode b)const {
		return Val<b.Val;
	}
}List[MAXN];

void Delete(int x){
	List[List[x].Last].Next=List[x].Next;
	List[List[x].Next].Last=List[x].Last;
}

int Calc(int x){
	int last=abs(List[x].Val-List[List[x].Last].Val);
	int next=abs(List[x].Val-List[List[x].Next].Val);
	return min(last,next);
}

int N,Ans;
int A[MAXN],O[MAXN];
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("turnover.in","r",stdin);
	freopen("turnover.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	A[0]=A[1];A[N+1]=INF;
	for(int i=1;i<=N;i++){
		List[i].Val=A[i];
		List[i].Origin=i;
	}
	sort(List+1,List+N+1);
	for(int i=1;i<=N;i++){		//Record the Orginal Order
		O[List[i].Origin]=i;
	}
	for(int i=1;i<N;i++){		//Make List connected
		List[i].Next=i+1;
	}
	for(int i=2;i<=N;i++){
		List[i].Last=i-1;
	}
	List[0].Val=INF;
	#ifdef Debug
	cout<<"After Initialization: "<<endl;
	for(int i=1;i<=N;i++){
		cout<<"Day "<<List[i].Origin<<"\t Value is "<<List[i].Val<<endl
			<<"    Its Last is Day "<<O[List[i].Last]<<endl
			<<"    Its Next is Day "<<O[List[i].Next]<<endl;
	}
	#endif
}

void work(){
	for(int i=N;i>=2;i--){
		Ans+=Calc(O[i]);
		#ifdef Debug
		cout<<"The Min Fluctuating Value On Day "<<O[i]<<" is "<<Calc(O[i])<<endl;
		#endif
		Delete(O[i]);
	}
	Ans+=A[1];
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(List)+sizeof(A)+sizeof(O))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


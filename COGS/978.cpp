#include <iostream>
#include <cstring>
#include <ctime>
#include <stack>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
#define Debug
using namespace std;

stack<char> Q;
string S;
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("encrypta.in","r",stdin);
	freopen("encrypta.out","w",stdout);
	#endif
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		Q.push(s[i]);
	}
	cin>>S;
}

void work(){
	while(!Q.empty()){
		switch (Q.top()){
			case 'A':{
				string t=S;
				string A;
				for(int i=S.length()-1;i>=0;i--)
					A+=t[i];
				S=A;
				break;
			}
			case 'C':{
				char t=S[0];
				for(int i=S.length()-2;i>=0;i--)
					S[i]=S[i+1];
				S[S.length()-1]=t;
				break;
			}
			case 'E':{
				if(S.length()%2==0){
					string A,B;
					for(int i=0;i<S.length()/2;i++){
						A+=S[i];
					}
					for(int i=S.length()/2+1;i<S.length();i++){
						B+=S[i];
					}
					S=A+B;
				}
				break;
			}
			case 'J':{
				char t=S[S.length()-1];
				for(int i=1;i<S.length();i++)
					S[i]=S[i-1];
				S[0]=t;
				break;
			}
			case 'M':{
				for(int i=0;i<S.length();i++){
					if(isdigit(S[i]))
						if(S[i]>='0'&&S[i]<='8')	S[i]++;
						else S[i]='0';
				}
				break;
			}
			case 'P':{
				
				for(int i=0;i<S.length();i++){
					if(isdigit(S[i]))
						if(S[i]>='1'&&S[i]<='9')	S[i]--;
						else S[i]=9;
				}
				break;
			}
		}
		#ifdef Debug
		cout<<"Operate "<<Q.top()<<endl<<"\t"
			<<S<<endl;
		#endif
		Q.pop();
	}
	cout<<S<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(Q))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


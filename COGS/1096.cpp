#include <iostream>
#include <cstdio>
#define FILE
using namespace std;

bool is_odd(string st)
{
	char ch=st[st.size()-1];
	if(ch=='0'||ch=='2'||ch=='4'||ch=='6'||ch=='8')
		return false;
	return true;
}

void work()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		string Num;
		cin>>Num;
		cout<<(is_odd(Num) ? "odd" : "even")<<endl;
	}
}

int main()
{
	#ifdef FILE
	freopen("evenodd.in","r",stdin);
	freopen("evenodd.out","w",stdout);
	#endif
	work();
	return 0;
}

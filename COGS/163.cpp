#include <iostream>
#include <cstring>
#define FILE
using namespace std;

bool Vowel(string buf)
{
	if(buf[0]=='a'|| buf[0]=='e'|| buf[0]=='i'|| buf[0]=='o'|| buf[0]=='u')
		return true;
	return false;
}

string Trans(string buf)
{
	string Ans=buf;
	if(Vowel(buf))
	{
		Ans=buf+"cow";
	}
	else
	{
		int len=buf.size();
		Ans[len-1]=buf[0];
		for(int i=0;i<len-1;i++)
			Ans[i]=buf[i+1];
		Ans+="ow";
	}
	return Ans;
}

int main()
{
	freopen("latin.in","r",stdin);
	freopen("latin.out","w",stdout);
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string IN;
		cin>>IN;
		cout<<Trans(IN)<<endl;
	}
	return 0;
}

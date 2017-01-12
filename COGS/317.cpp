#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 255
#define INF (-(1<<30))
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

const string Name="WING";
int hash[MAXN],Repl[4],S[4][4*4],T[4][4*4];
string s;
bool f[MAXN][MAXN][4],d[MAXN][MAXN][4];

bool find(int i,int j,int c)
{
	if(d[i][j][c])
		return f[i][j][c];
	d[i][j][c]=true;
	if(i==j)
	{
		f[i][j][c]=(s[i]==Name[c]);
		return f[i][j][c];
	}
	for(int p=i;p<j;p++)
		for(int q=0;q<Repl[c];q++)
			if(find(i,p,S[c][q]) && find(p+1,j,T[c][q]))
			{
				f[i][j][c]=true;
				return true;
			}
	return false;
}
void init()
{
	char Ori,Targ;
	SpeedUp;
	#ifdef FILE
	freopen("name.in","r",stdin);
//	freopen("name.out","w",stdout);
	#endif
	for(int i=0;i<4;i++)
		hash[(int)Name[i]]=i;
	for(int i=0;i<4;i++)
		cin>>Repl[i];
	for(int i=0;i<4;i++)
		for(int j=0;j<Repl[i];j++)
		{
			cin>>Ori>>Targ;
			S[i][j]=hash[(int)Ori];
			T[i][j]=hash[(int)Targ];
			#ifdef Debug
			cout<<"S["<<i<<"]["<<j<<"] = "<<S[i][j]<<" refer to "<<Ori<<endl;
			cout<<"T["<<i<<"]["<<j<<"] = "<<T[i][j]<<" refer to "<<Targ<<endl;
			#endif
		}
	cin>>s;
	#ifdef Debug
	cout<<"s = "<<s<<endl;
	cout<<"Name = "<<Name<<endl;
	cout<<"----------------data Reading Suc!--------------------"<<endl;
	#endif
}

void work()
{
	bool flag=false;
	for(int i=0;i<4;i++)
		if(find(0,s.length()-1,i))
		{
			cout<<Name[i];
			flag=true;
		}
	if(!flag)
	{
		cout<<"The name is wrong!"<<endl;
		return;
	}
	cout<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#define MAXN 30
#define INF 1<<30
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug

using namespace std;

string data;
int chr[MAXN],f[MAXN];
int cnt,time;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("1079.in","r",stdin);
	//freopen("1079.out","w",stdout);
	#endif
}

void init_Huff()
{
	memset(chr,0,sizeof(chr));
	memset(f,0,sizeof(f));
	cnt=0;
	for(int i=0;i<data.length();i++)
	{
		#ifdef Debug
		cout<<"operate: "<<data[i]<<endl;
		#endif 
		if(data[i]=='_')
			chr[27]++;
		else
			chr[(int)(data[i]-'A'+1)]++;
	}
	#ifdef Debug
	cout<<"Changed Successfully!"<<endl;
	#endif
	for(int i=1;i<=27;i++)
		if(chr[i])
		{
			f[0]++;
			f[f[0]]=chr[i];
		}
	for(int i=1;i<f[0];i++)
		for(int j=i+1;j<=f[0];j++)
			if(f[i]>f[j])
				swap(f[i],f[j]);
	if(f[0]==1)
		cnt=f[1];
	time=f[0]-1; 
}

void Huff()
{
	init_Huff();
	while(time)
	{
		cnt+=f[1]+f[2];
		f[2]+=f[1];
		f[1]=INF;
		for(int i=1;i<f[0];i++)
			for(int j=i+1;j<=f[0];j++)
				if(f[i]>f[j])
					swap(f[i],f[j]);
		f[0]--;
		time--;
	}
}

void work()
{
	while(1)
	{
		cin>>data;
		if(data=="END")
			return ;
		#ifdef Debug
		cout<<"Reading Success!   To be continued."<<endl
			<<"The string is: "<<data<<endl;
		#endif
		cout<<data.length()*8<<" ";
		Huff();
		cout<<cnt<<" "<<fixed<<setprecision(1)<<(double)data.length()*8/cnt<<endl;
	}
}


int main()
{
	init(); 
	work();
	return 0;
}


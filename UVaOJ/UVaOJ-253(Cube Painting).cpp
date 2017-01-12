#include<iostream>
#include<cstring>

using namespace std;

char CubeStatus[13];
bool is_visual[3];

int main()
{
	int cnt;
	while (cin>>CubeStatus)
	{
		memset(is_visual,false,sizeof(is_visual));
		cnt=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if((CubeStatus[i]==CubeStatus[6+j]&&CubeStatus[5-i]==CubeStatus[11-j]||CubeStatus[i]==CubeStatus[11-j]&&CubeStatus[5-i]==CubeStatus[6+j])&&!is_visual[j])
				{
					cnt++;
					is_visual[j]=true;
					break;
				}
		if(cnt==3)
			cout<<"TRUE"<<endl;
		else 
			cout<<"FALSE"<<endl;
	}
	return 0;
}

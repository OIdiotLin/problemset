#include <iostream>
#include <cstring> 
using namespace std;
int main()
{
	int Case=0,num,height[101];
	while(cin>>num && num!=0)
	{
		int stepSum=0,total=0;
		memset(height,0,sizeof(height));
		for(int i=0;i<num;i++)
		{
			cin>>height[i];
			total+=height[i];
		}
		int k=total/num;
		for(int i=0;i<num;i++)
			if(height[i]>k)
				stepSum+=(height[i]-k);
		Case++;
		cout<<"Set #"<<Case<<endl;
		cout<<"The minimum number of moves is "<<stepSum<<"."<<endl<<endl;
    }
	return 0;
}

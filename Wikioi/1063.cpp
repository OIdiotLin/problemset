#include<iostream>
using namespace std;
void Rank(int *,int);
			
int main()
{
	int n,sum=0;	//n是堆数，sum是体力总量
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	Rank(a,n);
			//先排序
	int i=1;			
	int k=n;			//k来保存n的值
	while(n!=1)
	{	
		sum+=a[i]+a[i-1];	//当前耗费的体力
		a[i]=a[i]+a[i-1];	
		i++;				//a[i]代表最近一次合并的堆的果子数目
		n--;		//堆数少了1
		Rank(a,k);	//还要再排一次续，保证序列始终是从小到大的，这为了简便，还是按n个数排序
	}
	cout<<sum<<"Hint"<<endl;
	delete []a;
}

void Rank(int *s,int n)			//将数列从小到大排序（冒泡）
{
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			if(s[i]>s[j])
			{
				int temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
}

#include<iostream>
using namespace std;
void Rank(int *,int);
			
int main()
{
	int n,sum=0;	//n�Ƕ�����sum����������
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	Rank(a,n);
			//������
	int i=1;			
	int k=n;			//k������n��ֵ
	while(n!=1)
	{	
		sum+=a[i]+a[i-1];	//��ǰ�ķѵ�����
		a[i]=a[i]+a[i-1];	
		i++;				//a[i]�������һ�κϲ��ĶѵĹ�����Ŀ
		n--;		//��������1
		Rank(a,k);	//��Ҫ����һ��������֤����ʼ���Ǵ�С����ģ���Ϊ�˼�㣬���ǰ�n��������
	}
	cout<<sum<<"Hint"<<endl;
	delete []a;
}

void Rank(int *s,int n)			//�����д�С��������ð�ݣ�
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

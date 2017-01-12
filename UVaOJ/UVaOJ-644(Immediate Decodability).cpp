/*
	Name: Immediate Decodability
	Copyright: UVaOJ-644
	Author: LHD
	Date: 21/11/13 13:04
	Description: ͨѶ�еı��뷽ʽ��Ҫ��ÿ���ַ���Ӧ�Ķ����Ʊ��룬
				 �����������ַ���Ӧ�����ǰ׺��
				 ���ڼ�����뷽ʽ������Ƿ���С�
	Analysis: �ж�ÿ���ַ����Ƿ��������ַ�����ǰ׺���ɡ��������ĳ���ַ����������ַ�����ǰ׺������벻���С�
			  ע��: ��a.length()���Ի�ȡ�ַ���a�ĳ��ȣ�����������<string>��. 
*/
#include <cstdio>
#include <iostream>
#include <string>
#define MAXN 100000
using namespace std;
string str[MAXN];
bool judge(string x, string y)
{
	for(int i=0;i<x.length();i++)
		if(x[i]!=y[i])
			return false;
	return true;
}

int main()
{
	int count=0,now=0;
	while (cin>>str[now])
	{
		if (str[now]=="9")		//����'9'ʱ�ж��� 
		{
			bool flag=false;
			for (int i=0; i<now; i++)						//�ж��� 
				for (int j=0; j<now; j++)
  					if (i!=j&&judge(str[i],str[j]))
						flag=true;
			printf("Set %d is %simmediately decodable\n", ++count, flag ? "not " : "");			//������Ԫ��������ٴ����� 
			now=0;
		}
		else
		{
			now++;
			//printf("now=%d\n",now);
		}
	}
	return 0;
}

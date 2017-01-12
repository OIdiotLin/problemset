/*
	Name: Immediate Decodability
	Copyright: UVaOJ-644
	Author: LHD
	Date: 21/11/13 13:04
	Description: 通讯中的编码方式，要求每个字符对应的二进制编码，
				 不能是其他字符对应编码的前缀。
				 对于几组编码方式，检查是否可行。
	Analysis: 判断每个字符串是否是其他字符串的前缀即可。如果存在某个字符串是其他字符串的前缀，则编码不可行。
			  注意: 用a.length()可以获取字符串a的长度，它被定义在<string>里. 
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
		if (str[now]=="9")		//读入'9'时判定。 
		{
			bool flag=false;
			for (int i=0; i<now; i++)						//判定！ 
				for (int j=0; j<now; j++)
  					if (i!=j&&judge(str[i],str[j]))
						flag=true;
			printf("Set %d is %simmediately decodable\n", ++count, flag ? "not " : "");			//利用三元运算符减少代码量 
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

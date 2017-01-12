#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Rank(char c)
{
	switch(c)
	{
		case '{':return -3;
		case '[':return -2;
		case '(':return -1;
		case ')':return 1;
		case ']':return 2;
		case '}':return 3;
		default:return 0;
	}
}

bool judge(string buf)
{
	stack<char> bracket;
	for(int i=0;i<buf.size();i++)
	{
		if(bracket.empty())			//Ñ¹ÈëµÚÒ»¸ö×Ö·û 
			bracket.push(buf[i]);
		else if(!bracket.empty())		//Õ»·Ç¿Õ 
		{
			if(Rank(buf[i])<0)		//×óÀ¨ºÅ 
				bracket.push(buf[i]);
			else					//ÓÒÀ¨ºÅ 
			{
				if(Rank(buf[i]) + Rank(bracket.top())==0)	//¶ÔÓ¦À¨ºÅ
					bracket.pop();
			}
		}
	}
    if(!bracket.empty())			//Õ»ÖĞÈÔÁôÓĞÔªËØ 
        return false;
	return true;
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string input;
		cin>>input;
		if(judge(input))
			cout<<"TRUE"<<endl;
		else
			cout<<"FALSE"<<endl;
	}
	return 0;
}

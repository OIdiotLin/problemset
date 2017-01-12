/*
	Step１:任选一个正整数Ａ作为这个数列的第一项。
	Step２:如果Ａ＝１则停止。
	Step３:如果Ａ为偶数，则Ａ＝Ａ／２然后重新回到Step２。
	Step４:如果Ａ为奇数，则Ａ＝３*Ａ＋１然后重新回到Step２。
Sample Input
	3 100
	34 100
	75 250
	27 2147483647
	101 304
	101 303
	-1 -1
Sample Output
	Case 1: A = 3, limit = 100, number of terms = 8
	Case 2: A = 34, limit = 100, number of terms = 14
	Case 3: A = 75, limit = 250, number of terms = 3
	Case 4: A = 27, limit = 2147483647, number of terms = 112
	Case 5: A = 101, limit = 304, number of terms = 26 
	Case 6: A = 101, limit = 303, number of terms = 1
*/

#include <iostream>
using namespace std;
long long A,limit;
int CaseNum;

bool even(long long N)
{
	if(N%2)
		return false;
	return true;
}

void work(long long a,long long l)
{
	long long term=0,t=a;
	while(a<=l&&a!=1)
	{
		if(even(a))
			a/=2;
		else if(!even(a))
			a=a*3+1;
		term++;
	}
	if(a==1)
		term++;
	cout<<"Case "<<++CaseNum<<": A = "<<t<<", limit = "<<l<<", number of terms = "<<term<<endl;
}

int main()
{
	while((cin>>A>>limit) && (A!=-1||limit!=-1))
	{
		work(A,limit);
	}
	return 0;
}

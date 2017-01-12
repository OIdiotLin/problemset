#include<iostream>
#include<string>
using namespace std;

string input;
int main()
{
    int n;
    cin>>n;
    while(n--)
	{
		cin>>input;
		if(input.size()<=2)
            cout<<'+';
		else if(input[input.size()-2]=='3' && input[input.size()-1]=='5')
            cout<<'-';
        else if(input[0] == '9' && input[input.size() - 1] == '4')
            cout<<'*';
        else
			cout<<'?';
        cout<<endl;
    }
    return 0;
}

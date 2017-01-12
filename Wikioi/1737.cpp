#include <iostream>
using namespace std;
int main()
{
    int n,c,s;
    char b[100000+1];
    cin>>n;
    cin>>c;
    for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	    cin>>s;   
	    if(b[i]=='+')
	    	c+=s;
	    if(b[i]=='-')
	    	c-=s;
	    if(b[i]=='*')
	    	c*=s;
	    if(b[i]=='/')
	    	c/=s;
	    if(b[i]=='%')
	    {
			if(s!=0)
				c%=s;   
	      	else
	    	{
				cout<<"Error!";
				return 0;
			}
		}
    }
	cout<<c<<endl;
    return 0;
}

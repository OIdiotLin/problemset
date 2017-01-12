#include<iostream>
using namespace std;
int n,ans;
int catche;
int a[11];
int main()
{
	catche=30;
	for(int i=1;i<=10;i++)
		cin>>a[i];
	cin>>n; catche+=n;
    for(int i=1;i<=10;i++)
		if(a[i]<=catche)
			ans++;
    cout<<ans<<endl;
    return 0;
}

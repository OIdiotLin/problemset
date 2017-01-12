#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
long long n,i;
cout<<"Please input a integer\n";
cin>>n;
if(n <= 0)
{
cout<<"Your input is not larger than 0.\n";
exit(-1);
}
cout<<n<<"=";
while(n % 2 == 0 && n != 2)
{
cout<<"2*";
n /= 2;
}
long long val = sqrt(n);
for(i = 3; i <= val; i += 2)
{
while(val >= i)
{
if(n % i == 0)
{
cout<<i<<'*';
n /= i;
val = sqrt(n);
}
else
break;
}
}
cout<<n<<endl;
return 0;
}

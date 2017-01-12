#include<iostream>
using namespace std;

int Power(long a, long b, long c)
{
    long ans=1;
    a=a%c;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=(ans*a)%c;
        }
        b=b/2;
        a=(a*a)%c;
    }
    return ans;
}

int main()
{
    long A,B,C;
    while(cin>>A>>B>>C)
    {
        int Re;
        Re=Power(A,B,C);
        cout<<A<<'^'<<B<<" mod "<<C<<'='<<Re<<endl;
    }
    return 0;
}

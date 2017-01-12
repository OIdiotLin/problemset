#include <iostream>
using namespace std;
int main() 
{    
    int x,y,Case; 
    cin>>Case; 
    while(Case--) 
    { 
        cin>>x>>y; 
        cout<<(int)(x/3)*(y/3)<<endl; 
    }
    return 0; 
}

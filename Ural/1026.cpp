#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

vector<int> A;

int main(){
    string Cut;
    int N,x;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>x;
        A.push_back(x);
    }
    cin>>Cut;
    sort(A.begin(),A.end());
    cin>>N;
    for(int i=0;i<N;i++){
cin>>x;
cout<<A[x-1]<<endl;
}
    return 0;
}

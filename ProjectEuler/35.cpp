/* 
    The number, 197, is called a circular prime because all rotations of the digits:  
    197, 971, and 719, are themselves prime. 
    There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97. 
    How many circular primes are there below one million? 
*/  
#include <Windows.h>  
#include <iostream>  
#include <vector>  
#include <list>  
using namespace std;  
typedef unsigned long DWORD;  
const DWORD size = 1000000;  
bool prime[size] = {false};  
vector<DWORD> primes;  
const int pow[] = {1,1,10,100,1000,10000,100000,100000};  
bool IsPrime(long long int n)    
{    
    if (n==1) return false;  
    if (n==2) return true;  
    if(n%2==0) return false;    
    long long int hd=8;    
    long long int lg=6;      
    long long int lh=8;     
    long long int va=n-1;    
    while(va>=hd)    
    {    
        if(!((va-hd)%lg)) return false;    
        lh+=8;    
        lg+=4;    
        hd+=lh;                    
    }    
    return true;    
}    
bool Problem35(size_t N)  
{  
      
    list<int> lcp;   //circular prime  
    int tmp = N;  
    int sum = 0;  
    while (tmp!=0)  
    {  
        int p = tmp % 10;  
        if (p%2==0 || p%5==0)  
            return false;  
        lcp.push_front(p);  
        sum += p;  
        tmp /= 10;  
        if (tmp == 0)  
        {  
            list<int> copy(lcp.begin(), lcp.end());  
            lcp.insert(lcp.end(),copy.begin(), copy.end());  
            //cp.insert(cp.end(),cp.begin(),cp.end());  
        }  
    }  
    if (sum%3==0)  
        return false;  
      
    const int digit = lcp.size()/2;  
    vector<int> vcp(lcp.begin(), lcp.end());  //circular prime copy  
    for (int t=1; t<digit; t++)  
    {  
        int cPrime = 0;  
        for (int c=t; c<digit+t; c++)   
        {  
            cPrime += vcp[c] * pow[digit+t-c];  
        }  
        if (!prime[cPrime])  
            return false;  
    }  
    cout << N << endl;  
    return true;  
      
}  
int main()  
{  
    DWORD start = GetTickCount();  
    for (int n=1; n<size; n++)  
    {  
        if (IsPrime(n))  
        {  
            primes.push_back(n);  
            prime[n] = true;  
        }  
    }  
    vector<int> c;  
    for (int N=1; N < primes.size(); N++)  
    {  
        if (primes[N]<100)  
            continue;  
        if (Problem35(primes[N]))  
            c.push_back(primes[N]);  
    }  
    cout << c.size()+13 << endl;  
    DWORD end = GetTickCount();  
    cout << "the running time = " << end - start << " ms." << endl;  
    return 0;  
}  

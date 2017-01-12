#include<iostream>
using namespace std;

struct diag{
	int x;
	int y;
	int N;
};

diag Diagonal;

bool odd(int N)
{
	if(N%2)
		return true;
	else
		return false;
}

int main()
{
    int n,x,y;
    while(cin>>n,n)
	{
        Diagonal.N=1;
        Diagonal.x=1;
        while(true)
		{
			Diagonal.N=Diagonal.N+2*(Diagonal.x-1);//Diagonal.N表示对角线上的数，Diagonal.x表示Diagonal.N的横坐标
	    	if(n>Diagonal.N && n<=Diagonal.N+(Diagonal.x-1))
			{
	        	if(!odd(Diagonal.x))
				{
	                x=Diagonal.x;
	                y=Diagonal.x-(n-Diagonal.N);
	            }
	            else
				{
	            	x=Diagonal.x-(n-Diagonal.N);
	                y=Diagonal.x; 
	            }
	            break;
	        }
	        else if(n<Diagonal.N&&n>=Diagonal.N-(Diagonal.x-1))
			{
	            if(!odd(Diagonal.x))
				{
	                x=Diagonal.x-(Diagonal.N-n);
	                y=Diagonal.x;
	            }
	            else
				{
	                x=Diagonal.x;
	                y=Diagonal.x-(Diagonal.N-n);   
	            } 
	            break;
	        }
	        else if(n==Diagonal.N)
			{
	            x=y=Diagonal.x;		//对角线 
	            break;
	        }
	        Diagonal.x++;
    	}
        cout<<x<<" "<<y<<endl;        
    }
    return 0;    
}


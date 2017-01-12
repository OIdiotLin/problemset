/*
ID: MagicLin
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    static int ans[10];
    int np,i,j,p,present,num;
    string names[10],recept,give;
    fin>>np;
    for(i=0;i<np;i++)
		fin>>names[i];
    for(i=0;i<np;i++)
	{
        fin>>give>>present>>num;
        for(p=0;names[p]!=give;p++);
        if(num!=0)
			ans[p]=ans[p]-(present-present%num);
        else ans[p]-=present;
        for(j=0;j<num;j++)
		{
        	fin>>recept;
            for(p=0;names[p]!=recept;p++);
            	ans[p]+=present/num;
        }
    }
    for(i=0;i<np;i++)
		fout<<names[i]<<' '<<ans[i]<<endl;
    return 0;
}

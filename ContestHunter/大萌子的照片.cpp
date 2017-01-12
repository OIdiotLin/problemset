#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN=10001;
struct Square{
	double x1,y1;
	double x2,y2;
}M[MAXN];

int N;
double Ans,r1,r2,r3,r4;

bool comp(Square a,Square b)
{
	if(a.y2!=b.y2)
		return a.y2<b.y2;
	if(a.x2!=b.x2)
		return a.x2<b.x2;
	return a.x1>b.x1;
}

void init()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>r1>>r2>>r3>>r4;
		M[i]=(Square){r1,r2,r3,r4};
	}
	Ans=0;
	sort(M,M+N,comp);
}

void Union(double x1,double x2,double y1,double y2,int t,int r)
{
	while(t<N && (x1>=M[t].x2||x2<=M[t].x1||y1>=M[t].y2||y2<=M[t].y1))
		t++;
		
	if(t>=N)
	{
		Ans+=(x2-x1)*(y2-y1);
		return;
	}
	if(x1<M[t].x1)
	{
		Union(x1,y1,M[t].x1,y2,t+1,r);
		x1=M[t].x1;
	}
	if(x2>M[t].x2)
	{
		Union(M[t].x2,y1,x2,y2,t+1,r);
		x2=M[t].x2;
	}
    if(y1<M[t].y1)
	{
		Union(x1,y1,x2,M[t].y1,t+1,r);
		y1=M[t].y1;
	}
    if(y2>M[t].y2)
	{
		Union(x1,M[t].y2,x2,y2,t+1,r);
		y2=M[t].y2;
	}
}
void Cover(double x1,double y1,double x2,double y2,int k,int c)
{
    while(k<N && (x1>=M[k].x2||x2<=M[k].x1||y1>=M[k].y2||y2<=M[k].y1) )
		k++;//???? 
    if(k>=N){Ans+=(x2-x1)*(y2-y1); return;}//????
    if(x1<M[k].x1){Cover(x1,y1,M[k].x1,y2,k+1,c);x1=M[k].x1;}
    if(x2>M[k].x2){Cover(M[k].x2,y1,x2,y2,k+1,c);x2=M[k].x2;}
    if(y1<M[k].y1){Cover(x1,y1,x2,M[k].y1,k+1,c);y1=M[k].y1;}
    if(y2>M[k].y2){Cover(x1,M[k].y2,x2,y2,k+1,c);y2=M[k].y2;}
}
void Cal()
{
	for(int i=N-1;i>=0;i--)
		Cover(M[i].x1,M[i].y1,M[i].x2,M[i].y2,i+1,i);
}

int main()
{
	init();
	Cal();
	cout<<fixed<<setprecision(1)<<Ans<<endl;
	return 0;
}

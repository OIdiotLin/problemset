#include <iostream>
#include <string>

using namespace std;

bool flag,already;
int m,n,p,x,c1,f1,t1,total,guilty,g,d,i;
string name[25],s;
int c[100],f[100],t[100],h[20];

int find_name(string st)
{
	for(int i=1;i<=m;i++)
		if(name[i]==st)
			return i;
}

int pos(char F,string buf)
{
	for(int i=0;i<strlen(buf);i++)
		if(buf[i]==F)
			return i+1;
	return -1;
}

int find_day(string st)
{
	switch(st)
	{
		case "Monday.":return 1;
		case "Tuesday.":return 2;
		case "Wednesday.":return 3;
		case "Thursday.":return 4;
		case "Friday.":return 5;
		case "Saturday.":return 6;
		case "Sunday.":return 7;
		default: return 0;
	}
}

void work()
{
	int i,max=m,min=0,is;
	memset(h,0,sizeof(h));
	for(i=1;i<=total;i++)
	{
		switch(c[i])
		{
			case 1:if(t[i]==g) is=1; else is=-1;
			case 2:if(t[i]==g) is=-1; else is=1;
			case 3:if(t[i]==d) is=1; else is=-1;
		}
		if(is+h[f[i]]==0)
			return;
		if(h[f[i]]==0)
			if(is==1)
				max--;
			else
				min++;
		if(max<n || min>n)
			return;
		h[f[i]]=is;
	}
	if(already)
	{
		cout<<"Cannot Determine";
		return;
	}
	flag=true;
	already=true;
	guilty=g;
}

void init()
{
	cin>>m>>n>>p;
	for(i=1;i<=m;i++)
		cin>>name[i];
	for(i=1;i<=p;i++)
	{
		t1=0;
		cin>>s;
		x=pos(':',s);
		if(!x)
			continue;
	}	
}



















#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#define MAXN 150
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

char Base_Equation[MAXN],Ask_Equation[MAXN];
char Base_Elem[MAXN][MAXN],Ask_Elem[MAXN][MAXN];
int Coeff[MAXN],Coeff_Ask[MAXN],Length,Length_A;
bool flag;

void Quick_Sort(int a[],int s,int t)
{
	int i=s,j=t,r0;
	char r[MAXN];
	strcpy(r,Base_Elem[i]);
	r0=a[i];
	while(i<j)
	{
		while(i<j && strcmp(Base_Elem[j],r)>=0)
			j--;
		a[i]=a[j];
		strcpy(Base_Elem[i],Base_Elem[j]);
		while(i<j && strcmp(Base_Elem[i],r)<=0)
			i++;
		a[j]=a[i];
		strcpy(Base_Elem[j],Base_Elem[i]);
	}
	a[i]=r0;
	strcpy(Base_Elem[i],r);
	if(s<i-1)
		Quick_Sort(a,s,i-1);
	if(j+1<t)
		Quick_Sort(a,j+1,t);
}

void Process(char s[],int x,int y,int t)
{
	int i=x,j,Sum=0,temp;
	char tmp[MAXN];
	bool p;
	while(isdigit(s[i]))
		Sum=Sum*10+s[i++]-'0';
	if(i==x)
		Sum=1;
	Sum*=t;
	while(i<=y)
	{
		if(s[i]=='(')
		{
			int Bracket=1;
			x=i;
			while(Bracket)
			{
				i++;
				if(s[i]=='(')
					Bracket++;
				else if(s[i]==')')
					Bracket--;
			}
			Bracket=i++;
			temp=0;
			while(i<=y && isdigit(s[i]))
				temp=temp*10+s[i++]-'0';
			if(temp==0)
				temp=1;
			Process(s,x+1,Bracket-1,Sum*temp);
			continue;
		}
		x=i++;
		while(i<=y && !isupper(s[i]) && s[i]!='(')
			i++;
		memset(tmp,0,sizeof(tmp));
		for(j=x;j<i;j++)
		{
			if(isalpha(s[j]))
				tmp[j-x]=s[j];
			else 
				break;
		}
		while(j<i && s[j]==')')
			j++;
		temp=0;
		while(j<i && isdigit(s[j]))
			temp=temp*10+s[j++]-'0';
		if(temp==0)
			temp=1;
		p=false;
		for(j=0;j<Length_A;j++)
		{
			if(!strcmp(tmp,Base_Elem[j]))
			{
				p=true;
				break;
			}
		}
		if(p)
			Coeff[j]+=Sum*temp;
		else
		{
			Coeff[Length_A]=Sum*temp;
			strcpy(Base_Elem[Length_A],tmp);
			#ifdef Debug
			cout<<"\tThere are "<<Coeff[Length_A]<<" "<<tmp<<endl;
			#endif
			Length_A++;
		}
	}
}

void Make(char s[])
{
	int i=0,j;
	while(s[i])
	{
		j=i++;
		while(s[i] && s[i]!='+')
			i++;
		Process(s,j,i-1,1);
		while(s[i] && s[i]=='+')
			i++;
	}
	Quick_Sort(Coeff,0,Length_A-1);

}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("chem.in","r",stdin);
	//freopen("chem.out","w",stdout);
	#endif
	cin>>Base_Equation;
	memset(Coeff,0,sizeof(0));
	memset(Base_Elem,0,sizeof(0));
	Length_A=0;
}

void work()
{
	int N;
	Make(Base_Equation);

	for(int i=0;i<Length_A;i++)
	{
		Coeff_Ask[i]=Coeff[i];
		strcpy(Ask_Elem[i],Base_Elem[i]);
	}
	Length=Length_A;
	cin>>N;
	while(N--)
	{
		memset(Coeff,0,sizeof(Coeff));
		memset(Base_Elem,0,sizeof(Base_Elem));
		Length_A=0;
		cin>>Ask_Equation;
		Make(Ask_Equation);

		flag=true;
		if(Length_A!=Length)
			flag=false;
		else
			for(int i=0;i<Length_A;i++)
			{
				if(Coeff[i]!=Coeff_Ask[i] || strcmp(Base_Elem[i],Ask_Elem[i]))
				{
					flag=false;
					break;
				}
			}
		if(flag)
			cout<<Base_Equation<<"=="<<Ask_Equation<<endl;
		else
			cout<<Base_Equation<<"!="<<Ask_Equation<<endl;
		#ifdef Debug
		cout<<"-------------------------------------------------------------------"<<endl;
		#endif
	}
}

int main()
{
	init();
	work();
	return 0;
}


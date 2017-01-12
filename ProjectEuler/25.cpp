#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define BigN_MAXN 1010
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;


struct BigN{
	int Len,s[BigN_MAXN];
	
	BigN(){
		memset(s,0,sizeof(s));
		Len=1;
	}
	
	BigN(int num){
	*this=num;
	}
	
	BigN(const char*num){
	*this=num;
	}
	
	BigN operator = (int num){
		char s[BigN_MAXN];
		sprintf(s,"%d",num);
		*this=s;
		return *this;
	}
	
	BigN operator = (const char *num){
		Len=strlen(num);
		for(int i=0;i<Len;i++)
			s[i]=num[Len-i-1]-'0';
		return *this;
	}
	
	string str()const{
		string res="";
		for(int i=0;i<Len;i++)
			res=(char)(s[i]+'0')+res;
		if(res=="")
			res="0";
		return res;
	}
	
	BigN operator + (const BigN &b)const{
		BigN c;
		c.Len=0;
		for(int i=0,g=0;g||i<max(Len,b.Len);i++){
			int x=g;
			if(i<Len)
				x+=s[i];
			if(i<b.Len)
				x+=b.s[i];
			c.s[c.Len++]=x%10;
			g=x/10;
		}
		return c;
	}
	
	void clean(){
		while(Len>1&&!s[Len-1])
			Len--;
	}
	
	BigN operator * (const BigN &b){
		BigN c;
		c.Len=Len+b.Len;
		for(int i=0;i<Len;i++)
			for(int j=0;j<b.Len;j++)
				c.s[i+j]+=s[i]*b.s[j];
		for(int i=0;i<c.Len-1;i++){
			c.s[i+1]+=c.s[i]/10;
			c.s[i]%=10;
		}
		c.clean();
		return c;
	}
	
	BigN operator - (const BigN &b){
		BigN c;
		c.Len=0;
		for(int i=0,g=0;i<Len;i++){
			int x=s[i]-g;
			if(i<b.Len)x-=b.s[i];
			if(x>=0)
				g=0;
			else{
				g=1;
				x+=10;
			}
			c.s[c.Len++]=x;
		}
		c.clean();
		return c;
	}
	
	/*BigN operator / (const BigN &b){
		BigN c;
	}*/
	
	bool operator < (const BigN &b)const{
		if(Len!=b.Len)
			return Len<b.Len;
		for(int i=Len-1;i>=0;i--)
			if(s[i]!=b.s[i])
				return s[i]<b.s[i];
		return false;
	}
	
	bool operator > (const BigN &b)const{
		return b<*this;
	}
	
	bool operator <= (const BigN &b){
		return !(b>*this);
	}
	
	bool operator == (const BigN &b){
		return !(b<*this)&&!(*this<b);
	}
	
	BigN operator += (const BigN &b){
		*this=*this+b;
		return *this;
	}
};

istream &operator >> (istream &in,BigN &x){
	string s;
	in>>s;
	x=s.c_str();
	return in;
}

ostream &operator << (ostream &out,const BigN &x){
	out<<x.str();
	return out;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

void work()
{
	BigN A=1,B=1,C,cnt=2;
	while(1){
		cnt+=1;
		C=A+B;
		A=B;
		B=C;
		if(C.Len==1000){
			cout<<cnt<<endl;
			return;
		}
	}
}

int main()
{
	work();
	return 0;
}
 

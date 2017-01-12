#include <iostream>
using namespace std;
int main()
{
	int Va,Vb,S,Vd;
	cin>>S>>Va>>Vb>>Vd;
	cout<<Vd*(S/(Va+Vb))<<endl;
	return 0;
}

program sss;
 var a,s:integer;
 function abc(n:integer):longint;
  var i,m:integer;
   begin
    m:=o;
    for i:=1 to n do
    if n mod i=o then m:=m+1;
    abc:=m;
   end;
begin
 s:=0;
 for a:=1 to 1000000 do
 s:=s+abc(n);
 write(s);
end.

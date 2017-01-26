program vijos1061;
var
 m,n,i,j,k:longint;
 h:array[1..5000] of longint;
 f:array[0..5000,0..1000] of longint;
function min(i,j:longint):longint;
begin
 if i<j then
  exit(i);
 exit(j);
end;
begin
 readln(m,n);
 for i:=n downto 1 do
  read(h[i]);
 readln;
 for i:=1 to n do
  for j:=1 to m do
   f[i,j]:=1000000000;
 for k:=1 to m do
  for i:=3*k to n do
   f[i,k]:=min(f[i-1,k],f[i-2,k-1]+sqr(h[i]-h[i-1]));
 writeln(f[n,m]);
end.
	

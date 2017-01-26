type sj=record
      s:array[1..5000]of longint;
      len:longint;
     end;
var b,a:array[1..10100]of longint;
    n,i,j:longint;
    x,sum:sj;
procedure setio;
begin
assign(input,'save.in');
assign(output,'save.out');
reset(input);
rewrite(output);
end;
procedure print;
begin
close(input);
close(output);
end;
procedure add(a,b:sj; var c:sj);
var i,max:longint;
    d:sj;
begin
fillchar(d.s,sizeof(d.s),0);
max:=a.len; if b.len>a.len then max:=b.len;
for i:=1 to max do
d.s[i]:=a.s[i]+b.s[i];
d.len:=max;
for i:=1 to max do
begin
   d.s[i+1]:=d.s[i+1]+d.s[i] div 10;
   d.s[i]:=d.s[i] mod 10;
end;
if d.s[max+1]>0 then inc(d.len);
c:=d; 
end; 
procedure mul(a:sj; var c:sj);
var i:longint; d:sj;
begin
    fillchar(d.s,sizeof(d.s),0);
    for i:=1 to a.len do
      d.s[i]:=d.s[i]+a.s[i]*2;
for i:=1 to a.len+1 do
begin
   d.s[i+1]:=d.s[i+1]+d.s[i] div 10;
   d.s[i]:=d.s[i] mod 10;
end;
d.len:=a.len+1;
while d.s[d.len]=0 do dec(d.len);
c:=d;
end;
begin
setio;
readln(n);
for i:=n downto 1 do read(a[i]);
b[1]:=a[1];
for i:=2 to n do
b[i]:=a[i] xor b[i-1];//格雷码解码成二进制
sum.len:=1; sum.s[1]:=0;
x.s[1]:=1; x.len:=1;
for i:=n downto 1 do
begin
   if b[i]=1 then add(x,sum,sum);
   mul(x,x);
end; //二进制转十进制
for i:=sum.len downto 1 do write(sum.s[i]);
        writeln;
print;
end.
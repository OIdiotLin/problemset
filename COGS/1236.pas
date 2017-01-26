const
  maxn=1000;
  maxpos=30000;
  inputfile='juxing.in';
  outputfile='juxing.out';
var
  n,i,ans:integer;
  p:array[1..maxn]of record
                       a,x,y:integer;
                     end;
  can:array[1..maxn]of boolean;
function equal(a,b:real):boolean;
  begin
    equal:=abs(a-b)<1E-7;
  end;
function crash(k:real;p1x,p1y,p2x,p2y:integer;var minx:real):boolean;
  var x,y:real;
  begin
    if p1x=p2x then begin
       y:=k*p1x;
       if equal(y,p1y) or equal(y,p2y) or (p2y>y) and (y>p1y) then begin
          if p1x<minx then begin
             minx:=p1x;
             crash:=true;
          end else crash:=false;
       end else crash:=false;
    end
    else begin
           x:=p1y/k;
           if equal(x,p2x)
              then crash:=false
              else if equal(x,p1x) or (p1x<x) and (x<p2x) then
                      if x<minx then begin
                         minx:=x;
                         crash:=true
                      end else crash:=false
                   else crash:=false;
         end;
  end;
procedure check(x,y:integer);
  var k,minx:real;
      no,i:integer;
  begin
    k:=y/x;
    minx:=maxpos;
    no:=0;
    for i:=1 to n do
      if p[i].x<minx then
         if not crash(k,p[i].x,p[i].y,p[i].x,p[i].y+p[i].a,minx)
         then if crash(k,p[i].x,p[i].y,p[i].x+p[i].a,p[i].y,minx)
                 then no:=i
                 else
         else no:=i;
    if no>0 then can[no]:=true;
  end;
begin
  assign(input,inputfile);
  reset(input);
  read(n);
  for i:=1 to n do read(p[i].x,p[i].y,p[i].a);
  close(input);
  fillchar(can,sizeof(can),0);
  for i:=1 to n do begin
    check(p[i].x+p[i].a,p[i].y);
    if not can[i] then check(p[i].x,p[i].y+p[i].a);
  end;
  ans:=0;
  for i:=1 to n do
    if can[i] then inc(ans);
  assign(output,outputfile);
  rewrite(output);
  writeln(ans);
  close(output);
end.

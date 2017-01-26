const   infns                   = 'numgame.in';
        outfns                  = 'numgame.out';
        maxn                    =  50;
var     m, n                    :  byte;
        max, min                :  longint;
        a                       :  array[0 .. maxn] of longint;
        last, now               :  array[1 .. maxn, 1 .. maxn] of longint;

procedure out;
  begin
    assign(output, outfns);
    rewrite(output);
    writeln(min);
    writeln(max);
    close(output)
  end;  { end of out }

function  sum(i, j : byte) : longint;
  begin
    if i <= j then sum := a[j] - a[i-1]
              else sum := a[n] - a[i-1] + a[j];
  end;  { end of sum }

procedure catch(kind : byte;  var  ans : longint);
var  i, j1, j, k1, k, l     : integer;
     best, dis              : longint;
  begin
    case kind of
      0 : dis := maxlongint;
      1 : dis := -1;
    end;
    for i := 1 to n do
      for j := 1 to n do last[i,j] := dis;
    for i := 1 to n do last[i,i] := 1;
    
    for l := 1 to m - 1 do
      begin
        for i := 1 to n do
          for j := 1 to n do 
		  	now[i,j] := dis;
        for i := 1 to n do
          for j1 := i + l - 1 to n + i - 1 do
            begin
              j := (j1 - 1) mod n + 1;
              for k1 := i + l - 1 to j1 do
                begin
                  k := (k1 - 1) mod n + 1;
                  if (last[i,k] = -1) or (last[i,k] = maxlongint) then continue;
                  best := sum(k, j);
                  best := (10 + best mod 10) mod 10;
                  best := last[i,k] * best;
                  case kind of
                    0 : if best < now[i,j] then now[i,j] := best;
                    1 : if best > now[i,j] then now[i,j] := best;
                  end;
                end;{k1}
            end;{i}
        last := now;
      end;
    case kind of
      0 :  ans := maxlongint;
      1 :  ans := 0;
    end;
    for i := 1 to n do
      for j := 1 to n do
        if (i <> j) and (now[i,j] <> maxlongint) and (now[i,j] <> -1) then
          begin
            best := sum(j mod n + 1, (i+n-2) mod n+1);
            best := (10 + best mod 10) mod 10;
            best := now[i,j] * best;
            case kind of
              0 : if best < ans then ans := best;
              1 : if best > ans then ans := best;
            end;
          end
  end;  { end of catch }

procedure main;
var  ans                : longint;
  begin
    catch(0, ans);
    min := ans;
    catch(1, ans);
    max := ans;
  end;  { end of main }

procedure init;
var  i, x               : integer;
  begin
    assign(input, infns);
    reset(input);
    readln(n, m);
    fillchar(a, sizeof(a), 0);
    for i := 1 to n do
      begin
        readln(x);
        a[i] := a[i-1] + x;
      end;
    close(input);
  end;  { end of init }

begin
  init;
  main;
  out;
end.

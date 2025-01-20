const fi = '8hau.inp';
     fo = '8hau.out';
var bc , bp , c : array[1..1000000] of boolean;
    f1,f2:text;
    n,kq,i,j,x:longint;
procedure dathau(i:integer);
  begin 
       for j:=1 to 8 do
        begin
             if not(c[j]) and not(bc[i-j]) and not(bp[i+j]) then
             begin
                  x[i]:=j;
                  c[j]=true;
                  bc[i-j]:=true;
                  bc[i+j]:=true;
                  if i=8 then inc(x);
                  else dathau(i+1);
                  bp[i+j]:=false;
                  bc[i-j]:=false;
                  c[i]:=false;
             end;
        end;
  end;                

Begin
  assign(f1,fi); reset(f1);
  assign(f2,fo); rewrite(f2);
  write(f2,x);
  close(f1);
  close(f2);
End.
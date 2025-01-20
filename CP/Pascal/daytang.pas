var n , i , ln , d: longint;
    A , B: array [1..100000000] of longint;
    f1 , f2 : text;

Begin

  assign(f1,'daytang.inp');reset(f1);
  assign(f2,'daytang.out');rewrite(f2);
  readln(f1,n);
  for i := 1 to n do read(f1,a[i]);

  if n = 1 then write(f2,'1')
  else if n > 1 then 
  begin
    b[1] := 1;
    for i := 2 to n do 
    begin
       if a[i-1] <= a[i] then b[i] := b[i-1] + 1
       else b[i] := 1;
    end;      
    d := b[1];
    for i := 2 to n do 
      if b[i] > d then d :=b[i];
    write(f2,d);
  end;

  close(f1);
  close(f2);
End.

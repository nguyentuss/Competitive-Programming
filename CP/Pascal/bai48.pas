const fi = 'bai48.inp';
      fo = 'bai48.out';

var f1,f2:text;
    t,x:array[0..10001] of longint;
    i:int32;
    ck,bd,kt,a,n:int64;

Begin
   assign(f1,fi); reset(f1);
   assign(f2,fo); rewrite(f2);
   read(f1,a,n);
   t[a] := 1;
   x[1] := a;
   for i := 2 to 10000 do
      begin
         a := (a * a) mod 10000;
         x[i] := a;
         if t[a] <> 0 then
            begin
               bd := t[a];
               kt := i;
               break;
            end;
         t[a] := i;
      end;
   if n >= bd then
      begin
         ck := kt - bd;
         n := bd + (n - bd) mod ck;
      end;
   write(f2,x[n]);
   close(f1); 
   close(f2);
End.
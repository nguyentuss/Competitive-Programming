const fi='cong.inp';
      fo='cong.out';
var n,k,m:int64;
    i,j,o:int32; 
    A:array[0..10000000] of int64;
    f1,f2:text;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n,k);
   i:=0;
   while n>0 do
        begin
           inc(i);
           a[i]:=((n mod 10)+(k mod 10)) mod 10;
           k:=k div 10;
           n:=n div 10;
        end;
   j:=i;o:=0; 
   for i:=1 to j do 
      if a[i]=0 then inc(o);
    if j = o then write(f2,'0')
    else
      for i:=i downto 1 do write(f2,a[i]);
   close(f1);
   close(f2);
End.

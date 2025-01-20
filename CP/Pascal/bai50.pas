uses math;
const fi='bai50.inp';
      fo='bai50.out';
var n,m,j,i:int64;
    f1,f2:text;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   m:=0;
   while n <> m do   
      begin
         while m < n do
            begin
               inc(j);
               inc(m,j);
            end;
         while m > n do
            begin
               inc(i);
               dec(m,i);
            end;
      end;
   write(f2,n,'=',i+1,'+...+',j);
   close(f1);
   close(f2);
End.
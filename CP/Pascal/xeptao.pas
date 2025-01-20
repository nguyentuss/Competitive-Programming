uses math;
const fi='xeptao.inp';
      fo='xeptao.out';
var A:array[1..2*1000000] of char;
    ch:char;
    n,dem:int64;
    i:int32;
    f1,f2:text;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   dem:=0;
   n:=n*2;
   for i:=1 to n do read(f1,a[i]);
   if a[1]='0' then ch:='1' 
   		else ch:='0';
   for i:=2 to n do 
   		if (a[i]=ch) and (a[i-1]=ch) then inc(dem);
   write(f2,dem);
   close(f1);
   close(f2);
End.
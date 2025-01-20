const fi = 'bai03.inp';
      fo = 'bai03.out';
var x,y:array[1..10000000] of double;
    s,max:double;
    i,j,n:longint;
	f1,f2:text;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   max:=0;
   for i:=1 to n do readln(f1,x[i],y[i]);
   for i:=1 to n - 1 do 
   begin
   	  for j:=i+1 to n do 
   	  begin
   	  	 s:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
         if max < s then max:=s; 
   	  end;
   end;
  write(f2,max/2:0:3);
  close(f1);
  close(f2);
End.
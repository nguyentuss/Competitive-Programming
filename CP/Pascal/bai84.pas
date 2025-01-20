const fi='bai84.inp';
      fo='bai84.out';
var max,i,j,u,n:longint;
    x:array[1..100000000] of longint;
    f1,f2:text;
function ucln(a,b:longint):longint;
begin
	if (a mod b = 0) then exit(b)
	else 
	begin
		exit(ucln(b,a mod b));
	end;
end;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   max:=0;
   for i:=1 to n do read(f1,x[i]);
   for i:=1 to n-1 do
     for j:=i + 1 to n do 
   	 begin
   	    	u:=(x[i]*x[j]) div (ucln(x[i],x[j]));
        	if max < u then max:=u;
     end;
   write(f2,max);
   close(f1);
   close(f2);
End.


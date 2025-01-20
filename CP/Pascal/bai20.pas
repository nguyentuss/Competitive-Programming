uses math;
const fi='bai20.inp';
	  fo='bai20.out'; 
var n,i,j,dem:longint;
    td:real; 
    f1,f2:text;
    x,y,r:array[1..100000] of longint;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   dem:=0;
   for i:=1 to n do readln(f1,x[i],y[i],r[i]);
   for i:=1 to n-1 do
   		begin
   		   for j:=i+1 to n do
   		   		if (i <> j) then 
   		   			begin
   		   			   td:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
   		   			   if (td<r[i]+r[j]) then inc(dem);
   		   		    end;
   		end;
   write(f2,dem);
   close(f1);
   close(f2);
End.

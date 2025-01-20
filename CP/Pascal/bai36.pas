uses math;
const fi='bai36.inp';
      fo='bai36.out';
var n:int64;
    f1,f2:text;
function daonguoc(n:int64):int64;
var m:int64;
	begin
	   m:=0;
	   while (n>0) do 
	   		begin
	   			m:=(m*10) + n mod 10;
	   			n:=n div 10;
	   		end;
	   	exit(m);
	end;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   daonguoc(n);
   Repeat
      n:=n+daonguoc(n);
   Until n=daonguoc(n);
   write(f2,n);
   close(f1);
   close(f2);
End.

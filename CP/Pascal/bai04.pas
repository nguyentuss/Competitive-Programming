uses math;
const fi='bai04.inp';
	  fo='bai04.out';
var T:array[1..10000000] of double;
	s,ans:double;
	i,j,n,vt:longint;
	x,y:array[0..100] of int64;
	f1,f2:text;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   vt:=0;ans:=1e6;
   for i:=1 to n do readln(f1,x[i],y[i]);
   for i:=1 to n do 
   	  begin
   	  	  for j:=1 to n do 
   	  	  	begin
   	  	       if i <> j then 
   	  	  		   t[i]:=t[i]+(sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])));
   	  	    end;
   	  	  if t[i] < ans then
   	  	  		begin
   	  	  			ans:=t[i];
   	  	  			vt:=i;
   	  	  		end;
   	  end;
   write(f2,vt,' ',ans:0:3);
   close(f1);close(f2);
End. 
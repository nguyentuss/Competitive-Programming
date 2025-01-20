uses math;
const fi='bai47.inp';
      fo='bai47.out';
var n,i,m,j:longint;
    s1,s2,b,c:int64;
    f1,f2:text;
	a:array[1..100000000] of int64;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   close(f1);
   j:=0;
   for i:=1 to n do 
   		if n mod i = 0 then 
   			begin
   			   inc(j);
   			   a[j]:=i;
   			end;
   m:=a[1];s1:=0;s2:=0;
   for i:=2 to j do 
   		begin
   		    b:=a[i];
   		    c:=m;
   			while (c>0) do 
   				begin
   					s1:=s1+(c mod 10);
   					c:=c div 10;
   				end;
   			while (b>0) do
   				begin
   					s2:=s2+(b mod 10);
   					b:=b div 10; 
   				end;
   			if s2 > s1 then m:=a[i]
   			else if s1 = s2 then
   				if a[i] < m then m:=a[i];
   			s1:=0;s2:=0;
   		end;
   write(f2,m);
   close(f2);
End.	
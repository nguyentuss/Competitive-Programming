uses math;
const fi='bai19.inp';
      fo='bai19.out';
var n,i,s,j,tam:integer;
    f1,f2:text;
    d,t:array[1..100000] of integer;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   for i:=1 to n do readln(f1,t[i],d[i]);
   for i:=1 to n do 
   		for j:=i+1 to n do
   			if t[i]>t[j] then 
   				begin
   				 	tam:=t[i];
   				 	t[i]:=t[j];
   				 	t[j]:=tam;
   				 	tam:=d[i];
   				 	d[i]:=d[j];
   				 	d[j]:=tam;
   				 end;	
   for i:=1 to n do 
   		begin
   		    if s < t[i] then s:=t[i];
 			s:= s+d[i];
   		end;
   write(f2,s);
   close(f1);
   close(f2);
End.
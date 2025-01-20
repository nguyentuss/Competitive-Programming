uses math;
const fi='bai69.inp';
	  fo='bai69.out';
var f1,f2:text;
	l,r,s,dem,i,j:longint;
	a:array[1..100000000] of longint;	
Begin
	assign(f1,fi);reset(f1);
	assign(f2,fo);rewrite(f2);
	readln(f1,l,r);
	s:=1;
	for i:=l to r do 
		begin
		   if i > 1 then
		   begin 
		   for j:=2 to round(sqrt(i)) do
		   		if i mod j = 0 then 
		   			begin
		   			   s:=s+j;
		   			   if (i div j) <> j then s:=s+(i div j);
		   			end;
		   if s > i then inc(dem);
		   s:=1;
		   end;
		end;		
	write(f2,dem);
	close(f1);
	close(f2);
End.
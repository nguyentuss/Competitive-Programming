uses math;
const fi='bai54.inp';
	  fo='bai54.out';
var f1,f2:text;
	y,x,a,b,s:int64;
	kt:Boolean;
Begin
	assign(f1,fi);reset(f1);
	assign(f2,fo);rewrite(f2);
	readln(f1,y);
	kt:=false;
	x:=y;
	while (kt = false) do
		begin
		   dec(y);
		   b:=y;
		   a:=b;
		   s:=0;
		   while b > 0 do 
		   		begin
		   			s:=s+(b mod 10);
		   			b:=b div 10;	
		   		end;	
		    if (a+s=x) then 
		   		begin
		   		   write(f2,a);
		   		   kt:=true;
		   		   break;
		   		end; 
		end;	
	close(f1);
	close(f2);
End.

var n:Integer;
	i,j:longint;
	s:int64;
	f1,f2:text;
Begin
	assign(f1,'bai34.inp');reset(f1);
	assign(f2,'bai34.out');rewrite(f2);
	readln(f1,n);
	s:=0;
	for i:=1 to n do 
		begin
			for j:=0 to i do 
			begin
				s:=s+i+j;
			end;
		end;
    write(f2,s);
    close(f1);
    close(f2);
End.

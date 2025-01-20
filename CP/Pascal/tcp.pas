var n , s , i : longint;
	a : array[1..1000000] of longint;
	f1 ,f2 : text;
Begin
	assign(f1,'tcp.inp');reset(f1);
	assign(f2,'tcp.out');rewrite(f2);

	readln(f1,n);
	for i := 1 to n do 
	begin
		read(f1,a[i]);
		if frac(sqrt(a[i]))= 0 then s := s + a[i];
	end;

	write(f2,s);

	close(f1);
	close(f2);
	
End.
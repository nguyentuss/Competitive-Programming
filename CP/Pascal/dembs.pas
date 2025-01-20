var n : integer;
	i , dem , j : longint;
	a : array [1..1000] of longint;
	f1 , f2 : text;

Begin

	assign(f1,'dembs.inp');reset(f1);
	assign(f2,'dembs.out');rewrite(f2);

	readln(f1,n);
		for i := 1 to n do read(f1,a[i]);

	dem := 0; 
	for i := 1 to n - 1 do 
		begin
			for j := i + 1 to n  do 
			if (a[i] mod a[j] = 0) or (a[j] mod a[i] = 0) then inc(dem);
		end;

	write(f2,dem);

	close(f1);
	close(f2);

End.

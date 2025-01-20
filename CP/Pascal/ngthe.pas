var n : byte;
	i , j , dem : longint;
	a : array [1..100] of longint;
	f1 , f2 : text;

Begin

	assign(f1,'ngthe.inp');reset(f1);
	assign(f2,'ngthe.out');rewrite(f2);
	readln(f1,n);
	for i := 1 to n do read(f1,a[i]);

	write(f2,'0 ');

	dem := 0;
	for i := 2 to n do 
	begin
		for j := (i - 1) downto 1 do
			if a[i] < a[j] then inc(dem);  
		write(f2,dem,' ');
		dem := 0;
	end;

	close(f1);
	close(f2);

End.

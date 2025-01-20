var n , i , max: longint;
	f1 , f2 : text;
	a : array [1..1000000] of longint;
Begin

	assign(f1,'maxabs.inp');reset(f1);
	assign(f2,'maxabs.out');rewrite(f2);
	readln(f1,n);
	for i := 1 to n do read(f1,a[i]);

	max := a[1];

	for i := 2 to n do 
		if abs(max) < abs(a[i]) then max := a[i];

	write(f2,max);

	close(f1);
	close(f2);

End.
	
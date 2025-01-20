var n : integer;
	i : longint;
	max : int64;
	a : array[1..1000] of int64;
	f1,f2:text;

function ucln(a,b : int64) : int64;
begin
	if a mod b = 0 then exit(b)
	else exit(ucln(b,a mod b));
end;
Begin

	assign(f1,'tucln.inp');reset(f1);
	assign(f2,'tucln.out');rewrite(f2);

	readln(f1,n);

	for i := 1 to n do read(f1,a[i]);

	max := ucln(a[1],a[2]);
	for i := 3 to n - 1 do max := ucln(max,a[i+1]);

	write(f2,max);

	close(f1);
	close(f2);

End.



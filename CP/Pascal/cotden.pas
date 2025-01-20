var m , n , bcnn , t , x: longint;
	f1 , f2 : text;

function ucln(a,b:int64):int64;
begin
	if a mod b = 0  then exit(b)
	else exit(ucln(b,a mod b));
end;
Begin

	assign(f1,'cotden.inp');reset(f1);
	assign(f2,'cotden.out');rewrite(f2);
	readln(f1,m,n);

	bcnn := (m*n) div ucln(m,n);

	write(f2,(bcnn div m) + 1);

	close(f1);
	close(f2);

End. 
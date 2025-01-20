var n , hc , kq: int64;
	tp : real;
	f1 , f2 : text;

Begin

	assign(f1,'socp.inp');reset(f1);
	assign(f2,'socp.out');rewrite(f2);
	read(f1,n);

	tp := frac(sqrt(n));
	hc := trunc(sqrt(n));
	
	if tp <= 0.5 then kq := hc
	else if tp > 0.5 then kq := hc + 1;

	write(f2,kq*kq);

	close(f1);
	close(f2);

End.



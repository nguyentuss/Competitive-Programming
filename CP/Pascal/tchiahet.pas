var n , i: longint;
	q , k: int64;
	f1 , f2 : text;
Begin

	assign(f1,'tchiahet.inp');reset(f1);
	assign(f2,'tchiahet.out');rewrite(f2);

	readln(f1,n);

	q := 0;
	for i := 1 to n do 
		begin
			readln(f1,k);
			inc(q,k);
			q := q mod n;
		end;
	
	if q mod n = 0 then writeln(f2,'YES')
	else writeln(f2,'NO');
	close(f1);
	close(f2);

End.

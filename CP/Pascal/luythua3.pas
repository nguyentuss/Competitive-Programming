var n , k , s : int64;
	f1 , f2 : text;

Begin

	assign(f1,'luythua3.inp');reset(f1);
	assign(f2,'luythua3.out');rewrite(f2);
	readln(f1,n);

	k := 0; s := 1;
	Repeat
		inc(k);
		s := s*3;
	Until s >= n;

	write(f2,k);

	close(f1);
	close(f2);

End.
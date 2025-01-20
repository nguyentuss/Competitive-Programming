var n , a , b : longint;
	f1 , f2 : text;
Begin

	assign(f1,'dembi.inp');reset(f1);
	assign(f2,'dembi.out');rewrite(f2);
	read(f1,n);

	a := ( n div 5 ) * 3;

	b := ( n div 5 ) * 2;

	if a + b = n then write(f2,a,' ',b)
	else write(f2,-1);

	close(f1);
	close(f2);

End.12
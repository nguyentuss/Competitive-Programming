var 
	m , n , k : longint;
	f1 , f2 : text;
Begin

	assign(f1,'kang.inp');reset(f1);
	assign(f2,'kang.out');rewrite(f2);
	read(f1,m,n,k);

	if (k-n-1>n-m-1) then write(f2,k-n-1)
	else write(f2,n-m-1);

	close(f1);
	close(f2);

End.


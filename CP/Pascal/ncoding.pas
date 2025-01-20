var n , k , i , dem , j , d  : longint;
	st: AnsiString;
	f1 , f2 : text;

Begin

	assign(f1,'ncoding.inp');reset(f1);
	assign(f2,'ncoding.out');rewrite(f2);
	readln(f1,n,k);
	read(f1,st);
	
	k := k mod n; 
	write(f2, copy(st, n - k+1 , k) + copy(st,1,n - k));
	close(f1);
	close(f2);

End.

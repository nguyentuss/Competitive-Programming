var n , k , kq , i : longint;
	A : array[1..10000] of longint;
	f1 , f2 : text;

Begin

	assign(f1,'solap.inp');reset(f1);
	assign(f2,'solap.out');rewrite(f2);
	readln(f1,n);

	fillbyte(a,sizeof(a),0);
	kq := n;
	for i := 1 to n do 
	begin
		read(f1,k);
		a[k] := a[k] + 1;
		if a[k] > 1 then dec(kq);
	end;

	write(f2,kq);

	close(f1);
	close(f2);

End.


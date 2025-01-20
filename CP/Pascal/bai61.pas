var g , s , k , n , i , x , y : longint;
	f1 , f2 : text;

Begin

	assign(f1,'bai61.inp');reset(f1);
	assign(f2,'bai61.out');rewrite(f2);

	readln(f1,g,s,k);

	x := k + s * 29 + g * 29 * 17;

	readln(f1,n);

	for i := 1 to n do 
	begin
		readln(f1,g,s,k);
		y := y + (k + s * 29 + g * 29 * 17);
	end;
	if x < y then write(f2,'-1')
	else 
	begin
		x := x - y ;
		g := x div (17*29);
		s := (x mod (17*29)) div 29;
		k := (x mod (17*29)) mod 29;
		writeln(f2,g,' ',s,' ',k);
	end;

	close(f1);
	close(f2);

End.
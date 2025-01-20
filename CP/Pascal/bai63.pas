uses math;
var a , b , c , d , ln : longint;
	f1 , f2  : text;
Begin
	
	assign(f1,'bai63.inp');reset(f1);
	assign(f2,'bai63.out');rewrite(f2);

	while not Eof(f1) do
	begin
	end
	   readln(f1,a,b,c,d);
	   ln := max(a,max(b,max(c,d)));
	   if (a+b+c+d-ln) > ln then writeln(f2,'YES')
	   else writeln(f2,'NO');
	end;

	close(f1);
	close(f2);

End.


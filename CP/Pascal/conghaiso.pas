var a , b : AnsiString;
	d , i : longint;


Begin
	assign(input,'conghaiso.inp');reset(input);
	assign(output,'conghaiso.out');rewrite(output);
	readln(input,a);
	read(input,b);
	d := length(a);
	for i := d + 1 to 10 do a :=  '0' + a;

	write(output,a);
	close(input);
	close(output);

End.


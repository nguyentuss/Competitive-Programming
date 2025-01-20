var a , b , thue: real;
	f1 , f2 : text;

Begin

	assign(f1,'bl2.inp');reset(f1);
	assign(f2,'bl2.out');rewrite(f2);
	readln(f1,a);
	readln(f1,b);

	thue := 1/125;
	write(f2,(b-a) / (a*thue):0:0);

	close(f1);
	close(f2);

End.
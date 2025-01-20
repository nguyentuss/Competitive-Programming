var p : real;
	f1 , f2 : text;

Begin

	assign(f1,'bl1.inp');reset(f1);
	assign(f2,'bl1.out');rewrite(f2);
	readln(f1,p);

	write(f2,sqr((p / 4)):0:1); 

	close(f1);
	close(f2);

End.
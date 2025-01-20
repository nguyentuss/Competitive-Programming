uses math;
var x , y , z , s , ln : double;
	f1 , f2 : text;

Begin

	assign(f1,'tamgiac.inp');reset(f1);
	assign(f2,'tamgiac.out');rewrite(f2);

	readln(f1,x,y,z);

	ln := max(x,max(y,z));

	s := (x + y + z - ln) - ln ;

	write(f2,s:0:5);

	close(f1);
	close(f2);

End.
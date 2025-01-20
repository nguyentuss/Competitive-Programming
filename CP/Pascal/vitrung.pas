
var n , t , dem : int64;
	f1 , f2 : text;

Begin

	Assign(f1,'vitrung.inp');reset(f1);
	Assign(f2,'vitrung.out');rewrite(f2);

	readln(f1,n,t);

	dem:=0;
	Repeat
		inc(dem);
		n := n * 2;
	Until dem = t;

	write(f2,n);

	close(f1);
	close(f2);

End.

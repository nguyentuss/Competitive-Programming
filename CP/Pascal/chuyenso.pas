var n , tam , max : ansistring;
	i , d , dem , sl , vt: longint;
	kt : boolean;
	f1 , f2 : text;
	a : array[1..300] of ansistring;

Begin

	assign(f1,'chuyenso.inp');reset(f1);
	assign(f2,'chuyenso.out');rewrite(f2);
	read(f1,n);


	dem := 0; kt := false; max := '0';
	d := length(n);sl := 0;

	Repeat
		inc(sl);
		inc(dem);
		//			Phan xu li 			//
				tam := n[1];
				for i := 2 to d do
					n[i-1] := n[i];
				n[d]:=tam[1];
				if n > max then 
					begin
					 	max := n;
					 	vt := dem;
					 end 
		//								//

	Until sl = d;
	write(f2,vt);
		writeln(f2);
		write(f2,max);
	close(f1);
	close(f2);

End.
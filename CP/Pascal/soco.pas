var n , s , k  : longint;
	f1 , f2 : text;

Begin

	assign(f1,'soco.inp');reset(f1);
	assign(f2,'soco.out');rewrite(f2);

	readln(f1,n);

	repeat
		s := 0;
		while n > 0 do 
		begin
			k := n mod 10;
			s := s + k;
			n := n div 10;
		end;
		n := s;
	until n <= 9;

	write(f2,s);

	close(f1);
	close(f2);

End.
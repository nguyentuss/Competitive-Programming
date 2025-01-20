var f1 , f2  : text;
	n : byte;
	s : int64;
	i : int32;

Begin

	assign(f1,'bai33.inp');reset(f1);
	assign(f2,'bai33.out');rewrite(f2);
	readln(f1,n);

	if n = 1 then write(f2,4)
	else
	begin
		s := 2;
		for i := 2 to n do 
			s := (s * 2) - 1;
		s := s * s;
		write(f2,s); 
	end;
	close(f1);
	close(f2);

End.

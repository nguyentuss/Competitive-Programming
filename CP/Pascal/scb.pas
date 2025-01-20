var n , i : longint;
	s : real;
	kt : boolean;
	A : array[1..1000000] of longint;
	f1 , f2 : text;

Begin

	assign(f1,'scb.inp');reset(f1);
	assign(f2,'scb.out');rewrite(f2);

	s := 0;
	readln(f1,n);
	for i := 1 to n do 
		begin
			read(f1,a[i]);
			s := s + a[i];
		end;

	s := s / 2;kt := false;

	for i := 1 to n do
		begin
		 	if s = a[i] then 
		 		begin
		 			write(f2,a[i]);
		 			break;
		 		end;
		 	if i = n then kt := true;
		 end;
	if kt = true then write(f2,'-1');
	close(f1);
	close(f2);

End.

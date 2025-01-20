var t , u1 , un , s , i , n: longint;
	f1 , f2 : text;

Begin

	assign(f1,'arrt.inp');reset(f1);
	assign(f2,'arrt.out');rewrite(f2);

	readln(f1,t);

	u1 := 1; un := u1 ;
	while s <> t do 
	begin
		n := un - u1 + 1;
		s := ((u1+un) * n) div 2;
		if (s < t) then inc(un);
		if (s > t) then inc(u1);
	end;

	write(f2,u1,' ',un);

	close(f1);
	close(f2);

End.


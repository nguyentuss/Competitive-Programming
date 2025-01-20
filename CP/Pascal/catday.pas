var f1 , f2 : text;
	m , k , s1 , s2 : real;

Begin

	assign(f1,'catday.inp');reset(f1);
	assign(f2,'catday.out');rewrite(f2);
	readln(f1,m,k);

	k := k + 1;

	s1 := m / k ;

	if frac(s1) <> 0 then write(f2,'-1')
	else
		begin
			write(f2,s1:0:0,' ',m - s1:0:0);
		end;
	close(f1);
	close(f2);

End.
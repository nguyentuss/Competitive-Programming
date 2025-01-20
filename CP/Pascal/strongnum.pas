uses math;

var n , i , j , a , dem : longint;
	s , nhan , tam : int64;
	f1 , f2 : text;

Begin

	assign(f1,'strongnum.inp');reset(f1);
	assign(f2,'strongnum.out');rewrite(f2);

	readln(f1,n);

 	dem := 0;
	for i := 1 to n do 
	Begin
		a := i;
		nhan := 1; s := 0; 
		while a <> 0 do 
		begin
			tam := a mod 10;
			a := a div 10;
			for j := 1 to tam do 
				nhan := nhan*j; 
			s := s + nhan;
			nhan := 1;
		end;
		if s = i then inc(dem);
	End;

	write(f2,dem); 
	close(f1);
	close(f2);
End.
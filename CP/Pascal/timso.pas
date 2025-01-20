var m , n , i , k , tong , nhan , tam , s  : longint;
	kt : boolean;
	f1 , f2 : text;

Begin

	assign(f1,'timso.inp');reset(f1);
	assign(f2,'timso.out');rewrite(f2);

	readln(f1,m,n);

	k := m * n; 
	for i := 1 to 10000000 do
	begin
		tam := i;tong := 0; nhan := 1;

		while tam > 0 do 
		begin
			s := tam mod 10;
			tam := tam div 10;
			tong := tong + s;
			nhan := nhan * s;
		end;
		if ( tong = m ) and ( nhan = n ) then 
		begin
			write(f2,i);
			kt := true;
			break;
		end;
	end;

	if kt = false then write(f2,'-1');
	close(f1);
	close(f2);

End.


	

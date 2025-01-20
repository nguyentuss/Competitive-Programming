var st , tam : string;
	d , i , j : longint;
	f1 , f2 : text;

Begin

	assign(f1,'snum.inp');reset(f1);
	assign(f2,'snum.out');rewrite(f2);
	readln(f1,st);

	d := length(st);

	for i := 1 to d - 1  do 
		begin
			for j := i + 1 to d do
			if st[i] < st[j] then
				begin
					tam := st[i];
					st[i] := st[j];
					st[j] := tam[1];

				end;
		end;

	write(f2,st);

	close(f1);
	close(f2);

End.
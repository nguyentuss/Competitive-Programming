var n ,dem : int64;
	i , j : longint;
	kt : boolean;
	f1 , f2 : text;

Begin

	assign(f1,'uocnto.inp');reset(f1);
	assign(f2,'uocnto.out');rewrite(f2);

	read(f1,n);

	dem:=0;
	for i := 1 to n do 
		begin 
			if n mod i = 0 then 
				begin
					kt := true;
					for j := 2 to trunc(sqrt(i)) do 
						if (i mod j = 0) then kt := false;
					if (kt = true) and (i > 1) then 
						begin
							write(f2,i,' ');
							inc(dem);
						end;
				end;
		end;

	if dem = 0 then write(f2,'-1');
	close(f1);
	close(f2);
End.
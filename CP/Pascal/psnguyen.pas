var m , n , tam , dema , demb , dem : int64;
	f1 , f2 : text;

Begin

	assign(f1,'psnguyen.inp');reset(f1);
	assign(f2,'psnguyen.out');rewrite(f2);
	readln(f1,m);
	readln(f1,n);

	if m < n then 
			begin
				tam := m;
				m := n;
				n := tam;
			end;

	dema := 0;dem :=0 ; demb := 0;

	while dema < m - 1 do
	begin
		inc(dema);
		demb := 0;
		while demb < n - 1 do 
		 	begin
		 		inc(demb);
		 		if (m + dema) mod (n + demb) = 0 then 
		 			begin
		 				inc(dem);
		 			end;
		 	end
	end;

	write(f2,dem);
	close(f1);
	close(f2);

End.
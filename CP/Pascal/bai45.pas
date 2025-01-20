var st : AnsiString;
	i , cap , s : longint;

Begin

	assign(input,'bai45.inp');reset(input);
	assign(output,'bai45.out');rewrite(output);
	read(input,st);

	cap := 0 ; s := 0;
	for i := 1 to length(st) do 
	begin
		if st[i] = 'C' then 
			begin
				inc(cap);
				inc(s,cap);
			end
		else if st[i] = 'N' then
			begin
				cap := 0;
			end;
	end;

	write(output,s);
	close(input);
	close(output);

End.
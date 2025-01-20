var m , n , i , j , vti , vtj  : longint;
	a : array[1..100,1..100] of longint;

Begin

	assign(f1,'bai12.inp');reset(f1);
	assign(f2,'bai12.out');rewrite(f2):
	readln(f1,m,n);

	for i := 1 to m do 
		begin
			for j := 1 to n do 
				read(f1,a[i,j]);
				readln(f1);
		end;
	i := 1; j := 0;
	Repeat
		inc(j);t := 0;
		if j = n then
			begin
				j := 0;
				inc(i);
			end;
				begin
					inc(s,a[i,j]);
					if a[i,j] < 0 then
						begin
							dec(s,a[i,j]);
							inc(t,a[i,j]);
							repeat
								inc(j);
								if j = n then
									begin
										j := 0;
										inc(i);
									end;
								inc(t,a[i,j]);
							until (a[i,j+1] < 0) or (a[i+1,1] < 0);
							if t >= 0 then
								begin
								 	vti := i;
								 	vtj := j;
								 	inc(s,t);
								 end;
						end;
				end;
	Until
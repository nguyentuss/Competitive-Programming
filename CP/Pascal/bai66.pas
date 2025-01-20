var n , m : integer;
	tmax , imax ,i , tam , j : longint;
	a : array [1..1000] of longint;
	f1 , f2 : text;

Begin

	assign(f1,'bai66.inp');reset(f1);
	assign(f2,'bai66.out');rewrite(f2);
	readln(f1,n,m);

	for i := 1 to m do read(f1,a[i]);

	for i := 1 to m do 
		for j := i + 1 to m do 
			if a[i] < a[j] then 
				begin
					tam := a[i];
					a[i] := a[j];
					a[j] := tam;
				end;
	
	for i := 1 to m do 
	begin
		if i > n then imax := n 
		else imax := i;
		if imax*a[i] > tmax then tmax:=imax*a[i];
	end;
	write(f2,tmax);

	close(f1);
	close(f2);

End.
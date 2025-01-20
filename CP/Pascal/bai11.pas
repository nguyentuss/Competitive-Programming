var f1 , f2 : text;
	n , j , i , x , dau , cuoi , tam , sl , dau1 , dem , cong , tru : longint;
	a : array[1..50,1..50] of longint;

Begin
	assign(f1,'bai11.inp');reset(f1);
	assign(f2,'bai11.out');rewrite(f2);
	readln(f1,n);

// 	Test 1 	//
	x := 0;
	for i := 1 to n do 
		begin
			if i mod 2 <> 0 then 
				for j := 1 to n do 
					begin
						inc(x);
						a[i,j] := x;
					end
			else 
				for j := n downto 1 do 
					begin
						inc(x);
						a[i,j] := x;
					end;
		end;
	for i := 1 to n do
		begin
			for j := 1 to n do write(f2,a[i,j],' ');
			writeln(f2);
		end;
	writeln(f2);
//	Test 2 //
	x := 0 ;
	for j := n downto 1 do 
		begin
			if j mod 2 <> 0 then 
				for i := n downto 1 do
					begin
				 		inc(x);
				 		a[i,j] := x;
				 	end
			else 
				for i := 1 to n do 
					begin
						inc(x);
						a[i,j] := x;
					end;

		end;

	for i := 1 to n do 
		begin
			for j := 1 to n do 
				write(f2,a[i,j],' ');
			writeln(f2);
		end;

//	Test 3 //
	x := 0; i := 1;	tam := n; dau := 1;dau1:= 0;
	for sl := 1 to (n div 2)+1 do 
		begin
			for j := dau to tam do 
				begin
					inc(x);
					a[i,j] := x;
				end;
			inc(i);
			dau := i ;
			for i := dau to tam do 
				begin
					inc(x);
					a[i,j] := x;
				end;
			dec(tam);
			inc(dau1);
			for j := tam downto dau1 do 
				begin
					inc(x);
					a[i,j] := x;
				end;
			for i := tam downto dau do 
				begin
					inc(x);
					a[i,j] := x;
				end;
		end;

	writeln(f2);
	for i := 1 to n do 
		begin
			for j := 1 to n do
				write(f2,a[i,j],' ');
			writeln(f2);
		end;
writeln(f2);
//	Test 4	//
	x := 1;cong := 1;i := 1; j := 1; a[1,1] := 1;

	for sl := 2 to n do 
		begin
			if sl mod 2 = 0 then 
				begin
					inc(j);
					inc(x);
					a[i,j] := x;
					Repeat
						inc(dem);
						inc(i);dec(j);inc(x);
						a[i,j] := x;
					Until dem = cong;
					dem := 0;
				end
			else
				begin
					inc(i);
					inc(x);
					a[i,j] := x;
					Repeat
						inc(dem);
						inc(j);dec(i);inc(x);
						a[i,j] := x;
					Until dem = cong;
					dem := 0;
				end;
			inc(cong);
		end;
	tru := cong - 1;dem :=0; a[n,n] := n *n;
	for sl := n + 1 to (n*2)-2 do 
		begin
			if sl mod 2 = 0 then 
				begin
					inc(i);
					inc(x);
					a[i,j] := x;
					inc(dem);
					Repeat
						inc(dem);
						inc(i);dec(j);inc(x);
						a[i,j] := x;
					Until dem = tru;
					dem := 0;
				end
			else
				begin
					inc(j);
					inc(x);
					a[i,j] := x;
					inc(dem);
					Repeat
						inc(dem);
						inc(j);dec(i);inc(x);
						a[i,j] := x;
					Until dem = tru;
					dem := 0;
				end;
			dec(tru);
		end;
	for i := 1 to n do 
			begin
				for j := 1 to n do 
					write(f2,a[i,j],' ');
				writeln(f2);
			end;
	close(f1);
	close(f2);

End.
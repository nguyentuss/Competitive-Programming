var i , j , n , tam : longint;
	f1 , f2 : text;
	a : array[1..1000] of longint;

Begin

	assign(f1,'bl3.inp');reset(f1);
	assign(f2,'bl3.out');rewrite(f2);

	readln(f1,n);

	for i := 1 to n do read(f1,a[i]);

	for i := 1 to n-1 do 
		begin 
			for j := i+1 to n do 
				if a[i] < a[j] then
					begin
					 	tam := a[i];
					 	a[i] := a[j];
					 	a[j] := tam;
					 end;

		end;

	write(f2,abs(a[1]-a[n]));

	close(f1);
	close(f2);

End.
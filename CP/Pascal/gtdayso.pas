var ans , amax , i , n : longint;
	a : array[1..1000000] of longint;
	f1 , f2 : text; 	

Begin

	assign(f1,'gtdayso.inp');reset(f1);
	assign(f2,'gtdayso.out');rewrite(f2);

	readln(f1,n);
	for i := 1 to n do read(f1,a[i]);

	ans := a[n] ; 
	amax := a[n] ; 

	for i := n - 1 downto 1 do 
		begin
			if (a[i] > amax) then amax := a[i];
			ans := ans + amax;
		end;
	
	write(f2,ans);
	
	close(f1);
	close(f2);

End.
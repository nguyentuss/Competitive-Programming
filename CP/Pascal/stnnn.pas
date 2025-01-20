var n : integer;
	i , j : longint;
	a,b:array[0..30000] of longint;
	f1 , f2 : text;
	kt : boolean;
Begin

	assign(f1,'stnnn.inp');reset(f1);
	assign(f2,'stnnn.out');rewrite(f2);

	readln(f1,n);
	for i := 1 to n do read(f1,a[i]);

	for i := 0 to n do b[i] := i;

	for i := 0 to n do 
		begin
			kt := false;
			for j := 1 to n do
				begin
				   if b[i] <> a[j] then kt := true
				   else 
				   begin
				   	  kt := false;
				   	  break;
				   end; 
				end;
			if kt = true then begin
								 write(f2,b[i]);
								 break;
							  end;	 
		end;

	close(f1);
	close(f2);

End.
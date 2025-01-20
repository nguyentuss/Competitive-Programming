var n , m , k , i , dem: longint;
	k1 , k2 : array[0..1000000] of longint;
	f1 , f2 : text;
Begin
	assign(f1,'ghepgiay.inp');reset(f1);
	assign(f2,'ghepgiay.out');rewrite(f2);

	readln(f1,m,n);

	fillbyte(k1,sizeof(k1),0);
	fillbyte(k2,sizeof(k2),0);

	for i:= 1 to m do 
	begin
	 	read(f1,k);
	 	k1[k] := k1[k] + 1;
	end;
	readln(f1);
	for i:= 1 to n do 
	begin
		read(f1,k);
		k2[k] := k2[k] + 1;
	end;
	dem := 0;
	for i := 0 to 1000000 do
	begin
		if k1[i] <= k2[i] then dem := dem + k1[i]
		else if k1[i] >=  k2[i] then dem := dem + k2[i];
	end;
	write(f2,dem);
	close(f1);
	close(f2);

End.


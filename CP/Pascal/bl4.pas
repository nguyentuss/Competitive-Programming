var st : string;
	ss : array[1..255] of string;
	f1 , f2 : text;
	i , j , dem , k , d: longint;
	kt : boolean;

Begin

	assign(f1,'bl4.inp');reset(f1);
	assign(f2,'bl4.out');rewrite(f2);
	read(f1,st);

	
	for i:=1 to length(st) do
		begin
			j:=i+1;
			repeat
			if (st[i]=st[j]) or (st[i] = upcase(st[j])) then begin
									delete(st,j,1);
								end
			else j:=j+1;
		until (j>length(st));
	end;
	d := length(st);
	write(f2,d*10);
	close(f1);
	close(f2);

End.
var n : integer;
	kt : boolean;

procedure xuli(n : integer);
var a , b , i : integer;
begin
	if n mod 2 <> 0 then 
		begin
			b := (n div 2) + 1;
			a := n - b;
		end
	else 
		begin
			a := n div 2;
			b := n div 2;
		end;
	Repeat
		kt := true;
		for i := 2 to a do 
				if (a mod i = 0) and (b mod i = 0) then kt := false;
		if kt = true then break;	
		dec(a);
		inc(b);

	Until a = 0;

	write(output,a,'/',b);

end;

Begin

	assign(input,'bai55.inp');reset(input);
	assign(output,'bai55.out');rewrite(output);
	read(input,n);

	xuli(n);

	close(input);
	close(output);

End.
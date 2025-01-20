var n : byte;
	i : integer;
	x : array[1..10] of integer;

procedure nghiem;
var i : integer;
begin
	for i := 1 to n do write(output,x[i]);
	writeln(output);
end;
procedure try ( i : integer);
var j : integer;
begin
	for j := 0 to 1 do 
		begin
			x[i] := j;
			if i = n then nghiem
			else try(i+1);
		end;
end;

Begin
	assign(input,'bai42ql.inp');reset(input);
	assign(output,'bai42ql.out');rewrite(output);

	readln(input,n);

	try(1);

	close(input);
	close(output);

End.
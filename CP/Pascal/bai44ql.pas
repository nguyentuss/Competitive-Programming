var n : byte;
	i : longint;
	x , c: array[1..200] of string;

	f1 , f2 : text;

procedure ghinghiem;
var j , i : longint;
	kt : boolean;
begin
	kt := true;
	for i := 1 to n - 1 do 
		if x[i] = 'B' then 
			begin
				if x[i+1] = 'B' then
				begin
				kt := false;
				break;
				end;
			end;
	if (kt = true) then
		begin
			for i := 1 to n do 	
				write(f2,x[i]);
			writeln(f2);
		end;
end;

procedure try(i : integer);
var j : integer;
begin
	for j := 1 to 2 do 
	begin
		x[i] := c[j];
		if i = n then ghinghiem
		else try(i+1);		
	end;
end;

Begin

	assign(f1,'bai44ql.inp');reset(f1);
	assign(f2,'bai44ql.out');rewrite(f2);
	readln(f1,n);

	c[1] := 'A'; c[2] := 'B';
	try(1);

	close(f1);
	close(f2);

End.
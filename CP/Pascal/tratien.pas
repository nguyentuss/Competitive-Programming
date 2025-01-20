const maxn = 30;
var n , i , d : longint;
	t , x : array[1..maxn] of longint;
	conghiem : boolean;
	f1 , f2 : text;
procedure ghinghiem;
var s , i : longint;
begin
	s := 0;
	for i := 1 to n do s := s + (x[i] * t[i]);
	if s = d then 
	begin
		for i := 1 to n do 
			if x[i] = 1 then write(f2,t[i],' ');
		conghiem := true;
	end;
end;
procedure chontien(i:integer);
var j : longint;
begin
	if conghiem then exit;
	for j := 0 to 1 do 
	begin
		x[i] := j;
		if i = n then ghinghiem
		else chontien(i+1);
	end;
end;
Begin

	assign(f1,'tratien.inp');reset(f1);
	assign(f2,'tratien.out');rewrite(f2);

	readln(f1,n,d);
	for i := 1 to n do read(f1,t[i]);

	conghiem := false;
	chontien(1);

	if not(conghiem) then write(f2,'-1');
	close(f1);
	close(f2);

End.






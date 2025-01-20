	const maxn = 10 ;
var a , x: array[1..10] of longint;
	n , k : byte;
	conghiem:boolean;
	i , s : longint;

//
function dieukien:boolean;
var i , j : integer;
	T : array[1..30] of longint;
begin
	fillbyte(t,sizeof(t),0);
	for i := 1 to n do 
		write(output,x[i] ,' ');
	writeln(output);
	for i := 1 to n do 
		begin
			t[x[i]] := t[x[i]] + a[i];
		end;
	for i := 1 to n do
		write(output,t[i],' ');
	writeln(output);

	for i := 2 to k do 
		if t[i] <> t[i-1] then exit(false);
	exit(true);
end;
//
procedure nghiem;
var i , j : integer;
begin
	if dieukien then 
	begin
		conghiem := true;
		for i := 1 to k do 
		begin
			for j := 1 to n do 
				begin
					if x[j] = i then 
						write(output, a[j],' ');
				end;
			writeln(output);
		end;
	end;
end;
//
procedure try(i : integer);
var j : integer;
begin
	if conghiem then exit;
	for j := 1 to k do 
	begin
		x[i] := j ;
		if i = n then nghiem
		else try(i+1); 
	end;
end;

Begin

	assign(input,'bai45ql.inp');reset(input);
	assign(output,'bai45ql.out');rewrite(output);

	readln(input,n,k);
	conghiem := false;
	for i := 1 to n do 
		begin
			read(input,a[i]);
			s := s + a[i];
		end;
	if s mod k <> 0 then write(output,'-1')
	else try(1);

	close(input);
	close(output);

End.
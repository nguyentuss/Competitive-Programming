var n , i , dem : longint;
	f1 , f2 : text;
	a : array[1..3] of string;
	x : array[1..1000000] of string;
procedure ghinghiem;
var t :boolean;
begin
	t := false;
	for i := 1 to n - 1 do 
		if ((x[i] = 'B') and (x[i+1] = 'C')) or ((x[i]='C') and (x[i+1] = 'B')) then t := true;
	if t = false then inc(dem);
end;
procedure try(i: longint);
var j : longint;
begin
	for j := 1 to 3 do
		begin 
			x[i] := a[j];
			if i = n then ghinghiem
			else try(i+1);
		end;
end;
Begin

	assign(f1,'gxau.inp');reset(f1);
	assign(f2,'gxau.out');rewrite(f2);
	readln(f1,n);
	a[1] := 'A'; a[2] := 'B'; a[3] := 'C';
	dem := 0;
	try(1);
	write(f2,dem);
	close(f1);
	close(f2);

End.
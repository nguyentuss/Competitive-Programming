var f1 , f2 : text;
	i , ans , k , n , j: longint;
	a , b , x : array[1..10000] of longint;

procedure ghinghiem;
var t : integer;
begin
	t := 0;
	for i := 1 to n do 
	inc(t,a[i]*x[i]);
	if t = k then inc(ans);
end;
procedure try(i : integer);
var j : integer;
begin
	for j := 0 to b[i] do 
	begin
		x[i] := j;
		if i = n then ghinghiem
		else try(i+1);
	end;
end;

Begin

	assign(f1,'matm.inp');reset(f1);
	assign(f2,'matm.out');rewrite(f2);

	readln(f1,n,k);

	for i := 1 to n do 
		read(f1,a[i]);
	readln(f1);
	for i := 1 to n do
		read(f1,b[i]);

	try(1);

	write(f2,ans);
	close(f1);
	close(f2);
End. 
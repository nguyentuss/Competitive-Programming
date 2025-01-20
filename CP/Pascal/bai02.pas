const fi = 'bai02.inp';
	  fo = 'bai02.out';
 
var f1,f2:text;
	a,b,c:array [1..10000000] of int64;
	i,j:int32;
	n,x,tam:int64;

Begin
	assign(f1,fi); reset(f1);
	assign(f2,fo); rewrite(f2);
	readln(f1,n);
	x := 0;
	for i := 1 to n do
		read(f1,a[i]);
	for i := 1 to n do
		begin 
			if c[a[i]] = 0 then 
				begin
					inc(x);
					b[x] := a[i];
				end;
			inc(c[a[i]]);
		end;
	for i := 1 to x - 1 do
		for j := i + 1 to x do
			if b[i] < b[j] then
				begin
					tam := b[i];
					b[i] := b[j];
					b[j] := tam;
				end;
	writeln(f2,x);
	for i := 1 to x do
		writeln(f2,b[i],' ',c[b[i]]);
	close(f1);
	close(f2);
End.
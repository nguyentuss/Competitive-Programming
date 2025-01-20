const fi = 'xepsach.inp';
      fo = 'xepsach.out';

var f1,f2:text;
	a:array [1..10000000] of int64;
	n,d,x:int64;
	i:int32;
	k:boolean;

Begin
	assign(f1,fi); reset(f1);
	assign(f2,fo); rewrite(f2);
	d := 1;
	x := 1;
	k := false;
	readln(f1,n);
	for i := 1 to n do
		readln(f1,a[i]);
	for i := n downto 1 do
		begin 
			if a[i] = n then k := true;
			if (a[i] = n - x) and (k = true) then 
				begin
					inc(d);
					inc(x);
				end;
		end;
	write(f2,n - d);
	close(f1);
	close(f2);
End.
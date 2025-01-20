var n , a , b , t , i : longint;
	f1 , f2 : text;

function test(n : longint): boolean;
var i : longint;
	kt : boolean;
begin
	kt := true;
	for i := 2 to round(sqrt(n)) do 
		if n mod i = 0 then kt := false;
			if (kt = true) and (n > 1)  then exit(true)
			else exit(false);
end;

Begin

	assign(f1,'symprime.inp');reset(f1);
	assign(f2,'symprime.out');rewrite(f2);


	readln(f1,t);
	for i := 1 to t do 
		begin
			readln(f1,n);
			a := n + 1; b := n - 1;
			Repeat
				if test(a) = false then inc(a);
			Until test(a) = true;
			Repeat
				if test(b) = false then dec(b);
			Until test(b) = true;
			if n = (a + b) / 2 then writeln(f2,'YES')
			else writeln(f2,'NO');
		end;

	close(f1);
	close(f2);

End.
uses math;
var m , n , minsum , i , x , v : longint;
	a , b : array [1..100000] of longint;
	f1 , f2 : text;

function tim(d,c,x:longint):longint;
begin
	if (c <= d) then exit(d)
	else 
	begin
		m := (d + c) div 2;
		if (x=b[m]) then exit(m)
		else if (x<b[m]) then tim(d,m,x)
			else exit(tim(m,c,x));
	end;

end;

Begin

	assign(f1,'minsum.inp');reset(f1);
	assign(f2,'minsum.out');rewrite(f2);

	readln(f1,m,n);
	for i := 1 to m do read(f1,a[i]);
	readln(f1);
	for i := 1 to n do read(f1,b[i]);

	minsum := 2*1000000000;
	for i := 1 to m do 
	begin
		x := -a[i];
		v := tim(1,n,x);
		if abs(a[i]-b[v]) < minsum then minsum := abs(a[i]+b[v]);
	end;
	write(f2,minsum);

	close(f1);
	close(F2);

End.
var n : longint;
	f1 , f2 : text;

function kt(n : longint):boolean;
var i : longint;
begin
	for i := 2 to round(sqrt(n)) do 
		if (n mod i = 0)  then
			exit(false);
	if (n > 1) then exit(true)
	else exit(false);
end;
Begin

	assign(f1,'sntnn.inp');reset(f1);
	assign(f2,'sntnn.out');rewrite(f2);
	readln(f1,n);

	while kt(n) = false do 
		begin
			inc(n);
		end;
	write(f2,n);

	close(f1);
	close(f2);

End.
uses math;
var a,b:int64;
function ucln(a,b:int64):int64;
	begin
		if a mod b = 0 then exit(b)
		else exit(ucln(b,a mod b)); 
	end;
function ucln1(a,b:int64):int64;
begin
	while (a<>b) do 
		begin
			if a>b then a:=a-b
			else b:=b-a;
		end;
	exit(a);
end;
Begin
	readln(a,b);
	writeln('UCLN 1:',ucln(a,b));
	writeln('UCLN 2:',ucln1(a,b));
	readln;
End.
   
var n , a , s , dem , x ,  y : longint;
	f1 , f2 : text ;
function ucln(a,b:longint):longint;
begin
	if a mod b = 0 then exit(b)
	else exit(ucln(b,a mod b));
end;
Begin

	assign(f1,'denduong.inp');reset(f1);
	assign(f2,'denduong.out');rewrite(f2);
	readln(f1,a,n);
	if ucln(a,n) = 1 then write(f2,n-2)
	else write(f2,(n div ucln(a,n)) - 2);
	close(f1);
	close(f2);
End.


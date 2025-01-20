var a0 : ansistring;
	n , m , i: longint;
	f1 , f2 : text; 

function timchuso(n,m : longint): longint;
var l , i : longint;
begin
	l := length(a0);
	if (m<1) or (m>l*(1 shl n)) then 
	begin
		timchuso:=-1;
		exit;
	end;
	i := (m-1) mod l + 1;
	if ((m-1) div l) mod 2 = 1 then i := l - i + 1 ;
	exit(ord(a0[i])-48);
end;

Begin

	assign(f1,'chuso.inp');reset(f1);
	assign(f2,'chuso.out');rewrite(f2);

	readln(f1,a0);
	readln(f1,n,m);

	write(f2,timchuso(n,m));

	close(f1);
	close(f2);

End.	


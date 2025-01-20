var a , b , uc , hs : int64;
	f1 , f2  : text;
function ucln(a,b:int64):int64;
	begin
		if (a mod b = 0) then exit(b)
		else exit(ucln(b,a mod b)); 
	end;

begin

	assign(f1,'honso.inp');reset(f1);
	assign(f2,'honso.out');rewrite(f2);
	readln(f1,a,b);

	if (b=0) then write(f2,'-1')
	else
	begin
		if a = 0 then uc:=1
		else uc := ucln(a,b);
		a := a div uc;
		b := b div uc;
		if (b = 1) then write(f2,a div b)
		else
			begin
				hs := (a div b);
				a := a - hs*b;
				write(f2,hs,' ',a,' ',b);
			end;
	end;

	close(f1);
	close(f2);

End.
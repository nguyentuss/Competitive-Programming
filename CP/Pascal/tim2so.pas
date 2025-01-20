var a , b , x , y : longint;
	f1 , f2 : text;

Begin
	
	assign(f1,'tim2so.inp');reset(f1);
	assign(f2,'tim2so.out');rewrite(f2);

	readln(f1,a,b);

	if ((a mod 2 = 0) and (b mod 2 <> 0)) or ((a mod 2 <> 0) and (b mod 2 = 0)) then write(f2,'-1')
	else 
	begin
		y := (a - b) div 2;
		x := b + y;
		write(f2,x,' ',y);
	end;

	close(f1);
	close(f2);

End.
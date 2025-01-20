var dem : array[0..9] of longint;
	m , n , i , tam : longint;
	f1 , f2 : text;

Begin

	assign(f1,'ndigit.inp');reset(f1);
	assign(f2,'ndigit.out');rewrite(f2);
	readln(f1,m,n);

	fillchar(dem,sizeof(dem),0);
	if m > n then 
	begin
		tam := m;
		m := n;
		n := tam;
	end;
	for i := m to n do 
		begin
			tam := i;
			if tam = 0 then inc(dem[0]);
			while tam > 0 do 
				begin
					inc(dem[tam mod 10]);
					tam := tam div 10;
				end;
		end;

	for i := 0 to 9 do write(f2,dem[i],' ');

	close(f1);
	close(f2);

End.
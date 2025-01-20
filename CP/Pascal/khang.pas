var nhay : longint;
	m , n , k : byte;
	dem : integer;
	f1 , f2 : text;
Begin

	assign(f1,'khang.inp');reset(f1);
	assign(f2,'khang.out');rewrite(f2);
	read(f1,m,n,k);

	nhay := 0; dem :=0 ;
	while nhay + 1 <> k do
	begin
		nhay := n + 1;
		m := n;
		n := nhay;
		inc(dem);
	end;

	write(f2,dem);

	close(f1);
	close(f2);
	
End.


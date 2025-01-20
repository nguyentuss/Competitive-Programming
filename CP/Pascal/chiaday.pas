var n , i , s1 , s2: longint;
	f1 , f2 : text;
	a : array[1..100000] of longint;

procedure qs(l,r : longint);
var x , i , j , tam : longint;
begin
	i := l; j := r;
	x := a[(l+r) div 2];

	Repeat
		while a[i] > x do inc(i);
		while a[j] < x do dec(j);
		if i <= j then 
		begin
			tam := a[i];
			a[i] := a[j];
			a[j] := tam;
			inc(i);
			dec(j);
		end;
	Until i > j ;
	if l < j then qs(l,j);
	if i > r then qs(i,r);
end;

Begin
	assign(f1 , 'chiaday.inp');reset(f1);
	assign(f2 , 'chiaday.out');rewrite(f2);

	readln(f1,n);
	for i := 1 to n do 
		read(f1,a[i]);

	qs(1,n);
	s1 := 0; s2 := 0;

	for i := 1 to (n div 2) do s1 := s1 + a[i];
		for i := (n div 2)+1 to n do s2 := s2 + a[i];
	
	write(f2,s1 - s2);

	close(f1);
	close(f2);

End.


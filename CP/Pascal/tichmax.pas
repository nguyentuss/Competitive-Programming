
var n : integer;
	i , j , k : longint;
	T1,T2: int64;
	a : array[1..100000] of int64;
	f1 , f2 : text;

procedure quicksort(l,r:int64);
var tam , x , i , j  : longint;
begin
	i := l ; j := r;
	x := a[( l + r ) div 2];
	Repeat
		while a[i] < x do i := i + 1;
		while a[j] > x do j := j - 1;
		if i <= j then 
		begin
			tam:=a[i];
			a[i]:=a[j];
			a[j]:=tam;
			inc(i);
			dec(j);
		end;
	Until i > j;
	if l < j then quicksort(l,j);
	if r > i then quicksort(i,r);
end;
Begin

	assign(f1,'tichmax.inp');reset(f1);
	assign(f2,'tichmax.out');rewrite(f2);

	readln(f1,n);
	for i:=1 to n do read(f1,a[i]);

	quicksort(1,n);
	
	t1 := a[n] * a[n-1] * a[n-2];
	t2 := a[1] * a[2] * a[n];
	if t1 >= t2 then write(f2,t1)
	else write(f2,t2);
	close(f1);
	close(f2);

End.
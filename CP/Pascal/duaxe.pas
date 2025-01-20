var i,l,r,n,ans:longint;
    a:array[1..10000000] of int64;
procedure timlongchao(k:longint);
begin
	if k>n then exit;
	l:=k;
	r:=k;
	while(l-1 >= 1 ) and (A[l] < a[l-1]) do dec(l);
	while (r+1<=n) and (a[r] < a[r+1]) do inc(r);
end;
Begin
	assign(input,'duaxe.inp');reset(input);
	assign(output,'duaxe.out');rewrite(output);
	readln(input,n);
	for i:=1 to n do read(input,a[i]);
	r:=0;
	ans:=0;
	while r < n do 
	begin
		timlongchao(r+1);
		i:=r;
		while a[i] > a[l] do 
		begin
			ans:=ans+a[i]-a[i-1];
			i:=i-1;
		end;
	end;
	write(output,ans);
    close(input);
    close(output);
End.


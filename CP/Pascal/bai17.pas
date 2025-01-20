uses math;

var x,y:array[1..1000] of longint;
	f1,f2:text;
	n,i,j,tam,v,ans:longint;

Begin

	assign(f1,'bai17.inp');reset(f1);
	assign(f2,'bai17.out');rewrite(f2);
	readln(f1,n);
	for i:=1 to n do readln(f1,x[i],y[i]);

	for i:=1 to n - 1 do 
	begin
		for j:=i+1 to n do 
			if y[i] > y[j] then 
			begin
				tam:=y[i];
				y[i]:=y[j];
				y[j]:=tam;
			end;
	end;
	v := (n + 1) div 2;
	ans := 0;
	for i:=1 to n do ans := ans + abs(y[i]-y[v]);
	write(f2,ans);
	close(f1);
	close(f2);
End.

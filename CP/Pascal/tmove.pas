uses math;
var m,n : byte;
	f1 ,f2 : text;
	i , j , x , y , ln , s: longint;
	a,b:array[1..100,1..100] of longint;

Begin

	assign(f1,'tmove.inp');reset(f1);
	assign(f2,'tmove.out');rewrite(f2);

	readln(f1,m,n);

	for i := 1 to m do 
		begin
			for j := 1 to n do
				read(f1,a[i,j]);
			readln(f1);
		end;
	for i := 1 to m do 
		for j := 1 to n do 
			b[i,j] := a[i,j] + max(max(b[i-1,j],b[i-1,j-1]),b[i,j-1]);
	write(f2,b[m,n]);

	close(f1);
	close(f2);

End.
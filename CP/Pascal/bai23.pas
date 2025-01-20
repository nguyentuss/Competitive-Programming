uses math;

var i,j,dem,n:longint;
    a,vt1,vt2:array[1..1000000] of longint;
    f1,f2:text;
Begin

	assign(f1,'bai23.inp');reset(f1);
	assign(f2,'bai23.out');rewrite(f2);
	
	readln(f1,n);
	for i:=1 to n do read(f1,a[i]);

	dem:=0;
	for i:=1 to n - 1 do
		for j:=i+1 to n do 
			if a[i] = a[j] then 
			begin
				inc(dem);
				vt1[dem] := i;
				vt2[dem] := j;
			end;
	writeln(f2,dem);
	for i:=1 to dem do 
		writeln(f2,vt1[i],' ',vt2[i]);
	close(f1);
	close(f2);
End.
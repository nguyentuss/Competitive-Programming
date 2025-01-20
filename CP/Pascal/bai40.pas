uses math;

var n:byte;
	i,j,dem,ln,m,z:int32;
	a:array[1..100] of int64;
	f1,f2:text;

Begin

	assign(f1,'bai40.inp');reset(f1);
	assign(f2,'bai40.out');rewrite(f2);
	readln(f1,n);
	for i:=1 to n do read(f1,a[i]);

	m:=-100000000;ln:=0;dem:=0;
	for i:=1 to n  do m := max(m,a[i]);
	
	for i:=2 to (m div 2) do
	begin
		for j:=1 to n do 
			if a[j] mod i = 0 then 
			begin
				dem:=1;
				for z:=j+1 to n do 
					if a[z] mod i = 0 then inc(dem)
					else break;
			 	if ln < dem then ln := dem;
			 	
			end;
	end;
	write(f2,ln);
	close(f1);
	close(f2);
End.
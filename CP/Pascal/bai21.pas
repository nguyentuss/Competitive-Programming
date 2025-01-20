const fi = 'bai21.inp';
	  fo = 'bai21.out';

var f1,f2:text;
	i:int32;
	k,d,x:int64;
	s:ansistring;

Begin
	assign(f1,fi); reset(f1);
	assign(f2,fo); rewrite(f2);
	readln(f1,s);
	readln(f1,k);
	d := length(s);
	x := 0;
	repeat 
		for i := 1 to d - x - 1 do
			begin 
				if s[i] > s[i + 1] then 
					begin
						delete(s,i,1);
						inc(x);
						break;
					end;
			end;
	until x = k;
	write(f2,s);
	close(f1);
	close(f2);
End.
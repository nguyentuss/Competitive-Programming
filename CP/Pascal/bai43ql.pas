const fi = 'bai43ql.inp';
      fo = 'bai43ql.out';

var f1,f2:text;
	s,x:string;
	c:array [1..100] of boolean;
	n:int32;

procedure chon(i:int32);
var j:int32;
begin
	for j := 1 to n do
		begin
			if c[j] = false then
				begin
					x[i] := s[j];
					c[j] :=true;
					if i = n then writeln(f2,x)
					else chon(i + 1);
					c[j] := false; 
				end;
		end;
end;

Begin 
	assign(f1,fi); reset(f1);
	assign(f2,fo); rewrite(f2);
	readln(f1,s);
	n := length(s);
	x := s;
	chon(1);
	close(f1);
	close(f2);
End.
uses math;

const fi = 'chiaqua.inp';
	  fo = 'chiaqua.out';

var f1, f2: text;
	a, x: array [1..100] of int64;
	i: int32;
	kq, n: int64;

procedure ghinghiem;
var t: array [1..3] of int64;
	i: int32;
begin
	fillbyte(t,sizeof(t),0);
	for i := 1 to n do
		t[x[i]] := t[x[i]] + a[i];
	kq := min(kq, max(t[1], max(t[2], t[3])) - min(t[1], min(t[2], t[3])));
end;

procedure chon(i: int32);
var j: int32;
begin 
	for j := 1 to 3 do
		begin
			x[i] := j;
			if i = n then ghinghiem
			else chon(i + 1);
		end;
end;

Begin
	assign(f1, fi); reset(f1);
	assign(f2, fo); rewrite(f2);
	kq := 10000000000;
	readln(f1, n);
	for i := 1 to n do
		read(f1, a[i]);
	chon(1);
	write(f2,kq);
	close(f1);
	close(f2);
End.
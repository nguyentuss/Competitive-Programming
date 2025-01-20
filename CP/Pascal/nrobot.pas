uses math;

const fi = 'nrobot.inp';
      fo = 'nrobot.out';

var f1, f2: text;
	i: int32;
	n, k, ans, z, c, t: int64;
	x, y: array [1..1000] of int64;

Begin
	assign(f1, fi); reset(f1);
	assign(f2, fo); rewrite(f2);
	readln(f1, n); 
	readln(f1, k);
	ans := 0;
	z := n div 2 + 1;
	for i := 1 to k do
		readln(f1, x[i], y[i]);
	for i := 1 to k do
		begin 
			c := min(abs(x[i] - z), abs(y[i] - z));
			c := c * 15;
			t := max(abs(x[i] - z), abs(y[i] - z)) - min(abs(x[i] - z), abs(y[i] - z));
			t := t * 10;
			ans := ans + c + t;
		end;
	write(f2,ans);
	close(f1);
	close(f2);
End.
uses math;
var n , minx , miny , maxx , maxy , i , xtt , ytt , xpt , ypt , xtd , ytd , xpd , ypd : longint;
	s : real;
	x , y : array[1..10000000] of longint; 
	f1 , f2 : text;

Begin

	assign(f1,'hcn.inp');reset(f1);
	assign(f2,'hcn.out');rewrite(f2);
	readln(f1,n);
	for i := 1 to n do 
		readln(f1,x[i],y[i]);

	minx := x[1]; miny := y[1]; maxx := x[1]; maxy := y[1];
	for i := 2 to n  do 
		begin
			minx:=min(minx,x[i]);
			miny:=min(miny,y[i]);
			maxx:=max(maxx,x[i]);
			maxy:=max(maxy,y[i]);
		end;

	xtt := minx; ytt := maxy;
	xpt := maxx; ypt := maxy;
	xtd := minx; ytd := miny;
	xpd := maxx; ypd := miny;

	S := sqrt(sqr(xtt - xpt) + sqr(ytt - ypt)) * sqrt(sqr(xtt - xtd) + sqr(ytt - ytd));

	writeln(f2,S:0:2);
	writeln(f2,xtt,' ',ytt);
	writeln(f2,xpd,' ',ypd);

	close(f1);
	close(f2);

End.
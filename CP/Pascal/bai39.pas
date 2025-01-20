const fi='bai39.inp';
      fo='bai39.out';
var n,nh,s:int64;
    i:int32;
    A:array[0..100000000] of int64;
	f1,f2:text;
Begin
	assign(f1,fi);reset(f1);
	assign(f2,fo);rewrite(f2);
	readln(f1,n);
	close(f1);
	nh:=1;
	Repeat
	while n>0 do 
		begin
			s:=n mod 10;
   			n:=n div 10;
   			nh:=nh*s;
		end;
		n:=nh;
		inc(i);
		a[i]:=nh;
		nh:=1;
	Until n < 10;
	write(f2,a[i]);
	close(f2);
End.
uses math;
const fi='bai09.inp';
      fo='bai09.out';
var n:byte;
    i,j:longint;
    f1,f2:text;
	a,p:array[1..100000000] of longint;
Begin
	assign(f1,fi);reset(f1);
	assign(f2,fo);rewrite(f2);
	readln(f1,n);
	for i:=1 to n do read(f1,a[i]);
	fillchar(P,sizeof(P),0);
	for i:=2 to n do 
		begin
				for j := i - 1 downto 1 do
					if a[j] > a[i] then inc(p[i]);
		end;
	for i:=1 to n do write(f2,p[i],' ');
	close(f1);
	close(f2);
End.



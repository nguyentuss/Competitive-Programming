var n , a , b , c , k , x : int64;
	f1 , f2 :text;

Function UCLN(a,b:integer):longint;
var r : byte;
  begin
     r:=a mod b;
     if r = 0 then exit(b)
     else exit(ucln(b,r));     
  end; 

begin
	assign(f1,'vongdua.inp');reset(f1);
	assign(f2,'vongdua.out');rewrite(f2);
	readln(f1,n,a,b,c);
	x:=(a*b div ucln(a,b));
	k:=(x*c div ucln(x,c));
	while k >= n do k := k mod n;
	if k = 0 then write(f2,'-1')
	else write(f2,k);
	close(f1);
	close(f2);

End.
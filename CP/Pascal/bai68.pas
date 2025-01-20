const fi='bai68.inp';
	  fo='bai68.out';
var a,b,x,y,i,dem:longint;
    f1,f2:text;
Function daoso(n: longint):longint;
Var s:string;
ch:char; i,l,code:integer;
kq:longint;
begin
	str(n,s);
	For i:=1 to length(s) div 2 do
		Begin
			ch:=s[i];
			s[i]:=s[length(s)-i+1];
			s[length(s)-i+1]:=ch;
		End;
	val(s,kq,code);
	exit(kq);	
end;
function ucln(a,b:longint):longint;
begin
	if (a=0) then exit(b);
	if (b=0) then exit(a);
	if a<b then b:=b-a
	else a:=a-b;
	exit(ucln(a,b));    	
end;
Begin
	dem:=0;
	assign(f1,fi);reset(f1);
	assign(f2,fo);rewrite(f2);
	readln(f1,a,b);
	dem:=0;
	for i:=a to b do
		begin
			x:=daoso(i);
			y:=ucln(i,x);
			if y = 1 then inc(dem);
		end;
	write(f2,dem);
	close(f1);
	close(f2);
End.
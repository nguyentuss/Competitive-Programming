const fi='bai25.inp';
      fo='bai25.out';
var n,q,p,r,dem,i,a,b,c,d:longint;
    f1,f2:text;
function ucln(a,b:longint):longint;
begin
	if (a=0) then exit(b);
	if (b=0) then exit(a);
	if a<b then b:=b-a
	else a:=a-b;
	exit(ucln(a,b));    	
end; 
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
    while not eof(f1) do
    	begin
    	   readln(f1,n,p,q,r);
    	   a := p*q div ucln(p,q);
    	   b := q*r div ucln(q,r);
    	   c := p*r div ucln(p,r);
    	   d := a*r div ucln(a,r);
    	   dem := (n div a) + (n div b) + (n div c) - (n div d)*3;
         writeln(f2,dem);
    	end;   	
   close(f1);
   close(f2);
End. 

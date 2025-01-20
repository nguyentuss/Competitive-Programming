uses math;
const fi='nguyento.inp';
      fo='nguyento.out';
var n,dem,i:longint;
    A:array[0..100000000] of longint;
    f1,f2:text;
function nguyento(n : longint):boolean;
var i:longint;
	begin
		for i:=2 to trunc(sqrt(n)) do
			if n mod i = 0 then exit(false);
	 	exit(n>1);
	end;
Begin  
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   for i:=1 to n do read(f1,a[i]);
   dem:=0;
   for i:=1 to n do 
   		if nguyento(a[i])=true then inc(dem);
    write(f2,dem);
   close(f1);
   close(f2);
End. 



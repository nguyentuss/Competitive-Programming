uses math;
var n , k , d , s1 , s2 , t1 , t2 : int64;
    i : longint;
	f1 , f2 : text;
	a : array[1..100000000] of int64;
procedure qs(l,r:int64);
var i,j : longint;
    x,tam : Int64;
begin
   i:=l; j:=r;
   x:=A[(l+r) div 2];
   Repeat
       while a[i]<x do i:=i+1;
       while a[j]>x do j:=j-1;
       if i<=j then begin
                       tam:=a[i];
                       a[i]:=a[j];
                       a[j]:=tam;
                       i:=i+1;
                       j:=j-1;
                    end;

Until i>j;
    if l<j then qs(l,j);
    if i<r then qs(i,r);
end;
Begin

	assign(f1,'btmax.inp');reset(f1);
	assign(f2,'btmax.out');rewrite(f2);

	readln(f1,n,k);
	for i := 1 to n do read(f1,a[i]);
  t1 := 0 ; t2 := 0; s1 := 0; s2 :=0;
	qs(2,n);
  {for i := 1 to n do write(f2,a[i],' ');}
	for i := 1 to k do 
    inc(s1,a[i]);
  for i := k + 1 to n do 
    inc(s2,a[i]);
  for i := 1 to n - k do 
    inc(t1,a[i]);
  for i := (n - k + 1) to n do 
    inc(t2,a[i]); 
	
  write(f2,max(abs(s1-s2),abs(t1-t2)));


	close(f1);
	close(f2);

End.
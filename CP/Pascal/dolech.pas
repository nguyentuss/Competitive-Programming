var n , k , s , sn , sk , tam , l , i , j : longint;
	a : array[1..100000000] of longint;
	f1 , f2 : text;

procedure sxnhanh(l,r:longint);
var i,j,x,tam:longint;
begin
   i:=l; j:=r;
   x:=A[(l+r) div 2];
   Repeat
       while a[i]>x do i:=i+1;
       while a[j]<x do j:=j-1;
       if i<=j then begin
                       tam:=a[i];
                       a[i]:=a[j];
                       a[j]:=tam;
                       i:=i+1;
                       j:=j-1;
                    end;

Until i>j;
    if l<j then sxnhanh(l,j);
    if i<r then sxnhanh(i,r);

end;

Begin
	assign(f1,'dolech.inp');reset(f1);
	assign(f2,'dolech.out');rewrite(f2);
	readln(f1,n,k);
	for i := 1 to n do read(f1,a[i]);

	sxnhanh(1,n);

  l := n - k; 
  if k > l then 
  begin
	   for i := 1 to k do sk := sk + a[i];
	   for i := k + 1 to n do sn := sn + a[i];
  end
  else if (l >=k) then
  begin
      for i := 1 to l do sk := sk+a[i];
      for i := l + 1 to n do sn := sn + a[i];
  end;

	write(f2,sk-sn);

	close(f1);
	close(f2);

End.


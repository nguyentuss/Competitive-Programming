var n,k,i:integer;
    A:array[1..100] of integer;
    f1 , f2 : text;
procedure sxnhanh(l,r:longint);
var i,j,x,tam:integer;
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
    if l<j then sxnhanh(l,j);
    if i<r then sxnhanh(i,r);
end;
//
Begin
   Randomize;
   assign(f1,'thanhsat.inp');reset(f1);
   assign(f2,'thanhsat.out');rewrite(f2);
   readln(f1,n);
   for i := 1 to n do read(f1,a[i]);

   sxnhanh(1,n);
   for i := 1 to n do write(f2,a[i],' ');
   close(f1);
   close(f2);
End.




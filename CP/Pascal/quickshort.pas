uses crt;
var n,k:integer;
    A:array[1..100] of integer;
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
   clrscr;
   write('Nhap n:');readln(n);
   for k:=1 to n do read(a[k]);
   writeln;
   for k:=1 to n do write(A[k],' ');
   writeln;
   writeln;
   sxnhanh(1,n);
   for k:=1 to n do write(a[k],' ');
   readln;
   readln;
End.




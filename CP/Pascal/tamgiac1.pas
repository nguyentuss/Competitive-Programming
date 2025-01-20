uses math;
const fi='tamgiac.inp';
      fo='tamgiac.out';
var n,i,j,tam:longint;
    kt:boolean;
    A,B:array[1..100000000] of int64;
    f1,f2:text;
procedure sxnhanh(l,r:int64);
var i,j:longint;
    x,tam:int64;
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
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,n);
   kt:=false;
   for i:=1 to n do read(f1,a[i]);
   sxnhanh(1,n);
   {for i:=1 to n do write(f2,a[i],' ');}
   for i:=n downto 3 do
        begin
           if a[i]<(a[i-1]+a[i-2]) then
                begin
                   write(f2,a[i],' ',a[i-1],' ',a[i-2]);
                   kt:=true;
                   break;
                end
        end ;
    if kt = false then write(f2,'-1');
   close(f1);
   close(f2);
End.

const fi = 'mink.inp';
      fo = 'mink.out';

var f1,f2:text;
    a:array [1..100000000] of int64;
    n,k:int64;
    i:int32;

procedure quickshort(l,r:int64);
var i,j,x,tam:int32;
begin
     i:=l; j:=r;
     x:=a[(l+r) div 2];
     Repeat
          while a[i]<x do i:=i+1;
               while a[j]>x do j:=j-1;
               if i<=j then
                    begin
                         tam:=a[i];
                         a[i]:=a[j];
                         a[j]:=tam;
                         inc(i);
                         dec(j);
                    end;
     Until i>j;
     if l<j then quickshort(l,j);
     if i<r then quickshort(i,r);
end;

Begin
    assign(f1,fi); reset(f1);
    assign(f2,fo); rewrite(f2);
    read(f1,n,k);
    for i := 1 to n do
        read(f1,a[i]);
    quickshort(1,n);
    for i := 1 to n do write(f2,a[i],' ');
    write(f2,a[k]);
    close(f1);
    close(f2);
End.
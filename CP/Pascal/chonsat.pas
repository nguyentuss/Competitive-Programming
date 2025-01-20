const fi = 'chonsat.inp';
    fo = 'chonsat.out';

var f1, f2: text;
  a: array [1..100000] of int64;
  i, j: int32;
  n, maxn, maxsl, sl:int64;

procedure quickshort(l,r:int64);
var i,j,x,tam:int32;
begin
     i := l;
     j := r;
     x := a[(l + r) div 2];
     Repeat
          while a[i] < x do inc(i);
               while a[j] > x do dec(j);
               if i <= j then
                    begin
                         tam := a[i];
                         a[i] := a[j];
                         a[j] := tam;
                         inc(i);
                         dec(j);
                    end;
     Until i > j;
     if l < j then quickshort(l,j);
     if i < r then quickshort(i,r);
end;

Begin 
  assign(f1, fi); reset(f1);
  assign(f2, fo); rewrite(f2);
  readln(f1,n);
  for i := 1 to n do
    read(f1,a[i]);
  quickshort(1, n);
  maxsl := 1;
  maxn := a[1];
  sl := 1;
  for i := 2 to n do
    if a[i - 1] = a[i] then 
      begin
        inc(sl);
        if sl >= maxsl then 
          begin
            maxsl := sl;
            maxn := a[i];
          end;
      end
    else sl := 1;
  writeln(f2,maxsl);
  write(f2,maxn);
  close(f1);
  close(f2);
End.
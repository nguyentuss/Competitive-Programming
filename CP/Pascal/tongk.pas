const fi = 'tongk.inp';
      fo = 'tongk.out';

var f1,f2:text;
    a:array [1..100000000] of int64;
    i:int32;
    n,k,max,t:int64;

Begin
    assign(f1,fi); reset(f1);
    assign(f2,fo); rewrite(f2);
    max := 0;
    readln(f1,n,k);
    for i := 1 to n do
        read(f1,a[i]);
    for i := 1 to k do
        max := max + a[i];
    t := max;
    for i := k + 1 to n do
        Begin 
            t := t + a[i];
            t := t - a[i - k];
            if t > max then max := t;
        end;
    write(f2,max);
    close(f1);
    close(f2);
End.

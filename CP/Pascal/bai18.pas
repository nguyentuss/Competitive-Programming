const fi = 'bai18.inp';
      fo = 'bai18.out';

var f1,f2:text;
    a:array [-100..100,-100..100] of int64;
    x1,x2,y1,y2:array [-100..100] of int64;
    n,dt:int64;
    i,j,k:int32;

Begin
    assign(f1,fi); reset(f1);
    assign(f2,fo); rewrite(f2);
    readln(f1,n);
    dt := 0;
    fillbyte(a,sizeof(a),0);
    for i := 1 to n do
        readln(f1,x1[i],y1[i],x2[i],y2[i]);
    for k := 1 to n do
        for i := x1[k] to x2[k] - 1 do
            for j := y1[k] to y2[k] - 1 do
                a[i,j] := 1;
    for i := -100 to 100 do
        for j := -100 to 100 do
            dt := dt + a[i,j];
    write(f2,dt);
    close(f1);
    close(f2);
End.
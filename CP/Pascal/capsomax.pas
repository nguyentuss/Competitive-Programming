uses math;

var f1,f2:text;
    a:array [1..100000000] of int64;
    n,t1,t2,tam:int64;
    i,j:int32;

Begin 
    assign(f1,'capsomax.inp'); reset(f1);
    assign(f2,'capsomax.out'); rewrite(f2);
    readln(f1,n);
    for i := 1 to n do
        read(f1,a[i]);
    for i := 1 to 2 do
        for j := i + 1 to n do
            if a[i] > a[j] then 
                begin 
                    tam := a[i];
                    a[i] := a[j];
                    a[j] :=tam;
                end;
    t1 := a[1] * a[2];
    for i := 1 to 2 do
        for j := i + 1 to n do
            if a[i] < a[j] then 
                begin 
                    tam := a[i];
                    a[i] := a[j];
                    a[j] :=tam;
                end;
    t2 := a[1] * a[2];
    write(f2,max(t1,t2));
    close(f2);
End.
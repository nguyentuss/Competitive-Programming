var f1,f2:text;
    k1,k2:array [0..9] of boolean;
    i:int32;
    m,n:int64;
    kt:boolean;

Begin
    assign(f1,'sogiao.inp'); reset(f1);
    assign(f2,'sogiao.out'); rewrite(f2);
    readln(f1,n,m);
    kt := false;
    fillchar(k1,sizeof(k1),false);
    fillchar(k2,sizeof(k2),false);
    while n > 0 do
        begin 
            k1[n mod 10] := true;
            n := n div 10;
        end;
    while m > 0 do
        begin
            k2[m mod 10] := true;
            m := m div 10;
        end;
    for i := 0 to 9 do
        if (k1[i] = true) and (k2[i] = true) then 
            begin
                write(f2,i,' ');
                kt := true;
            end;
    if kt = false then write(f2,'-1');
    close(f1);
    close(f2);
End.

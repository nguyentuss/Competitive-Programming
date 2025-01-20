var f1,f2:text;
    n,x,k,y:int64;
    i:int32;
    s:char;

Begin
    assign(f1,'robot.inp'); reset(f1);
    assign(f2,'robot.out'); rewrite(f2);
    readln(f1,n);
    x := 0; y := 0;
    for i := 1 to n do
        begin 
            readln(f1,s,k);
            if s = 'E' then x := x + k;
            if s = 'W' then x := x - k;
            if s = 'S' then y := y - k;
            if s = 'N' then y := y + k;
        end;
    write(f2,x,' ',y);
    close(f1);
    close(f2);
End.
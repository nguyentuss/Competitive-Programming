var a : array[0..150] of int64;
    d , k , n , nho , i : longint;
    kt : boolean;
    f1 , f2 : text;
procedure solve(d,k:longint);
var i : longint;
    begin
        a[0] := d;nho:=0;
        for i := 1 to 150 do 
        begin
            a[i] := (a[i-1] * k + nho) mod 10;
            nho := (a[i-1]*k+nho) div 10;
            if (a[i] = d) and (a[i-1] <> 0) and (nho = 0) then 
            begin
                kt := true;
                n := i - 1;
                exit;
            end;
        end;
        n := -1;
    end;
begin

    assign(f1,'bai29.inp');reset(f1);
    assign(f2,'bai29.out');rewrite(f2);
    while not eof(f1) do 
    begin
        kt := false;
        readln(f1,d,k);
        solve(d,k);
        if kt = true then 
            begin
                for i := n downto 1 do write(f2,a[i]);
                write(f2,d);
                writeln(f2);
            end
        else writeln(f2,-1);
    end;

    close(f1);
    close(f2);

End.
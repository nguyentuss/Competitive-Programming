const fi = 'timhaiso.inp';
      fo = 'timhaiso.out';

var f1,f2:text;
    m,n,t:int64;
    a,b:int32;
    kt:boolean;

function ucln(x,y:int64):int64;
begin
    if (x mod y = 0) then exit(y)
    else exit(ucln(y,x mod y));
end;

Begin
    assign(f1,fi); reset(f1);
    assign(f2,fo); rewrite(f2);
    read(f1,m,n);
    t := m * n;
    kt := false;
    for a := 1 to trunc(sqrt(t)) do
        begin
            b := t div a;
            if (ucln(a,b) = m) and (a * b = m * n) and (a*b div (ucln(a,b)) = n) then
                begin
                    kt := true;
                    writeln(f2,a,' ',b);
                end;
        end;
    if kt = false then write(f2,'-1');
    close(f1);
    close(f2);
End.
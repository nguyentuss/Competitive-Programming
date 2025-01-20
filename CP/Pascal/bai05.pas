const oo = 1000000000;
var A,B:array[0..200] of int64;
    n,i,j:longint;
    ans:int64;
Begin
    assign(input,'bai05.inp'); reset(input);
    readln(input,n);    
    a[0]:=0;
    for i:=1 to n do 
        read(input,a[i]);
    close(input);
    for i:=1 to n - 1 do a[n+i] := a[i];
    for i:=1 to 2 * n do b[i] := b[i-1] + a[i];
    ans:=oo;
    for i:=1 to n do
    begin
       for j:=i+1 to i+n-1 do 
          if b[j] - b[i-1] < ans then ans:=b[j] - b[i-1];
    end;
    assign(output,'bai05.out'); rewrite(output);
    write(output,ans);
    close(output);
End.
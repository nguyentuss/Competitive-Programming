 Var
          i,n,j,t,ans:longint;
          f1,f2:text;
          a:array[-1999..1999]of longint;
      const fi='sum.inp';
            fo='sum.out';
Begin
    assign(f1,fi);reset(f1);
    assign(f2,fo);rewrite(f2);
    fillchar(a,sizeof(a),0);
        readln(f1,n);
        for i:=1 to n do begin 
        for j:=1 to n do
          begin
             read(f1,t);
               a[i-j]:=a[i-j]+t;
           end;
         readln(f1);
        end;
        ans:=a[1-n];
        for i:=1-n to n-1 do
         if a[i]>ans then ans:=a[i];
   writeln(f2,ans);
    close(f1);close(f2);  
End.
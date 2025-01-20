        Var
          i,j,n: longint;
          a:array[1..1000000] of real;
          x,s,tg:real;
          f:text;
      const fi='average.inp';
            fo='average.out';
 Procedure Sort(L,R : longint);
        Begin
          X := A[(L+R) Div 2];
          i  := L;
          j := R;
          Repeat
            While (A[i] < X) do Inc(i);
            While (A[j] > X) do Dec(j);
            If i <= j Then
              Begin
                Tg := A[i];
                A[i] := A[j];
                A[j] := Tg;
                Inc(i);
                Dec(j);
              End;
          Until i>j;
          If L < j Then Sort(L,j);
          If i < R Then Sort(i,R);
        End;
      Begin
      assign(f,fi);reset(f);
      readln(f,n);
      s:=0;
      for i:=1 to n do 
        read(f,a[i]);
      close(f);
      assign(f,fo);rewrite(f);
        Sort(1,n);
         for i:=1 to n do s:=s+a[i];
         for i:=2 to n do a[i]:=(a[i]+a[i-1])/2;
         s:=n*a[n]-s;
        write(f,s:0:5);
      close(f);  
      End.
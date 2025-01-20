uses math;

var n,i,j,tam,dem : longint;
 	s : int64;
	a : array[1..100000000] of longint;
	f1,f2:text;

Procedure Sort(L,R : longint);
var tg,x:longint;
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

	assign(f1,'bookstor.inp');reset(f1);
	assign(f2,'bookstor.out');rewrite(f2);

	readln(f1,n);
	for i := 1 to n do readln(f1,a[i]);

	Sort(1,n);
	
	s:=0;dem:=0;

	for i:=n downto 1 do 
	begin
	 	inc(dem);
	 	if dem mod 3 <> 0 then s := s + a[i];
	end;

	write(f2,s);

	close(f1);
	close(f2);

End.
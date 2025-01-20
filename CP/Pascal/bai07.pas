const   maxn = 200;
Var A: array[0..maxn] of longint;
  n,t,k,i,s:longint;
  B:longint;
Function ChiaT(t:longint): boolean;
Var s:longint;
Begin
  S:=0;
  For i:=1 to n do
  Begin
    S:=s+A[i];
    If s=t then s:=0;
  End;
  Exit(s=0);
End;

Begin
  assign(input,'bai07.inp'); reset(input);
  assign(output,'bai07.out'); rewrite(output);
  readln(input,n);
  B:=0;
  for i:=1 to n do
  Begin
    read(input,A[i]);
    B:=B + A[i];
  end;
  close(input);
  for i:=B downto 1 do
  Begin
    if (B mod i =0) then
    Begin
      k:=i;
      t:=B div k;
      if ChiaT(t) then break;
    end;
  end;
  writeln(output,k);
  s:=0;
  for i:=1 to n do
  Begin
    s:=s+A[i];
    if s=t then
    Begin
      write(output, i,' ');
      s:=0;
    end;
  end;
  close(output);
end.
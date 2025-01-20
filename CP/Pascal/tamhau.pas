const fi='tamhau.inp';
    fo='tamhau.out';
var f:text; n:Longint; conghiem:Boolean;
  X:array[1..10] of Longint;
  C,BC,BP:array[-2500..2500] of Boolean;

procedure ghinghiem;
var z:Longint;
begin
  conghiem:=true;
  for z:=1 to N do write(f,x[z],#32); 
  writeln(f);
end;

procedure DatHau(i:Longint);
var j:Longint;
begin
  for j:=1 to N do 
  begin
    if not(C[j]) and not(BC[i-j]) and not(BP[i+j]) then 
    begin
      x[i]:=j; 
      c[j]:=true;
      bc[i-j]:=true;
      bp[i+j]:=true;
      if (i=N) then ghinghiem else DatHau(i+1);
      BP[i+j]:=false;
      BC[i-j]:=false;
      C[j]:=false;
    end;
  end;
end;

begin
  assign(f,fi); reset(f);
  read(f,N); close(f);

  assign(f,fo); rewrite(f);
  conghiem:=false;
  fillbyte(x,sizeof(x),0);
  fillchar(c,sizeof(c),false);
  fillchar(bc,sizeof(bc),false);
  fillchar(bp,sizeof(bp),false);
  DatHau(1);
  if not conghiem then write(f,-1);
  close(f);
end.
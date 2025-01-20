const	fi='CAN2DIA.INP';
		fo='CAN2DIA.OUT';
var C:array[0..3000] of boolean;
	A:array[1..100] of integer;
	n,i,j,k:integer;

procedure Doc;
var f:text;
	i:integer;
begin
	assign(f,fi); reset(f);
	readln(f,n);
	for i:=1 to n do read(f,A[i]);
	close(f);
end;
procedure Ghi;
var f:text;
	i:integer;
begin
	assign(f,fo); rewrite(f);
	for i:=1 to 3000 do 
		if (C[i]) then write(f,i,' ');
	close(f);
end;
begin
	Doc;
	fillchar(C,sizeof(c),false);
	for i:=1 to n do C[A[i]]:=true;
	
	for i:=1 to n-1 do
		for j:=i+1 to n do C[A[i]+A[j]]:=true;
		
	for i:=1 to n-2 do
		for j:=i+1 to n-1 do
			for k:=j+1 to n do C[A[i]+A[j]+A[k]]:=true;
	Ghi;
end.
const maxn = 30;
var A,X: Array[1..maxn] of integer;
	n,i,s,ans:integer;

procedure Nghiem;
var s1,s2,i:integer;
begin
	s2:=0;
	for i:=1 to n do s2:= s2 + (X[i] * A[i]);
	s1 := s - s2;
	if abs(s1-s2) < ans then ans:=abs(s1-s2);
end;

procedure chon(i:integer);
var j:integer;
begin
	for j:=0 to 1 do
	begin
		x[i]:=j;
		if i=n then nghiem
		else chon(i+1);
	end;	
end;
begin
	assign(input,'chiakeo.inp'); reset(input);
	assign(output,'chiakeo.out'); rewrite(output);	
	readln(input, n);
	s:=0;
	for i:=1 to n do 
	begin
		read(input, A[i]);
		s:=s+A[i]
	end;
	ans:=s;
	chon(1);
	write(output,ans);
	close(input);
	close(output);
end.
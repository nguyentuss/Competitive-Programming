var x : array [1..100000000] of longint;
	v : array [1..10000000] of ansistring;
	c : array [1..1000000] of boolean;
	s : string;
	n , i , z: byte;

procedure nghiem;
var xau : string; j : longint;
begin
	xau :='';
	for j := 1 to n do xau := xau + s[x[j]];
	for i := 1 to z do
		if v[j] = xau then exit;
	inc(z);
	v[z] := xau;
end;

procedure try(i : longint);
var j : longint;
begin
	for j := 1 to n do 
	begin
		if not(c[j]) then 
		begin
		 	x[i] := j;
		 	c[j] := true;
		 	if i = n then nghiem
		 	else try(i+1);
		 	c[j] := false;
		end; 
	end;
end;

Begin
	assign(input,'bai49ql.inp');reset(input);
	assign(output,'bai49ql.out');rewrite(output);

	read(input,s);
	fillchar(c,sizeof(c),FALSE);
	z := 0;
	n := length(s);
	try(1);
	for i := 1 to n do writeln(output,v[i]); 
	close(input);
	close(output);

End.

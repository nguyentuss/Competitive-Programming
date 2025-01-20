const
    fi = 'bai46ql.INP';
	fo = 'bai46ql.OUT';
		maxn = 30;
var		S:string[maxn];
        C:array[1..100005] of string[maxn];
		X:Array[1..maxn] of boolean;
		n,m:integer;
        f:text;
procedure Input;
var i:integer;
begin
	assign(f,fi);
	reset(f);
	readln(f,S);
	n:=length(s);
    m:=0;
	close(f);
end;
procedure ghinghiem;
var i:integer;
    st:string[maxn];
begin
	st:='';
	for i:=1 to n do
		if x[i] then st:=st+S[i];
	if st='' then exit;
	for i:=1 to m do
		if st=C[i] then exit;
	m:=m+1;
	C[m]:=st;
	writeln(f,st);
end;
procedure tryby(i:byte);
var j:boolean;
begin
	for j:=false to true do
	begin
		X[i]:=j;
		if (i=n) then ghinghiem
		else tryby(i+1);
	end;
end;
begin
	input;
	assign(f,fo); rewrite(f);
	tryby(1);
    close(f);
end.

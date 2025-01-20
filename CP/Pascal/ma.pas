const
		fi = 'ma.inp';
		fo = 'ma.out';
		maxn = 10;
		dx: array[1..8] of integer =(-2, -1, 1, 2,  2,  1, -1, -2);
		dy: array[1..8] of integer =( 1,  2, 2, 1, -1, -2, -2, -1);
var		x,y,n:integer;
		b:array[1..maxn,1..maxn] of integer;
        conghiem:boolean;
procedure Input;
var f:text;
begin
	assign(f,fi);
    reset(f);
	readln(f,n);
	readln(f,x,y);
	close(f);
end;
procedure Output;
var f:text;
	i,j:integer;
begin
	assign(f,fo);
    rewrite(f);
	if not(conghiem) then write(f,-1)
	else
	begin
		for i:=1 to n do
		begin
			for j:=1 to n do write(f,b[i,j]:4);
			writeln(f);
		end;
	end;
	close(f);
end;
procedure ghingiem;
var f:text;
    i,j:integer;
begin
    if conghiem then exit
    else
    begin
        conghiem:=true;
        output;
    end;
end;
function inside(x,y:integer):boolean;
begin
	inside:= (x>=1) and (x<=n) and (y>=1) and (y<=n);
end;
procedure trygo(i:integer);
var j:integer;
begin
    if conghiem then exit;
    for j:=1 to 8 do
	begin
		if inside(x+dx[j],y+dy[j]) and (b[x+dx[j],y+dy[j]]=0) then
		begin
			x:=x+dx[j]; y:=y+dy[j]; b[x,y]:=i;
			if i=n*n then ghingiem else trygo(i+1);
			b[x,y]:=0; x:=x-dx[j]; y:=y-dy[j];
		end;
	end;
end;
begin
	input;
	fillbyte(b,sizeof(b),0);
    conghiem:=false;
	b[x,y]:=1;
	trygo(2);
end.

const fi='cank.inp';
	  fo='cank.out';
var f:text; n,k,i:Longint; conghiem:Boolean;
	A,X:array[1..20] of Longint;
procedure chonnghiem;
var t1,t2,i:longint;
begin
	t1:=k; t2:=0;
	for i:=1 to n do 
	begin
		if x[i]=1 then t1:=t1+A[i]
		else if x[i]=2 then t2:=t2+A[i];
	end;
	if t1=t2 then conghiem:=true; 
end;

procedure chon(i:Longint);
var j:Longint;
begin
	for j:=1 to 2 do 
	begin
		x[i]:=j;
		if (i=n) then chonnghiem else chon(i+1);
	end;
end;

begin
	assign(f,fi); reset(f);
	read(f,n,k);
	for i:=1 to N do read(f,A[i]);
	close(f);

	assign(f,fo); rewrite(f);
	conghiem:=false;
	fillbyte(x,sizeof(x),0);
	chon(1);
	if conghiem=true then write(f,'YES') else write(f,'NO');
	close(f);
end.
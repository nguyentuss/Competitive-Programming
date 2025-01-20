const fi='bai41QL.inp';
	  fo='bai41QL.out';
var f:text; i,so:Longint; X,S:String; 
	C:array[1..10] of boolean;
	KT:array[1..1000000000] of boolean;
procedure qs(d,c:longint);
var td,tc,k:longint; tam:char;
begin
	td:=d; tc:=c;
	k:=(ord(S[(td+tc) div 2])-48);
	repeat
		while ((ord(S[td])-48)<k) do inc(td);
		while ((ord(S[tc])-48)>k) do dec(tc);
		if td<=tc then
		Begin
			tam:=S[td];
			S[td]:=S[tc];
			S[tc]:=tam;
			inc(td);
			dec(tc);
		end;
	until td>tc;
	if td<c then qs(td,c);
	if d<tc then qs(d,tc);
end;

procedure chon(i:Longint);
var j:Longint;
begin
	for j:=1 to length(S) do 
		if not c[j] then 
		begin 
			X[i]:=S[j];
			C[j]:=true;
			if (i=length(S)) then 
			begin
				val(x,so);
				if (not kt[so]) and (x[1]<>'0') then 
				begin 
					writeln(f,X);
					kt[so]:=true;	
				end;
			end
			else chon(i+1);
			C[j]:=false;			
		end;
end;

begin
	assign(f,fi); reset(f);
	read(f,S); close(f);

	assign(f,fo); rewrite(f);
	fillchar(c,sizeof(c),false);
	fillchar(kt,sizeof(kt),false);
	qs(1,length(S));
	x:=s;
	chon(1);
	close(f);
end.
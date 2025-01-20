var s : string;
	i : longint;
procedure ghinghiem;
var v,i:longint;
begin
if(pos('A',X)>0) and (pos('B',X)>0) and (pos('C',X)>0)
then writeln(f,X);
end;
procedure try(i:longint);
var j:char;
begin
	for j:='A' to 'C' do
		begin
			if j<>s[i-1] then
				begin
					s[i]:=j;
					if i=n then ghinghiem
					else try(i+1);
				end;
		end;
end;
Begin

	s:='';
	for i:=1 to 8 do s:=s+'A';


	readln;

End.
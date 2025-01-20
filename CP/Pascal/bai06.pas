uses math;

var k,n,ans1,ans2,i,s,s1,d:longint;
	f1,f2:text;
	a:array[1..10000000] of boolean;

function next(k:longint):longint;
begin
	inc(k);
	if (k>n) then k:=1;
	if (not a[k]) then exit(k)
	else exit(next(k));
end;
Begin
	assign(f1,'bai06.inp');reset(f1);
	assign(f2,'bai06.out');rewrite(f2);
	readln(f1,n,s,k);
	i:=0;s1:=0;d:=0;
	fillchar(a,sizeof(a),false);
	while (d<n) do 
	begin
		i:=next(i);
		inc(s1);
		if (s1=s) then  
		begin
			inc(d);
			s1:=0;
			a[i]:=true;
		end;
	end;
	ans1:=i; ans2:=k-(ans1-1);
	if (ans2<=0) then ans2:=(ans2+n);
	if (ans2>n) then ans2:=(ans2-n);
	writeln(f2,ans1);
	writeln(f2,ans2);
 	close(f1);
 	close(f2);
End.
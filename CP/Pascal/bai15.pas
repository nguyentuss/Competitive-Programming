var a : array[0..100,0..100] of longint;
	i , j , dem , n , m : longint;
	f1,f2:text;

function kiemtra(i,j : integer):boolean;
var tdong,ttay,tbac,tnam : boolean;
	k : longint;
begin
	//huongdong//
	tdong := true;
	for k := j + 1 to n do
		if a[i,k] > a[i,j] then  
		begin
			tdong := false;
			break;
		end;
	//huongtay//
	ttay := true;
	for k := j - 1 downto 1 do 
		if a[i,k] > a[i,j] then 
		begin
			ttay := false;
			break;
		end;
	//huongnam//
	tnam := true;
	for k := i + 1 to m do 
		if a[k,j] > a[i,j] then 
		begin
			tnam := false;
			break;
		end;
	//huongbac//
	tbac := true;
	for k := i - 1 downto 1 do 
		if a[k,j] > a[i,j] then 
		begin
			tbac := false;
			break;
		end;
	writeln(f2,tdong,' ',ttay,' ',tnam,' ',tbac);
	exit (tbac or tnam or tdong or ttay);

end;

Begin

	assign(f1,'bai15.inp');reset(f1);
	assign(f2,'bai15.out');rewrite(f2);

	readln(f1,m,n);

	for i := 1 to m do 
		begin
			for j := 1 to n do  read(f1,a[i,j]);
			readln(f1);
		end;

	dem := 0 ;
	for i := 1 to m do 
		for j := 1 to n do 
			if kiemtra(i,j) then dem := dem + 1;

	write(f2,dem);
	close(f1);
	close(f2);
End.
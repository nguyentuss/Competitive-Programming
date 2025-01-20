const fi='bai59.inp';
	  fo='bai59.out';
var st,tam,c,st1:ansistring;
	d,i,dai,j:longint;
	kt:boolean;
	f1,f2:text;
Begin
	assign(f1,fi);reset(f1);
	assign(f2,fo);rewrite(f2);
	readln(f1,st);
	d:=length(st);
	dai:=length(st);
	for i:=1 to d-1 do
		begin
			for j:=1 to dai do
				begin
					if st[j] = st[dai] then 
						begin
					 		kt := true;
					 		dec(dai);
					 	end 
					else begin
					    	kt := false;
					    	break;
					 	end; 
				end;
			c:=COPY(st,d,d);
			   DELETE(st,d,d);
			   INSERT(c,st,1);
		end;
	if kt = false then write(f2,'NO')
	else if kt = true then write(f2,'Yes');
    close(f1);
    close(f2);
End.

		 

var n:byte;
	st:ansistring;
	x,y:int64;
	i:int32;
	f1,f2:text;
Begin
   assign(f1,'bai13.inp');reset(f1);
   assign(f2,'bai13.out');rewrite(f2);
   readln(f1,n);
   readln(f1,st);
   x:=0;y:=0;
   for i:=1 to length(st) do 
   	 begin 
   	 	if st[i] = 'B' then dec(y)
   	 	else if st[i] = 'R' then inc(x)
   	 	else if st[i] = 'L' then dec(x)
   	 	else if st[i] = 'G' then inc(y);
   	 end;
   write(f2,x,' ',y);
   close(f1);
   close(f2);
End.
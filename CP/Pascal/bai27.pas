var i:longint;
    m,d,y,s,nam:int64;
    f1,f2:text;
Begin
	assign(f1, 'bai27.inp');reset(f1);
	assign(f2, 'bai27.out');rewrite(f2);
	readln(f1,d,m,y);
    close(f1);
    nam:=y;
    dec(m);dec(y);
    s:=0;
    s:=s+d;
    for i:=1 to y do 
    	if (i mod 400 = 0) 
    	or ((i mod 100 <> 0) and (i mod 4 = 0))then s:=s+366
    	else s:=s+365;
    for i:=1 to m do
    	case i of 
    		1,3,5,7,8,10,12 : s:=s+31;
    		4,6,9,11 : s:=s+30;
    		2 : if ((nam mod 4 = 0) and (nam mod 100 <> 0)) or (nam mod 400 = 0) 
            then s:=s+29 else s:=s+28;
    	end;
    write(f2,s);
    close(f2);
End.    


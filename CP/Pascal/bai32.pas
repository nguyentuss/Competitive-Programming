uses math;

var a,b,c,p,q,r : int64;
    f1,f2 : text;
    x , z: double;
    ln,l1,l2,l3 : array[1..3] of double;

Begin
	assign(f1,'bai32.inp');reset(f1);
	assign(f2,'bai32.out');rewrite(f2);
	readln(f1,a,b,c);
	readln(f1,p,q,r);
    fillchar(ln,sizeof(ln),0);

//  Nếu l1 lấy hết
	l2[1] := (a / p) * q ;
	l3[1] := (a / p) * r ;
    if (l2[1] <= b) and (l3[1] <= c) then ln[1] := a + l2[1] + l3[1];

//  Nếu l2 lấy hết
	l1[2] := (b / q) * p ;
	l3[2] := (b / q) * r ;
    if (l1[2] <= a) and (l3[2] <= c) then ln[2] := b + l1[2] + l3[2];  

//  Nếu l3 lấy hết
	l1[3] := (c / r) * p ;
	l2[3] := (c / r) * q ;
    if (l1[3] <= a) and (l2[3] <= b) then ln[3] := c + l1[3] + l2[3];

    x:=max(ln[1],max(ln[2],ln[3]));
    z := 0;
    if x = ln[1] then 
        write(f2,z:0:6,' ',(b - l2[1]):0:6,' ',(c - l3[1]):0:6)
    else if x = ln[2] then 
        write(f2,(a - l1[2]):0:6,' ',z:0:6,' ',(c - l3[2]):0:6)
    else if x = ln[3] then 
  	    write(f2,(a - l1[3]):0:6,' ',(b - l2[3]):0:6,' ',z:0:6);
    	
    close(f1);
    close(f2);
End.



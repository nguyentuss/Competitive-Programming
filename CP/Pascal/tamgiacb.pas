var f1 , f2 : text;
	xa , ya , xb , yb , xc , yc , xm , ym , sabc , samb , samc , smbc : real;

Begin

	assign(f1,'tamgiacb.inp');reset(f1);
	assign(f2,'tamgiacb.out');rewrite(f2);
	readln(f1,xa,ya);
	readln(f1,xb,yb);
	readln(f1,xc,yc);
	readln(f1,xm,ym);

	sabc := 1/2*abs((xb - xa)*(yc-ya) - (xc-xa)*(yb-ya));
	samb := 1/2*abs((xm - xa)*(yb-ya) - (xb-xa)*(ym-ya));
	samc := 1/2*abs((xm - xa)*(yc-ya) - (xc-xa)*(ym-ya));
	smbc := 1/2*abs((xm - xb)*(yc-yb) - (xc-xb)*(ym-yb));
	if (samb+samc+smbc=sabc) then write(f2,'YES')
	else write(f2,'NO');

	close(f1);
	close(f2);

End.
	


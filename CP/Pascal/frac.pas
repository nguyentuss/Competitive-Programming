var a , b , c: Int64;
	f1 , f2 : text;

Begin

	assign(f1,'frac.inp');reset(f1);
	assign(f2,'frac.out');rewrite(f2);
	read(f1,a,b,c);

	if (a<b) and (b<c) then 
		write(f2,b,' ',c)
	else if (a<c) and (c<b) then 
		write(f2,c,' ',b)
	else if (b<c) and (c<a) then 
		write(f2,c,' ',a)
	else if (b<a) and (a<c) then 
		write(f2,a,' ',c)
	else if (c<b) and (b<a)	then 
		write(f2,b,' ',a)
	else if (c<a) and (a<b) then 
		write(f2,a,' ',b)
	else write(f2,'-1');

	close(f1);
	close(f2);

End.
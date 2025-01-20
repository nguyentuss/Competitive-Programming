var a , b : longint;
	st , st1 : string;
	f1 , f2 : text;


Begin

	assign(f1,'test.inp');reset(f1);
	assign(f2,'test.out');rewrite(f2);
	read(f1,st);

	st1 := 'BBB';
	if st =  st1 then write(f2,1);

	close(f1);
	close(f2);

End.
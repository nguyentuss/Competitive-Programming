uses crt;
var a : array[1..100] of longint;
	n , i : longint;
Begin

	clrscr;
	fillchar(a,sizeof(a),0);
	readln(n);
	for i := 1 to n do write(a[i]);

	readln;
	readln;

End.
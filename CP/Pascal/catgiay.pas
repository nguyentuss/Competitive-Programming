uses math;
var n , m , nn , s : double;
const pi = 3.14159;
Begin
	assign(input,'catgiay.inp');reset(input);
	assign(output,'catgiay.out');rewrite(output);
	readln(input,n,m);

	nn := min(n,m);
	s := pi * sqr(nn/2);

	write(output,s:0:5);

	close(input);
	close(output);

End.
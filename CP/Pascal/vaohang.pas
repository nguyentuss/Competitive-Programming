uses math;
var x,y:array[1..100000000] of longint;
	n,i,j,tam,a,max:longint;
	f1,f2:text;
procedure quickshort1(l,r:int64);
var i,j,tam,b:int32;
begin
     i:=l; j:=r;
     b:=x[(l+r) div 2];
     Repeat
          while x[i]<b do i:=i+1;
               while x[j]>b do j:=j-1;
               if i<=j then
                    begin
                         tam:=x[i];
                         x[i]:=x[j];
                         x[j]:=tam;
                         inc(i);
                         dec(j);
                    end;
     Until i>j;
     if l<j then quickshort1(l,j);
     if i<r then quickshort1(i,r);
end;

procedure quickshort2(l,r:int64);
var i,j,tam,b:int32;
begin
     i:=l; j:=r;
     b:=y[(l+r) div 2];
     Repeat
          while y[i]<b do i:=i+1;
               while y[j]>b do j:=j-1;
               if i<=j then
                    begin
                         tam:=y[i];
                         y[i]:=y[j];
                         y[j]:=tam;
                         inc(i);
                         dec(j);
                    end;
     Until i>j;
     if l<j then quickshort2(l,j);
     if i<r then quickshort2(i,r);
end;
Begin

	assign(f1,'vaohang.inp');reset(f1);
	assign(f2,'vaohang.out');rewrite(f2);

	readln(f1,n);
	for i := 1 to n do read(f1,x[i]);
	readln(f1);
	for i := 1 to n do read(f1,y[i]);

	quickshort1(1,n);
	quickshort2(1,n);
	max:=0;
	for i := 1 to n do 
		if abs(x[i] - y[i]) > max then max:= abs(x[i]-y[i]);

	write(f2,max); 
	close(f1);
	close(f2);
End.
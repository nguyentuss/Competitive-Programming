uses crt;
const maxn=10;
var a: array[1..maxn] of integer;
    n,m: integer;
    sn: longint;
(*==============================*)
procedure init;
var i: integer;
begin
write('Nhap so N=');readln(n);
for i:=1 to n do a[i]:=i;
end;
(*==============================*)
procedure swap( var x,y: integer);
var z: integer;
begin z:=x; x:=y; y:=z;
end;
(*==============================*)
procedure print;
var i: integer;
begin
sn:=sn+1;
for i:=1 to n do write(a[i]);
writeln;
end;
(*==============================*)
procedure hv(k: integer);
var j: integer;
begin
if k=1 then print
else
  for j:=k downto 1 do
  begin
    swap(a[k],a[j]);
    hv(k-1);
    swap(a[k],a[j]);
  end;
end;
(*===============================*)
begin
clrscr;
sn:=0;
init;
hv(n);
if sn<>0 then
writeln('Co tat ca',sn,' hoan vi cua ',n,'  so')
else writeln('Vo nghiem');
readln;
end.

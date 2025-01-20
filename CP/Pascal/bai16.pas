var f:text;
a:array[1..1000] of longint;
n,i,j,tam,tong,dem:longint;
const fi='bai16.inp';
     fo='bai16.out';
begin
   assign(f,fi);reset(f);
 readln(f,n);
 for i:=1 to n do read(f,a[i]);
 close(f);
 assign(f,fo);rewrite(f);
 for i:=1 to n-1 do
   for j:=i+1 to n do
   if a[i]<a[j] then
     begin
         tam:=a[i];
         a[i]:=a[j];
         a[j]:=tam;
     end;
     tong:=0;dem:=0;
 for i:=4 to n do tong:=tong+a[i];
 while a[1]+a[2]+a[3]>=tong do
   begin
     tong:=tong-a[4];
     for i:=2 to n do a[i-1]:=a[i]; n:=n-1;
     dem:=dem+1;
     if n=0 then begin writeln(f,-1);break; end;
    end;   
   if n<>0 then writeln(f,dem); 
   close(f);
 end.
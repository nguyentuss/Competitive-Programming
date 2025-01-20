var  x,n:int64;
t:boolean;
function nt(a:int64):boolean;
var j:longint;
begin
      if  a=1 then exit(false);
      for j:=2 to trunc(sqrt(a)) do 
        if (a mod j=0) then exit(false);
        exit(true); 
end;
procedure try(i:int64);
var j:longint;
begin
     for j:=1 to 9 do
       begin
          if nt(x*10+j) then 
          begin 
              x:=x*10+j;
              if i=n then begin t:=true; writeln(output,x);end
              else try(i+1);
              x:=x div 10;
          end;
       end;
end;   
begin       
 assign(input,'bai40ql.inp');reset(input);
  assign(output,'bai40ql.out');rewrite(output);
  readln(input,n);t:=false;
  try(1);
  if t=false then write(output,-1);
  close(input);close(output);      
end.
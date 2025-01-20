uses math;
const fi='bieuthuc.inp';
      fo='bieuthuc.out';
var a,b,c,t:int64;
    kt:boolean;
    f1,f2:text;
Begin
   assign(f1,fi);reset(f1);
   assign(f2,fo);rewrite(f2);
   readln(f1,a,b,c,t);
   kt:=false;
   if a+b-c=t then 
   		begin
   		   writeln(f2,a,'+',b,'-',c);
   		   kt:=true;
   		end;
    if a-b+c=t then 
   		begin
   		   writeln(f2,a,'-',b,'+',c);
   		   kt:=true;
   		end;
   	if a+b+c=t then 
   		begin
   		   writeln(f2,a,'+',b,'+',c);
   		   kt:=true;
   		end;
   	if a-b-c=t then 
   		begin
   		   writeln(f2,a,'-',b,'-',c);
   		   kt:=true;
   		end;
   	if a*b-c=t then 
   		begin
   		   writeln(f2,a,'*',b,'-',c);
   		   kt:=true;
   		end;
   	 if a-b*c=t then 
   		begin
   		   writeln(f2,a,'-',b,'*',c);
   		   kt:=true;
   		end;
   	 if a/b-c=t then 
   		begin
   		   writeln(f2,a,':',b,'-',c);
   		   kt:=true;
   		end;
   	 if a-b/c=t then 
   		begin
   		   writeln(f2,a,'-',b,':',c);
   		   kt:=true;
   		end;
   	 if a*b/c=t then 
   		begin
   		   writeln(f2,a,'*',b,':',c);
   		   kt:=true;
   		end;
   	 if a/b*c=t then 
   		begin
   		   writeln(f2,a,':',b,'*',c);
   		   kt:=true;
   		end;
   	 if a*b*c=t then 
   		begin
   		   writeln(f2,a,'*',b,'*',c);
   		   kt:=true;
   		end;
   	if a/b/c=t then 
   		begin
   		   write(f2,a,':',b,':',c);
   		   kt:=true;
   		end;
   	if kt = false then write(f2,'-1');
   	close(f1);
   	close(f2);
End.
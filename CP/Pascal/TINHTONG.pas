const fi='tinhtong.inp';
      fo='tinhtong.out';
var   a,b,l,kq,c:ansistring;
      x,y,s,nho,i:longint;
      t,k:boolean;
      f:text;
begin
	assign(f,fi);reset(f);
	     readln(f,a);
	     readln(f,b);
	close(f);     
	assign(f,fo);rewrite(f);
	      nho:=0;kq:='';k:=true;
          if ((a[1]='-') and (b[1]='-')) or ((a[1]<>'-') and (b[1]<>'-')) then
               begin
                  if (a[1]='-') and (b[1]='-') then 
                        begin
                             delete(a,1,1);delete(b,1,1);k:=false;
                        end;
         		  if length(a)>length(b) then while length(b)<>length(a) do b:='0'+b
        		  else while length(b)<>length(a) do a:='0'+a;   
      		      for i:=length(a) downto 1 do
              			begin
                 			 val(a[i],x);val(b[i],y);
                 			 s:=x+y+nho;
                  			 nho:=s div 10;
                 			 str(s mod 10,l);
                 			 kq:=l+kq;
               			end;
               			if nho<>0 then kq:='1'+kq;
               			if k=false then kq:='-'+kq;
               end
          else
               begin
                 {if b>a then begin c:=b;b:=a;a:=c;end;}
                 delete(b,1,1);
                 if length(a)>length(b) then while length(b)<>length(a) do b:='0'+b
        		 else while length(b)<>length(a) do a:='0'+a;
                 if b>a then begin c:=b;b:=a;a:=c;k:=false;end;
        		 for i:=length(a) downto 1 do
              			begin
                 			 val(a[i],x);val(b[i],y);
                 			 x:=x-nho;nho:=0;
                 			 if x<y then begin x:=x+10;nho:=1;end;
                  			 s:=x-y;
                 			 str(s,l);
                 			 kq:=l+kq;
               			end;
               	   if (nho=1) or (kq[1]='0') then delete(kq,1,1);		
                   if k=false then kq:='-'+kq;			
               end; 			
               writeln(f,kq);			
	close(f);
end.
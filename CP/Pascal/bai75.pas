const fi='bai75.inp';
      fo='bai75.out';
var a,b,dem:int64;
    i,j,k:longint;
    m:array[1..1000000] of longint;
    so:array[0..9] of integer;
    f1,f2:text;
Begin
	assign(f1,fi);reset(f1);
	assign(f2,fo);rewrite(f2);
	readln(f1,a,b);
	dem:=0;
	fillchar(so,sizeof(so),0);
	for i:=a to b do 
		begin
		    fillchar(m,sizeof(m),0);
		    k:=i;
			while k > 0 do 
				begin
				    inc(dem);
					m[dem] := k mod 10 ;
					k := k div 10;
					Case m[dem] of
						0 : so[0]:=so[0]+1;
						1 : so[1]:=so[1]+1;
						2 : so[2]:=so[2]+1;
						3 : so[3]:=so[3]+1;
						4 : so[4]:=so[4]+1;
						5 : so[5]:=so[5]+1;
						6 : so[6]:=so[6]+1;
						7 : so[7]:=so[7]+1;
						8 : so[8]:=so[8]+1;
						9 : so[9]:=so[9]+1;
					end;
				end;
					
			dem:=0;
		end;
	writeln(f2,0,' ',so[0]);
	writeln(f2,1,' ',so[1]);
	writeln(f2,2,' ',so[2]);
	writeln(f2,3,' ',so[3]);
	writeln(f2,4,' ',so[4]);
	writeln(f2,5,' ',so[5]);
	writeln(f2,6,' ',so[6]);
	writeln(f2,7,' ',so[7]);
	writeln(f2,8,' ',so[8]);
	writeln(f2,9,' ',so[9]);
	close(f1);
	close(f2);
End.



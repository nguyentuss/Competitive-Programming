const
        nmax=1000000;
var
        SNT:array[0..nmax+1] of boolean;
 
procedure sangnt;
var     i,j:longint;
begin
        fillchar(snt,sizeof(snt),true);
        snt[1]:=false;
        i:=2;
        while i<=trunc(sqrt(nmax)) do
                begin
                        while snt[i]=false do
                                inc(i);
                        for j:=2 to nmax div i do
                                snt[i*j]:=false;
                        inc(i);
                end;
 
        for i:=1 to nmax do
                if snt[i]=true then
                        write(i,' ');
end;
 
begin
        sangnt;
        readln;
end.
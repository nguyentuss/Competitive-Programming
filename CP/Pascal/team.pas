var m, n , k , dem :int64;
    
Begin

   assign(input,'team.inp');reset(input);
   assign(output,'team.out');rewrite(output);

   readln(input, m , n , k );

   dem:=0;  
   while (m+n)>=k do
        begin
           dec(m,2);
           dec(n,1);
           if ((m+n)>=k) and (n>=0) and (m>=0) then inc(dem);
        end;
            
   write(output, dem);
   readln;
End.
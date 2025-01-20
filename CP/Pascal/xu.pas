uses math;

var m : byte;
    ln , ln1 , ln2 , a , b , c , n , k , i: longint;
    f1 , f2 : text;


Begin

   assign(f1,'xu.inp');reset(f1);
   assign(f2,'xu.out');rewrite(f2);

   readln(f1,m);

   for i := 1 to m do 
   begin
      readln(f1,a,b,c,n);
      ln := max(a,max(b,c));

      if ln = a then 
        begin
           ln1 := b;
           ln2 := c; 
        end
      else if ln = b then 
        begin
           ln1 := a;
           ln2 := c; 
        end
      else if ln = c then 
        begin
           ln1 := a;
           ln2 := b;
        end;

      k := n - (ln - ln1) - (ln - ln2);
      ln1 := ln1 + (ln - ln1);
      ln2 := ln2 + (ln - ln2);
      if (k mod 3 = 0) and (k >= 0) then writeln(f2,'YES')
      else writeln(f2,'NO');
   end;

  close(f1);
  close(f2);

End.
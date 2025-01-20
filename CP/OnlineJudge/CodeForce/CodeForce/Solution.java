import java.util.*;

public class Solution {
    
    public int solve(int r , int c) {
        // there are possible fill the array
        // 
        // 0 1 2 3 .. c-1
        // 1 2 3 .. c-1 0
        // 2 3 .. c-1 0 1
        // .
        // .
        // .
        // c-2 c-1 0 1 .. c-3
        // 0 1 2 3 .. c-1
        // if c = 1, the possible answer is 0
        if (c == 1) System.out.println(0); 
        // if r = c-1, we can fill the array as described above, and the answer is c
        // also r > c-1 we can fill like r=c-1 and add more the columns 0 1 2 .. c-1 below
        else if (r > c - 1) System.out.println(c); 
        // if r < c, we fill the array as described above but with only c rows. So the answer is r + 1
        else System.out.println(r + 1); 
        for (int i = 0 ; i < Math.min(c - 1 , r) ; i++) {
            for (int j = 0 ; j < c ; j++) {
                System.out.print((i + j)%c + " ");
            }
            System.out.println();
        }
        if (r > c - 1) {
            // add more the columns 0 1 2 .. m - 1
            for (int i = c - 1 ; i < r ; i++) {
                for (int j = 0 ; j < c ; j++) {
                    System.out.print(j + " ");
                }
                System.out.println();
            }
        }
    }
}
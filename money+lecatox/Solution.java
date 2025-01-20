import java.util.*;
import java.io.*;

public class Solution {
    public int solve(int m, int b) {
        int ans = 0;
        // We have y = -x/m + b
        // Because b <= 10000, we can find all pairs (x, y)
        for (int y = 0; y <= b; y++) {
            int x = -(y - b) * m;
            // Calculate the nice value
            ans = Math.max(ans, (y + 1) * x * (x + 1) / 2 + (x + 1) * y * (y + 1) / 2);
        }
        return ans;
    }
}

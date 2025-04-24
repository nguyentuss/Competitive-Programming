import java.util.*;

public class Main {
    private int[] val, lazy;
    private int N;
    
    public Main(int size) {
        N = size;
        val = new int[N * 4];
        lazy = new int[N * 4];
    }
    
    public void add(int id, int l, int r, int u, int v, int x) {
        if (v < l || r < u) return;
        if (u <= l && r <= v) {
            val[id] += x;
            lazy[id] += x;
            return;
        }
        int mid = (l + r) >> 1;
        if (lazy[id] != 0) {
            val[id * 2] += lazy[id];
            val[id * 2 + 1] += lazy[id];
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
            lazy[id] = 0;
        }
        add(id * 2, l, mid, u, v, x);
        add(id * 2 + 1, mid + 1, r, u, v, x);
        val[id] = Math.min(val[id * 2], val[id * 2 + 1]);
    }
    
    public int getRootVal() {
        return val[1];
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        Main st1 = new Main(n);
        Main st2 = new Main(n);
        
        for (int i = 1; i <= n; i++) {
            int c = sc.nextInt();
            int s = sc.nextInt();
            
            if (s == 1) {
                st1.add(1, 1, n, 1, c, +1);
                st2.add(1, 1, n, 1, c, -1);
            } else {
                st1.add(1, 1, n, 1, c, -1);
                st2.add(1, 1, n, 1, c, +1);
            }
            
            if (st1.getRootVal() >= 0) {
                System.out.println(">");
            } else if (st2.getRootVal() >= 0) {
                System.out.println("<");
            } else {
                System.out.println("?");
            }
        }
        
        sc.close();
    }
}

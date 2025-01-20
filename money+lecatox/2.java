import java.util.BitSet;
import java.util.Scanner;

public class Main {

    private static final int MAX_N = 1005;
    private static final long MOD = 1000000007L; // 998244353
    private static final long INF = 1000000000000000001L;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        BitSet bs = new BitSet(2 * MAX_N);

        bs.set(0); // Initially setting the 0th bit to true

        for (int i = 1; i <= n; i++) {
            int x = sc.nextInt();
            x %= m;
            BitSet shifted = bs.get(0, bs.length()); // Copy of current BitSet
            shifted = shifted.get(0, 2 * MAX_N - x).get(0, 2 * MAX_N); // Shift left by x
            shifted = shifted.get(x, shifted.length()); // Adjust to match size
            bs.or(shifted); // Bitwise OR with the original BitSet
        }

        for (int i = m; i <= 1000; i += m) {
            if (bs.get(i)) {
                System.out.println("YES");
                sc.close();
                return;
            }
        }

        System.out.println("NO");
        sc.close();
    }
}

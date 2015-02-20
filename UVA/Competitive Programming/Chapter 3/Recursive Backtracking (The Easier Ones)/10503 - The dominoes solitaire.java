import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static int n;
    static int m;
    static int[] p1;
    static int[] p2;
    static boolean ok;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            n = cin.nextInt();
            if (n == 0) break;
            m = cin.nextInt();
            cin.nextInt();
            int left = cin.nextInt();
            int right = cin.nextInt();
            cin.nextInt();
            p1 = new int[m];
            p2 = new int[m];
            for (int i = 0; i < m; ++i) {
                p1[i] = cin.nextInt();
                p2[i] = cin.nextInt();
            }
            ok = false;
            doIt(0, 0, left, right);
            System.out.println(ok ? "YES" : "NO");
        }
    }

    private static void doIt(int depth, int mask, int left, int right) {
        if (ok) return;
        if (depth == n - 1) {
            for (int i = 0; i < m; ++i)
                if ((mask & (1 << i)) == 0)
                    ok |= (p1[i] == left && p2[i] == right) || (p2[i] == left && p1[i] == right);
        } else {
            for (int i = 0; i < m; ++i)
                if ((mask & (1 << i)) == 0) {
                    if (p1[i] == left)
                        doIt(depth + 1, mask ^ (1 << i), p2[i], right);
                    if (p2[i] == left)
                        doIt(depth + 1, mask ^ (1 << i), p1[i], right);
                }
        }
    }
}
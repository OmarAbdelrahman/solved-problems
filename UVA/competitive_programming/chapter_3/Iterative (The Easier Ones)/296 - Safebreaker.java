import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static boolean[] v1 = new boolean[4];
    static boolean[] v2 = new boolean[4];

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- != 0) {
            int n = cin.nextInt();
            int[][] guess = new int[n][4];
            int[] n1 = new int[n];
            int[] n2 = new int[n];
            for (int i = 0; i < n; ++i) {
                int curN = cin.nextInt();
                for (int j = 3; j >= 0; --j) {
                    guess[i][j] = curN % 10;
                    curN /= 10;
                }
                String[] part = cin.next().split("/");
                n1[i] = Integer.parseInt(part[0]);
                n2[i] = Integer.parseInt(part[1]);
            }
            int cnt = 0;
            int[] res = new int[4];
            for (int i = 0; i < 10000; ++i) {
                int curN = i;
                int[] N = new int[4];
                for (int j = 3; j >= 0; --j) {
                    N[j] = curN % 10;
                    curN /= 10;
                }
                if (solve(N, guess, n1, n2)) {
                    res = N.clone();
                    ++cnt;
                }
                if (cnt > 1) break;
            }
            if (cnt == 0)
                System.out.println("impossible");
            else if (cnt > 1)
                System.out.println("indeterminate");
            else
                System.out.printf("%d%d%d%d\n", res[0], res[1], res[2], res[3]);
        }
    }

    private static boolean solve(int[] n, int[][] guess, int[] n1, int[] n2) {
        for (int i = 0; i < guess.length; ++i) {
            Arrays.fill(v1, false);
            Arrays.fill(v2, false);
            int nn1 = cntSame(n, guess[i]);
            int nn2 = cntDiff(n, guess[i]);
            if (n1[i] != nn1 || n2[i] != nn2)
                return false;
        }
        return true;
    }

    private static int cntDiff(int[] a, int[] b) {
        int res = 0;
        for (int i = 0; i < a.length; ++i)
            if (!v1[i])
                for (int j = 0; j < b.length; ++j)
                    if (i != j && !v2[j]) {
                        if (a[i] == b[j]) {
                            ++res;
                            v1[i] = v2[j] = true;
                            break;
                        }
                    }
        return res;
    }

    private static int cntSame(int[] a, int[] b) {
        int res = 0;
        for (int i = 0; i < a.length; ++i)
            if (a[i] == b[i]) {
                v1[i] = v2[i] = true;
                ++res;
            }
        return res;
    }
}
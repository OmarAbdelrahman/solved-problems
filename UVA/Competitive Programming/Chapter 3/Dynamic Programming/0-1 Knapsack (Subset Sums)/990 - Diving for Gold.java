import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    static int[] depth;
    static int[] value;
    static int[] T;
    static int[] V;
    static int[] D;
    static int indx;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        for (boolean first = true; cin.hasNext(); first = false) {
            if (!first) System.out.println();
            int time = cin.nextInt();
            int w = cin.nextInt();
            int n = cin.nextInt();
            T = new int[n];
            depth = new int[n];
            value = new int[n];
            for (int i = 0; i < n; ++i) {
                depth[i] = cin.nextInt();
                value[i] = cin.nextInt();
                T[i] = (w * depth[i]) + (2 * w * depth[i]);
            }
            int[][] dp = new int[n + 1][time + 1];
            for (int[] row : dp) Arrays.fill(row, 0);
            for (int indx = 1; indx <= n; ++indx)
                for (int t = 1; t <= time; ++t) {
                    dp[indx][t] = dp[indx - 1][t];
                    if (t - T[indx - 1] >= 0)
                        dp[indx][t] = Math.max(dp[indx][t], value[indx - 1] + dp[indx - 1][t - T[indx - 1]]);
                }
            System.out.println(dp[n][time]);
            indx = 0;
            D = new int[n];
            V = new int[n];
            printSolution(n, time, dp);
            System.out.println(indx);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < indx; ++j)
                    if (D[j] == depth[i] && V[j] == value[i])
                        System.out.printf("%d %d\n", depth[i], value[i]);
        }
    }

    private static void printSolution(int n, int time, int[][] dp) {
        if (n <= 0) return;
        if (dp[n][time] == dp[n - 1][time]) {
            printSolution(n - 1, time, dp);
        } else {
            if (time - T[n - 1] >= 0) {
                D[indx] = depth[n - 1];
                V[indx] = value[n - 1];
                ++indx;
                printSolution(n - 1, time - T[n - 1], dp);
            }
        }
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}
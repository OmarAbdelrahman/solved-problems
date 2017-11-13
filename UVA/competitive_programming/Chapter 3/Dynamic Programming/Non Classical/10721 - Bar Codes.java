import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            int k = cin.nextInt();
            int m = cin.nextInt();
            long[][][] dp = new long[n + 1][k + 1][m + 1];
            for (long[][] row2d : dp) for (long[] row1d : row2d) Arrays.fill(row1d, 0);
            for (int i = 0; i <= m; ++i)
                dp[0][0][i] = 1;
            for (int N = 1; N <= n; ++N)
                for (int K = 1; K <= k; ++K)
                    for (int M = 1; M <= m; ++M)
                        if (N - M >= 0)
                            dp[N][K][m] += dp[N - M][K - 1][m];
            System.out.println(dp[n][k][m]);
        }
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}
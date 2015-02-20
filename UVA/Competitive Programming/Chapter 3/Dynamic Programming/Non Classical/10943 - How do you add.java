import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    final static int MOD = 1000000;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int N = cin.nextInt();
            int K = cin.nextInt();
            if (N == 0 && K == 0)
                break;
            int[][] dp = new int[N + 1][K + 1];
            for (int[] row : dp) Arrays.fill(row, 0);
            dp[N][K] = 1;
            for (int n = N; n >= 0; --n)
                for (int k = K; k >= 0; --k)
                    for (int i = 0; i <= N; ++i)
                        if (n + i <= N && k + 1 <= K) {
                            dp[n][k] += dp[n + i][k + 1];
                            dp[n][k] %= MOD;
                        }
            System.out.println(dp[0][0]);
        }
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}
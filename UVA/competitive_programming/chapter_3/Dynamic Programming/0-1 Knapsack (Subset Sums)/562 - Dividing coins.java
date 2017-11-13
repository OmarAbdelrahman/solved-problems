import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cases = cin.nextInt();
        while (cases-- != 0) {
            int n = cin.nextInt();
            int[] coins = new int[n];
            int sum = 0;
            for (int i = 0; i < coins.length; ++i) {
                coins[i] = cin.nextInt();
                sum += coins[i];
            }
            int[][] dp = new int[n + 1][sum + 1];
            for (int[] row : dp) Arrays.fill(row, 0);
            for (int i = 1; i <= n; ++i)
                for (int s = 1; s <= sum; ++s) {
                    dp[i][s] = dp[i - 1][s];
                    if (s - coins[i - 1] >= 0)
                        dp[i][s] = Math.max(dp[i - 1][s], coins[i - 1] + dp[i - 1][s - coins[i - 1]]);
                }
            int res = Integer.MAX_VALUE;
            for (int i = 0; i <= sum; ++i)
                res = Math.min(res, f(sum, dp[n][i]));
            System.out.println(res);
        }
    }

    private static int f(int sum, int nowSum) {
        return Math.abs((sum - nowSum) - nowSum);
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}
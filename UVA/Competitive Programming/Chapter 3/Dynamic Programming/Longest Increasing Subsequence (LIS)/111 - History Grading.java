import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int[] pos = new int[n];
        for (int i = 0; i < n; ++i)
            pos[i] = cin.nextInt();
        int[] num = new int[n];
        for (int i = 0; i < n; ++i)
            num[pos[i] - 1] = i + 1;
        while (cin.hasNext()) {
            int[] results = new int[n];
            for (int i = 0; i < n; ++i)
                results[cin.nextInt() - 1] = i + 1;
            int[][] dp = new int[n + 1][n + 1];
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= n; ++j) {
                    if (i == 0 || j == 0)
                        dp[i][j] = 0;
                    else if (num[i - 1] == results[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            System.out.println(dp[n][n]);
        }
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}
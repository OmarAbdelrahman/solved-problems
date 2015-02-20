import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    final static int TO = 100;
    static int[] coins = {5, 10, 20, 50, 1 * TO, 2 * TO, 5 * TO, 10 * TO, 20 * TO, 50 * TO, 100 * TO};
    static int n = coins.length;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        long[] dp = new long[30000 + 1];
        dp[0] = 1;
        for (int i = 0; i < n; ++i)
            for (int val = coins[i]; val < dp.length; ++val)
                if (val - coins[i] >= 0)
                    dp[val] += dp[val - coins[i]];
        while (cin.hasNext()) {
            double value = cin.nextDouble();
            int inVal = (int) ((value * 100.0) + 0.5);
            if (inVal == 0) break;
            System.out.printf("%6.2f", value);
            System.out.printf("%17d\n", dp[inVal]);
        }
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            int m = cin.nextInt();
            int t = cin.nextInt();
            int[] dp = new int[t + 1];
            Arrays.fill(dp, -1);
            dp[0] = 0;
            for (int T = 0; T <= t; ++T) {
                if (T - n >= 0 && dp[T - n] != -1)
                    dp[T] = Math.max(dp[T], 1 + dp[T - n]);
                if (T - m >= 0 && dp[T - m] != -1)
                    dp[T] = Math.max(dp[T], 1 + dp[T - m]);
            }
            if (dp[t] != -1)
                System.out.println(dp[t]);
            else {
                for (int T = t;; --T)
                    if (dp[T] != -1) {
                        System.out.println(dp[T] + " " + (t - T));
                        break;
                    }
            }
        }
    }
}
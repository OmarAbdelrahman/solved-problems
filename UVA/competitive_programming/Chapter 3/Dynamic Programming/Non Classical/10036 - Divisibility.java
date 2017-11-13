import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static int[] seq;
    static byte[][] dp;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cases = cin.nextInt();
        while (cases-- != 0) {
            int n = cin.nextInt();
            int k = cin.nextInt();
            seq = new int[n];
            for (int i = 0; i < n; ++i)
                seq[i] = cin.nextInt();
            dp = new byte[n + 1][k + 1];
            for (byte[] row : dp) Arrays.fill(row, (byte) -1);
            System.out.println(solve(0, 0, k) == 1 ? "Divisible" : "Not divisible");
        }
    }

    private static int solve(int indx, int sum, int k) {
        int mod = negMod(sum, k);
        if (indx == seq.length) return mod == 0 ? 1 : 0;
        if (dp[indx][mod] != -1)
            return dp[indx][mod];
        dp[indx][mod] = 0;
        dp[indx][mod] |= solve(indx + 1, sum + seq[indx], k);
        dp[indx][mod] |= solve(indx + 1, sum - seq[indx], k);
        return dp[indx][mod];
    }

    private static int negMod(int sum, int k) {
        return (sum % k + k) % k;
    }
}
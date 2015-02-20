import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    final static int MAX = 10000 + 1;
    static int[] memo;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        memo = new int[MAX];
        Arrays.fill(memo, -1);
        memo[0] = 0;
        for (int i = 1; i * i < MAX; ++i)
            memo[i * i] = 1;
        int cases = cin.nextInt();
        while (cases-- != 0) {
            int n = cin.nextInt();
            System.out.println(solve(n));
        }
    }

    private static int solve(int n) {
        if (n < 0) return Integer.MAX_VALUE - MAX - MAX;
        if (memo[n] != -1)
            return memo[n];
        memo[n] = Integer.MAX_VALUE;
        for (int i = 1; i * i <= n; ++i)
            memo[n] = Math.min(memo[n], 1 + solve(n - (i * i)));
        return memo[n];
    }
}
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    final static int MAX = 32000;
    static int[] seq;
    static byte[][] dp;
    static char[][] path;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cases = cin.nextInt();
        while (cases-- != 0) {
            int n = cin.nextInt();
            seq = new int[n];
            for (int i = 0; i < n; ++i)
                seq[i] = cin.nextInt();
            int target = cin.nextInt();
            dp = new byte[n + 1][(MAX + 1) * 2];
            path = new char[n + 1][dp[0].length];
            for (byte[] row : dp) Arrays.fill(row, (byte) -1);
            for (char[] row : path) Arrays.fill(row, '|');
            if (solve(1, seq[0], target) == 1) {
                System.out.print(seq[0]);
                printSolution(1, seq[0]);
                System.out.println("=" + target);
            } else
                System.out.println("NO EXPRESSION");
        }
    }

    private static void printSolution(int indx, int value) {
        if (indx == seq.length) return;
        switch (path[indx][value + MAX]) {
            case '/':
                System.out.print("/" + seq[indx]);
                printSolution(indx + 1, value / seq[indx]);
                break;
            case '*':
                System.out.print("*" + seq[indx]);
                printSolution(indx + 1, value * seq[indx]);
                break;
            case '+':
                System.out.print("+" + seq[indx]);
                printSolution(indx + 1, value + seq[indx]);
                break;
            case '-':
                System.out.print("-" + seq[indx]);
                printSolution(indx + 1, value - seq[indx]);
                break;
            default: break;
        }
    }

    private static byte solve(int indx, int value, int T) {
        if (indx == seq.length)
            return dp[indx][value + MAX] = (byte) (value == T ? 1 : 0);
        if (dp[indx][value + MAX] != -1)
            return dp[indx][value + MAX];
        dp[indx][value + MAX] = 0;
        if (value % seq[indx] == 0) {
            if (value / seq[indx] >= -MAX && value / seq[indx] <= MAX) {
                dp[indx][value + MAX] |= solve(indx + 1, value / seq[indx], T);
                path[indx][value + MAX] = '/';
            }
        }
        if (dp[indx][value + MAX] == 0 && value * seq[indx] >= -MAX && value * seq[indx] <= MAX) {
            dp[indx][value + MAX] |= solve(indx + 1, value * seq[indx], T);
            path[indx][value + MAX] = '*';
        }
        if (dp[indx][value + MAX] == 0 && value - seq[indx] >= -MAX && value - seq[indx] <= MAX) {
            dp[indx][value + MAX] |= solve(indx + 1, value - seq[indx], T);
            path[indx][value + MAX] = '-';
        }
        if (dp[indx][value + MAX] == 0 && value + seq[indx] >= -MAX && value + seq[indx] <= MAX) {
            dp[indx][value + MAX] |= solve(indx + 1, value + seq[indx], T);
            path[indx][value + MAX] = '+';
        }
        return dp[indx][value + MAX];
    }
}
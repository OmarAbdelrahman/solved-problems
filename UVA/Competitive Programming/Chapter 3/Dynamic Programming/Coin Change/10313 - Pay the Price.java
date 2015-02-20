import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.System.out;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        long[][] dp = new long[303][303];
        for (int i = 0; i < dp[0].length; i++)
            dp[0][i] = 1;
        for (int v = 0; v < dp.length; v++)
            for (int c = 1; c < dp[0].length; c++) {
                dp[v][c] = dp[v][c - 1];
                if (v - c >= 0)
                    dp[v][c] += dp[v - c][c];
            }
        while (cin.hasNext()) {
            String[] input = cin.nextLine().split(" ", -1);
            if (input.length == 1) {
                int v = Integer.parseInt(input[0]);
                out.println(dp[v][v]);
            } else if (input.length == 2) {
                int v = Integer.parseInt(input[0]);
                int s = Integer.parseInt(input[1]);
                out.println(dp[v][Math.min(s, 300)]);
            } else if (input.length == 3) {
                int v = Integer.parseInt(input[0]);
                int s = Integer.parseInt(input[1]);
                int e = Integer.parseInt(input[2]);
                if (s == 0)
                    out.println(dp[v][Math.min(e, 300)]);
                else if (s > 300)
                    out.println(0);
                else
                    out.println(dp[v][Math.min(e, 300)] - dp[v][s - 1]);
            }
        }
    }
}
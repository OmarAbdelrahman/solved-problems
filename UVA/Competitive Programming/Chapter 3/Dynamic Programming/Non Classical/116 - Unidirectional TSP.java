import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.out;

public class Main {
    static int INFINITY = 1 << 30;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            int m = cin.nextInt();
            int[][] cost = new int[n][m];
            for (int i = 0; i < n * m; ++i)
                cost[i / m][i % m] = cin.nextInt();
            int[][] path = new int[n][m];
            int[][] dp = new int[n][m];
            for (int[] a : dp) Arrays.fill(a, INFINITY);
            for (int[] a : path) Arrays.fill(a, -1);
            for (int row = 0; row < n; ++row)
                dp[row][m - 1] = cost[row][m - 1];
            for (int col = m - 2; col >= 0; --col)
                for (int row = 0; row < n; ++row) {
                    int curCost = cost[row][col];
                    for (int dir = -1; dir <= 1; ++dir) {
                        int next = (row + dir + n) % n;
                        if (dp[row][col] >= dp[next][col + 1] + curCost) {
                            if (path[row][col] == -1 || path[row][col] > next || dp[row][col] > dp[next][col + 1] + curCost)
                                path[row][col] = next;
                            dp[row][col] = dp[next][col + 1] + curCost;
                        }
                    }
                }
            int index = 0;
            for (int row = 1; row < n; ++row)
                if (dp[index][0] > dp[row][0])
                    index = row;
            int[] resPath = new int[m];
            int col = 0;
            int row = index;
            while (true) {
                resPath[col] = row + 1;
                if (col + 1 != resPath.length)
                    row = path[row][col++];
                else
                    break;
            }
            for (int i = 0; i < resPath.length; ++i) {
                out.print(resPath[i]);
                if (i + 1 != resPath.length)
                    out.print(" ");
            }
            out.printf("\n%d\n", dp[index][0]);
        }
    }
}
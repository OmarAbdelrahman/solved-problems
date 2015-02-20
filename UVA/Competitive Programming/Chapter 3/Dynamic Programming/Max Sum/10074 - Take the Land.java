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
            if (n == 0 && m == 0)
                break;
            int[][] forest = new int[n][m];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    forest[i][j] = cin.nextInt();
                    if (j > 0) forest[i][j] += forest[i][j - 1];
                    if (i > 0) forest[i][j] += forest[i - 1][j];
                    if (i > 0 && j > 0)
                        forest[i][j] -= forest[i - 1][j - 1];
                }
            int res = 0;
            for (int a = 0; a < n; ++a)
                for (int b = 0; b < m; ++b)
                    for (int c = a; c < n; ++c)
                        for (int d = b; d < m; ++d) {
                            int cur = forest[c][d];
                            if (a > 0) cur -= forest[a - 1][d];
                            if (b > 0) cur -= forest[c][b - 1];
                            if (a > 0 && b > 0)
                                cur += forest[a - 1][b - 1];
                            if (cur == 0)
                                res = Math.max(res, (c - a + 1) * (d - b + 1));
                        }
            System.out.println(res);
        }
    }
}
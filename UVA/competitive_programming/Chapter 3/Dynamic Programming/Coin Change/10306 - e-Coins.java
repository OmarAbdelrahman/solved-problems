import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    final static int INF = Integer.MAX_VALUE - 1000;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cases = cin.nextInt();
        while (cases-- != 0) {
            int m = cin.nextInt();
            int S = cin.nextInt();
            int[] x = new int[m];
            int[] y = new int[m];
            for (int i = 0; i < m; ++i) {
                x[i] = cin.nextInt();
                y[i] = cin.nextInt();
            }
            int[][] ways = new int[S + 1][S + 1];
            for (int[] row : ways) Arrays.fill(row, INF);
            ways[0][0] = 0;
            for (int i = 0; i < m; ++i)
                for (int nx = x[i]; nx <= S; ++nx)
                    for (int ny = y[i]; ny <= S; ++ny)
                        if (nx - x[i] >= 0 && ny - y[i] >= 0)
                            ways[nx][ny] = Math.min(ways[nx][ny], 1 + ways[nx - x[i]][ny - y[i]]);
            int res = INF;
            for (int i = 0; i <= S; ++i)
                for (int j = 0; j <= S; ++j)
                    if (i * i + j * j == S * S)
                        res = Math.min(res, ways[i][j]);
            if (res == INF)
                System.out.println("not possible");
            else
                System.out.println(res);
        }
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}
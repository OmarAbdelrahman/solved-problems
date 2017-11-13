import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static final String validCobbles = "IEHOVA#";
    static int[] path = new int[7];
    static int n;
    static int m;
    static int[] dx = {-1, 0, 0};
    static int[] dy = {0, 1, -1};
    static char[][] grid;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- != 0) {
            n = cin.nextInt();
            m = cin.nextInt();
            cin.nextLine();
            grid = new char[n][m];
            int x = 0;
            int y = 0;
            for (int i = 0; i < n; ++i) {
                grid[i] = cin.nextLine().toCharArray();
                if (i == n - 1) {
                    for (int j = 0; j < m; ++j)
                        if (grid[i][j] == '@') {
                            x = i;
                            y = j;
                        }
                }
            }
            Arrays.fill(path, -1);
            getPath(x, y, 0);
        }
    }

    private static void getPath(int x, int y, int depth) {
        if (depth == 7) {
            System.out.print(path[0] == 0 ? "forth" : path[0] == 1 ? "right" : "left");
            for (int i = 1; i < depth; ++i)
                System.out.print(" " + (path[i] == 0 ? "forth" : path[i] == 1 ? "right" : "left"));
            System.out.println();
            return;
        }
        for (int i = 0; i < 3; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] == validCobbles.charAt(depth)) {
                    path[depth] = i;
                    getPath(nx, ny, depth + 1);
                    path[depth] = -1;
                }
            }
        }
    }
}
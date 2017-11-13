import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int cases = cin.nextInt();
        for (int c = 1; cases-- != 0; ++c) {
            n = cin.nextInt();
            cin.nextLine();
            char[][] grid = new char[n][];
            for (int i = 0; i < n; ++i)
                grid[i] = cin.nextLine().toCharArray();
            boolean[] alpha = new boolean[26];
            Arrays.fill(alpha, false);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (grid[i][j] == '.') {
                        for (char ch = 'A'; ch <= 'Z'; ++ch) {
                            boolean all = false;
                            for (int dx = -1; dx <= 1; ++dx)
                                for (int dy = -1; dy <= 1; ++dy)
                                    if ((dx == 0) ^ (dy == 0)) {
                                        int nx = i + dx;
                                        int ny = j + dy;
                                        if (ok(nx, ny))
                                            all |= grid[nx][ny] == ch;
                                    }
                            if (!all) {
                                grid[i][j] = ch;
                                break;
                            }
                        }
                    }
            System.out.printf("Case %d:\n", c);
            for (char[] row : grid) System.out.println(row);
        }
    }

    private static boolean ok(int nx, int ny) {
        return nx >= 0 && nx < n && ny >= 0 && ny < n;
    }

    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }
}
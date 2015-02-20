import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    final static int MAX = 1025;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        int[][] killed = new int[MAX][MAX];
        while (T-- != 0) {
            for (int[] row : killed) Arrays.fill(row, 0);
            int strength = cin.nextInt();
            int population = cin.nextInt();
            for (int i = 0; i < population; ++i) {
                int x = cin.nextInt();
                int y = cin.nextInt();
                int val = cin.nextInt();
                for (int row = x - strength; row <= x + strength; ++row)
                    for (int col = y - strength; col <= y + strength; ++col)
                        if (row >= 1 && row < MAX && col >= 1 && col < MAX)
                            killed[row][col] += val;
            }
            int x = 1;
            int y = 1;
            int sum = -1;
            for (int row = 1; row < MAX; ++row)
                for (int col = 1; col < MAX; ++col)
                    if (killed[row][col] > sum) {
                        x = row; y = col;
                        sum = killed[row][col];
                    }
            System.out.printf("%d %d %d\n", x, y, sum);
        }
    }
}
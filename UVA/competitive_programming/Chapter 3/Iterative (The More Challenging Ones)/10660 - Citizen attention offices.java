import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        int[][] city = new int[5][5];
        while (T-- != 0) {
            for (int[] row : city) Arrays.fill(row, 0);
            int nonEmpty = cin.nextInt();
            for (int i = 0; i < nonEmpty; ++i)
                city[cin.nextInt()][cin.nextInt()] = cin.nextInt();
            int minDist = Integer.MAX_VALUE;
            int[] koko = new int[5];
            for (int a = 0; a < 25; ++a)
                for (int b = a + 1; b < 25; ++b)
                    for (int c = b + 1; c < 25; ++c)
                        for (int d = c + 1; d < 25; ++d)
                            for (int e = d + 1; e < 25; ++e) {
                                int sum = 0;
                                for (int row = 0; row < 5; ++row)
                                    for (int col = 0; col < 5; ++col) {
                                        int A = distance(row, col, a / 5, a % 5) * city[row][col];
                                        int B = distance(row, col, b / 5, b % 5) * city[row][col];
                                        int C = distance(row, col, c / 5, c % 5) * city[row][col];
                                        int D = distance(row, col, d / 5, d % 5) * city[row][col];
                                        int E = distance(row, col, e / 5, e % 5) * city[row][col];
                                        sum += Math.min(Math.min(A, Math.min(B, C)), Math.min(D, E));
                                    }
                                if (sum < minDist) {
                                    minDist = sum;
                                    koko = new int[]{a, b, c, d, e};
                                }
                            }
            System.out.printf("%d %d %d %d %d\n", koko[0], koko[1], koko[2], koko[3], koko[4]);
        }
    }

    private static int distance(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}
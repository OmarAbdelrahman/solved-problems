import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int N;
    static int Q;
    static int[] number;
    static int d, m;
    static int[][][] dp;

    public static int negMod(int a, int b) {
        return (a % b + b) % b;
    }

    public static int solve(int indx, int taken, int sum) {
        int sumMod = negMod(sum, Main.d);
        if (indx == number.length) {
            if (sumMod == 0 && taken == 0)
                return 1;
            return 0;
        }
        if (dp[indx][taken][sumMod] != -1)
            return dp[indx][taken][sumMod];
        dp[indx][taken][sumMod] = solve(indx + 1, taken, sum);
        if (taken - 1 >= 0)
            dp[indx][taken][sumMod] += solve(indx + 1, taken - 1, sum + number[indx]);
        return dp[indx][taken][sumMod];
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        for (int set = 1;; ++set) {
            N = cin.nextInt();
            Q = cin.nextInt();
            if (N == 0 && Q == 0)
                break;
            number = new int[N];
            for (int i = 0; i < N; ++i)
                number[i] = cin.nextInt();
            System.out.printf("SET %d:\n", set);
            dp = new int[N + 1][15][25];
            for (int i = 0; i < Q; ++i) {
                d = cin.nextInt();
                m = cin.nextInt();
                ArrayUtilis.fill(dp, -1);
                System.out.printf("QUERY %d: %d\n", i + 1, solve(0, m, 0));
            }
        }
    }
}

class ArrayUtilis {
    public static void fill(int[] array, int val) {
        Arrays.fill(array, val);
    }

    public static void fill(int[][] array, int val) {
        for (int[] row : array) ArrayUtilis.fill(row, val);
    }

    public static void fill(int[][][] array, int val) {
        for (int[][] row2D : array) ArrayUtilis.fill(row2D, val);
    }

    public static void fill(int[][][][] array, int val) {
        for (int[][][] row3D : array) ArrayUtilis.fill(row3D, val);
    }

    public static void fill(int[][][][][] array, int val) {
        for (int[][][][] row4D : array) ArrayUtilis.fill(row4D, val);
    }
}

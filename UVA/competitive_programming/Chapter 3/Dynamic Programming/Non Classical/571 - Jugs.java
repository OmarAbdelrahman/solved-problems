import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.System.out;

public class Main {
    static int[][] memo;
    static int[][] path;
    static String[] result = { "", "empty A", "empty B", "fill A", "fill B", "pour B A", "pour A B" };

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int A = cin.nextInt();
            int B = cin.nextInt();
            int N = cin.nextInt();
            int n = Math.max(Math.max(A, B), N);
            memo = new int[n + 1][n + 1];
            path = new int[n + 1][n + 1];
            for (int[] a : memo) Arrays.fill(a, -1);
            for (int[] a : path) Arrays.fill(a, -1);
            solve(0, 0, A, B, N);
            getResult(0, 0, A, B, N);
            out.println("success");
        }
    }

    private static void getResult(int a, int b, int A, int B, int N) {
        if (b == N || path[a][b] >= Integer.MAX_VALUE / 3 || path[a][b] == -1)
            return;
        out.println(result[path[a][b]]);
        switch (path[a][b]) {
            case 1:
                getResult(0, b, A, B, N);
                break;
            case 2:
                getResult(a, 0, A, B, N);
                break;
            case 3:
                getResult(A, b, A, B, N);
                break;
            case 4:
                getResult(a, B, A, B, N);
                break;
            case 5:
                int pourA = Math.min(b, A - a);
                getResult(a + pourA, b - pourA, A, B, N);
                break;
            case 6:
                int pourB = Math.min(a, B - b);
                getResult(a - pourB, b + pourB, A, B, N);
                break;
            default: break;
        }
    }

    private static int solve(int a, int b, int A, int B, int N) {
        if (b == N)
            return 0;
        if (memo[a][b] != -1)
            return memo[a][b];
        memo[a][b] = Integer.MAX_VALUE / 3;
        int result = solve(0, b, A, B, N);
        if (result + 1 < memo[a][b]) {
            memo[a][b] = result + 1;
            path[a][b] = 1;
        }
        result = solve(a, 0, A, B, N);
        if (result + 1 < memo[a][b]) {
            memo[a][b] = result;
            path[a][b] = 2;
        }
        result = solve(A, b, A, B, N);
        if (result + 1 < memo[a][b]) {
            memo[a][b] = result + 1;
            path[a][b] = 3;
        }
        result = solve(a, B, A, B, N);
        if (result + 1 < memo[a][b]) {
            memo[a][b] = result + 1;
            path[a][b] = 4;
        }
        int pourA = Math.min(b, A - a);
        int pourB = Math.min(a, B - b);
        result = solve(a + pourA, b - pourA, A, B, N);
        if (result + 1 < memo[a][b]) {
            memo[a][b] = result + 1;
            path[a][b] = 5;
        }
        result = solve(a - pourB, b + pourB, A, B, N);
        if (result + 1 < memo[a][b]) {
            memo[a][b] = result + 1;
            path[a][b] = 6;
        }
        return memo[a][b];
    }
}
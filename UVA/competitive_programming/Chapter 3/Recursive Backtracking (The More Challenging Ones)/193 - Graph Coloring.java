import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.System.out;

public class Main {
    final static int BLACK = 2;
    final static int WHITE = 1;
    final static int EMPTY = 0;
    static int max;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- != 0) {
            int nodes = cin.nextInt();
            int edges = cin.nextInt();
            boolean[][] matrix = new boolean[nodes][nodes];
            for (boolean[] a : matrix) Arrays.fill(a, false);
            for (int i = 0; i < edges; i++) {
                int a = cin.nextInt() - 1;
                int b = cin.nextInt() - 1;
                matrix[a][b] = matrix[b][a] = true;
            }
            int[] result = new int[nodes];
            int[] answer = new int[nodes];
            for (int i = 0; i < nodes; i++)
                result[i] = answer[i] = EMPTY;
            max = Integer.MIN_VALUE;
            dfs(0, 0, result, answer, matrix);
            out.println(max);
            for (int i = 0, count = 0; i < answer.length; i++)
                if (answer[i] == BLACK) {
                    if (count == 0)
                        out.print(i + 1);
                    else
                        out.print(" " + (i + 1));
                    ++count;
                }
            out.println();
        }
    }

    private static void dfs(int index, int black, int[] result, int[] answer, boolean[][] matrix) {
        if (index >= matrix.length) {
            if (black > max) {
                for (int i = 0; i < result.length; i++)
                    answer[i] = result[i];
                max = black;
            }
            return;
        }
        boolean ok = true;
        for (int i = 0; i < matrix[index].length; i++)
            if (matrix[index][i])
                if (result[i] == BLACK)
                    ok = false;
        if (ok) {
            result[index] = BLACK;
            dfs(index + 1, black + 1, result, answer, matrix);
            result[index] = EMPTY;
        }
        result[index] = WHITE;
        dfs(index + 1, black, result, answer, matrix);
        result[index] = EMPTY;
    }
}
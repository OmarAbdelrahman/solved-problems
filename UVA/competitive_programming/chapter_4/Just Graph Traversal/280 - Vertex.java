import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    static int[][] matrix;

    public static void dfs(boolean[] vis, int u) {
        for (int i = 0; i < matrix[u].length; ++i) {
            if (!vis[i] && matrix[u][i] == 1) {
                vis[i] = true;
                dfs(vis, i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (true) {
            int nodes = cin.nextInt();
            if (nodes == 0)
                break;
            matrix = new int[nodes][nodes];
            ArrayUtilis.fill(matrix, 0);
            while (true) {
                int from = cin.nextInt();
                if (from == 0)
                    break;
                while (true) {
                    int to = cin.nextInt();
                    if (to == 0)
                        break;
                    matrix[from - 1][to - 1] = 1;
                }
            }
            int n = cin.nextInt();
            List<Integer> res;
            boolean[] vis = new boolean[nodes];
            for (int i = 0; i < n; ++i) {
                ArrayUtilis.fill(vis, false);
                int startNode = cin.nextInt() - 1;
                dfs(vis, startNode);
                int cnt = 0;
                res = new ArrayList<Integer>();
                for (int node = 0; node < matrix[startNode].length; ++node)
                    if (!vis[node]) {
                        ++cnt;
                        res.add(node + 1);
                    }
                System.out.print(cnt);
                for (int node : res) System.out.print(" " + node);
                System.out.println();
            }
        }
    }
}

class ArrayUtilis {
    public static void fill(int[] array, int val) {
        Arrays.fill(array, val);
    }

    public static void fill(int[][] array, int val) {
        for (int[] row : array) fill(row, val);
    }

    public static void fill(int[][][] array, int val) {
        for (int[][] row2D : array) fill(row2D, val);
    }

    public static void fill(int[][][][] array, int val) {
        for (int[][][] row3D : array) fill(row3D, val);
    }

    public static void fill(int[][][][][] array, int val) {
        for (int[][][][] row4D : array) fill(row4D, val);
    }

    public static void fill(boolean[] array, boolean val) {
        Arrays.fill(array, val);
    }

    public static void fill(boolean[][] array, boolean val) {
        for (boolean[] row : array) fill(array, val);
    }
}
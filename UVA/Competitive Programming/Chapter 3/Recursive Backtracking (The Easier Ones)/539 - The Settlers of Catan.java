import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static boolean[][] connected;
    static int koko;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int nodes = cin.nextInt();
            int edges = cin.nextInt();
            if (nodes == 0 && edges == 0)
                break;
            connected = new boolean[nodes][nodes];
            boolean[][] visited = new boolean[nodes][nodes];
            for (int i = 0; i < edges; ++i) {
                int a = cin.nextInt();
                int b = cin.nextInt();
                connected[a][b] = true;
                connected[b][a] = true;
            }
            koko = Integer.MIN_VALUE;
            for (int start = 0; start < nodes; ++start) {
                for (boolean[] row1d : visited) Arrays.fill(row1d, false);
                getLongestPath(start, visited, 0);
            }
            System.out.println(koko);
        }
    }

    private static void getLongestPath(int start, boolean[][] visited, int cost) {
        koko = Math.max(koko, cost);
        for (int i = 0; i < connected[start].length; ++i) {
            if (connected[start][i] && !visited[start][i]) {
                visited[start][i] = true;
                visited[i][start] = true;
                getLongestPath(i, visited, cost + 1);
                visited[start][i] = false;
                visited[i][start] = false;
            }
        }
    }
}
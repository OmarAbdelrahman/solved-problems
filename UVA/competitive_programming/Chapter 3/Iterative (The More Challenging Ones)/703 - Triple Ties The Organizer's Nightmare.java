import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            boolean[][] win = new boolean[n][n];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    win[i][j] = cin.nextInt() == 1;
            List<Triple> res = new ArrayList<Triple>();
            for (int a = 0; a < n; ++a)
                for (int b = a + 1; b < n; ++b)
                    for (int c = b + 1; c < n; ++c) {
                        if (draw(a, b, c, win)) {
                            int[] arr = {a + 1, b + 1, c + 1};
                            Arrays.sort(arr);
                            res.add(new Triple(arr[0], arr[1], arr[2]));
                        } else if (cyclePos(a, b, c, win)) {
                            int[] arr = {a + 1, b + 1, c + 1};
                            Arrays.sort(arr);
                            res.add(new Triple(arr[0], arr[1], arr[2]));
                        } else if (cycleNeg(a, b, c, win)) {
                            int[] arr = {a + 1, b + 1, c + 1};
                            Arrays.sort(arr);
                            res.add(new Triple(arr[2], arr[1], arr[0]));
                        }
                    }
            Collections.sort(res);
            System.out.println(res.size());
            if (res.size() > 0)
                for (Triple triple : res)
                    System.out.println(triple);
        }
    }

    private static boolean cycleNeg(int a, int b, int c, boolean[][] win) {
        return win[a][c] && win[c][b] && win[b][a];
    }

    private static boolean cyclePos(int a, int b, int c, boolean[][] win) {
        return win[a][b] && win[b][c] && win[c][a];
    }

    private static boolean draw(int a, int b, int c, boolean[][] win) {
        return (!win[a][b] && !win[b][a]) && (!win[a][c] && !win[c][a]) && (!win[b][c] && !win[c][b]);
    }

    static class Triple implements Comparable<Triple> {
        int x, y, z;

        Triple(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public String toString() {
            return x + " " + y + " " + z;
        }

        public int compareTo(Triple t) {
            if (this.x != t.x)
                return this.x - t.x;
            if (this.y != t.y)
                return this.y - t.y;
            return this.z - t.z;
        }
    }
}
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static int[] data = new int[5];
    static boolean[] vis = new boolean[5];
    static int[] res = new int[5];
    static boolean ok;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            boolean allZero = true;
            for (int i = 0; i < 5; ++i) {
                data[i] = cin.nextInt();
                allZero &= data[i] == 0;
            }
            if (allZero) break;
            Arrays.fill(vis, false);
            ok = false;
            solve(0);
            System.out.println(ok ? "Possible" : "Impossible");
        }
    }

    private static void solve(int depth) {
        if (depth == 5) {
            ok |= solve(1, res[0]);
        } else for (int i = 0; i < 5; ++i) {
            if (!vis[i]) {
                res[depth] = data[i];
                vis[i] = true;
                solve(depth + 1);
                vis[i] = false;
            }
        }
    }

    private static boolean solve(int index, int value) {
        if (index == 5)
            return value == 23 ? true : false;
        boolean koko = false;
        koko |= solve(index + 1, value + res[index]);
        koko |= solve(index + 1, value - res[index]);
        koko |= solve(index + 1, value * res[index]);
        return koko;
    }
}
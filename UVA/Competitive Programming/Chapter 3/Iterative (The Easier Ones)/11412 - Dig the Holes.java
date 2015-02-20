import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static boolean[] visited = new boolean[6];
    static char[] perm = new char[4];
    static char[] color = new char[] { 'R', 'B', 'G', 'Y', 'O', 'V' };

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = Integer.parseInt(cin.nextLine());
        while (T-- != 0) {
            cin.nextLine();
            char[] g1 = cin.next().toCharArray();
            int r11 = cin.nextInt();
            int r12 = cin.nextInt();
            char[] g2 = cin.next().toCharArray();
            int r21 = cin.nextInt();
            int r22 = cin.nextInt();
            Arrays.fill(visited, false);
            Arrays.fill(perm, '-');
            System.out.println(!solve(0, g1, g2, r11, r12, r21, r22) ? "Cheat" : "Possible");
        }
    }

    private static boolean solve(int depth, char[] g1, char[] g2, int r11, int r12, int r21, int r22) {
        boolean ok = false;
        if (depth == 4) {
            int curR11 = calcSame(g1);
            int curR12 = calcOccur(g1);
            int curR21 = calcSame(g2);
            int curR22 = calcOccur(g2);
            return curR11 == r11 && curR12 == r12 && curR21 == r21 && curR22 == r22;
        } else for (int i = 0; i < color.length; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                perm[depth] = color[i];
                ok |= solve(depth + 1, g1, g2, r11, r12, r21, r22);
                visited[i] = false;
            }
        }
        return ok;
    }

    private static int calcOccur(char[] g1) {
        int res = 0;
        for (int i = 0; i < g1.length; ++i)
            for (int j = 0; j < g1.length; ++j)
                if (i != j) {
                    if (g1[i] == perm[j]) {
                        ++res;
                        break;
                    }
                }
        return res;
    }

    private static int calcSame(char[] g1) {
        int res = 0;
        for (int i = 0; i < g1.length; ++i)
            res += g1[i] == perm[i] ? 1 : 0;
        return res;
    }
}
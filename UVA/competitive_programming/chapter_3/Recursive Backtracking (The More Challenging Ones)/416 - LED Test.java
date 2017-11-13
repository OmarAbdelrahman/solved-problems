import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    final static int MAX = 7;
    static int[] value = new int[]{ 126, 48, 109, 121, 51, 91, 95, 112, 127, 123 };

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            if (n == 0) break;
            int[] seq = new int[n];
            for (int i = 0; i < n; ++i) {
                String row = cin.next();
                for (int j = row.length() - 1; j >= 0; --j)
                    if (row.charAt(j) == 'Y')
                        seq[i] |= (1 << (MAX - j - 1));
            }
            boolean[] burned = new boolean[MAX];
            boolean ok = false;
            for (int start = 9; start >= 0; --start) {
                if (n - 1 > start || ok) break;
                Arrays.fill(burned, false);
                ok |= dfs(0, start, burned, seq);
            }
            System.out.println(ok ? "MATCH" : "MISMATCH");
        }
    }

    private static boolean dfs(int index, int num, boolean[] burned, int[] seq) {
        boolean ok = false;
        if (index == seq.length) {
            return true;
        } else if (validLed(index, num, burned, seq))
            ok |= dfs(index + 1, num - 1, burned, seq);
        return ok;
    }

    private static boolean validLed(int index, int num, boolean[] burned, int[] seq) {
        for (int i = 0; i < MAX; ++i) {
            if (burned[i] && (seq[index] & (1 << i)) != 0)
                return false;
            if ((value[num] & (1 << i)) != (seq[index] & (1 << i))) {
                if ((seq[index] & (1 << i)) != 0)
                    return false;
                else
                    burned[i] = true;
            }
        }
        return true;
    }
}
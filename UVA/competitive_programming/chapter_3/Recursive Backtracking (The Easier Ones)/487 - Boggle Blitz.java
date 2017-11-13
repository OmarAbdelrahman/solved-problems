import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    private static void debug(Object...os) {
        System.out.println(Arrays.deepToString(os));
    }

    static Set<String> res;
    static String[] table;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        res = new TreeSet<String>(new Comparator<String>() {
            public int compare(String s1, String s2) {
                if (s1.length() != s2.length())
                    return s1.length() - s2.length();
                return s1.compareTo(s2);
            }
        });
        int T = Integer.parseInt(cin.nextLine());
        while (T-- != 0) {
            cin.nextLine();
            int n = Integer.parseInt(cin.nextLine());
            table = new String[n];
            for (int i = 0; i < n; ++i)
                table[i] = cin.nextLine();
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    solve(i, j, "");
            for (String koko : res) System.out.println(koko);
            res.clear();
            if (T != 0) System.out.println();
        }
    }

    private static void solve(int x, int y, String now) {
        now += table[x].charAt(y);
        if (now.length() >= 3)
            res.add(now);
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = dx + x;
                int ny = dy + y;
                if (nx >= 0 && nx < table.length && ny >= 0 && ny < table.length)
                    if (table[nx].charAt(ny) > table[x].charAt(y))
                        solve(nx, ny, now);
            }
    }
}